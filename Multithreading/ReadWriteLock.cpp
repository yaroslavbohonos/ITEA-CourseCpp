/* Task in Replit(Compiler) - https://replit.com/@Bgns/Read-Write-Lock-with-Multithreading-or-95#main.cpp

Task: Imagine you have an application where you have multiple readers and a single writer. 
You are asked to design a lock which lets multiple readers read at the same time, 
but only one writer writes at a time. */

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

class RWLock {
public:
    RWLock() : readersCount(0), writerWriting(false) {}

    void acquireReadLock() 
    {
        std::unique_lock<std::mutex> lock(mutex);
        readCondition.wait(lock, [this] { return !writerWriting; });
        ++readersCount;
    }

    void releaseReadLock() 
    {
        std::unique_lock<std::mutex> lock(mutex);
        --readersCount;
        if (readersCount == 0)
            writeCondition.notify_one();
    }

    void acquireWriteLock() 
    {
        std::unique_lock<std::mutex> lock(mutex);
        writeCondition.wait(lock, [this] { return !writerWriting && readersCount == 0; });
        writerWriting = true;
    }

    void releaseWriteLock() 
    {
        std::unique_lock<std::mutex> lock(mutex);
        writerWriting = false;
        writeCondition.notify_one();
        readCondition.notify_all();
    }

private:
    std::condition_variable readCondition;
    std::condition_variable writeCondition;
    std::mutex mutex;
    int readersCount;
    bool writerWriting;
};

RWLock ReadWriteLock;
int sharedData = 0;

void readerThread(int id) 
{
    ReadWriteLock.acquireReadLock();
    std::cout << "Reader " << id << " has read the shared data: " << sharedData << std::endl;
    ReadWriteLock.releaseReadLock();
}

void writerThread(int id, int newData) 
{
    ReadWriteLock.acquireWriteLock();
    sharedData = newData;
    std::cout << "Writer " << id << " has modified the shared data to: " << sharedData << std::endl;
    ReadWriteLock.releaseWriteLock();
}

int main() {
    const int nReaders = 5, nWriters = 3;
    std::vector<std::thread> readers(nReaders);
    std::vector<std::thread> writers(nWriters);

    for (int i = 0; i < nReaders; ++i)
        readers[i] = std::thread(readerThread, i);

    for (int i = 0; i < nWriters; ++i)
        writers[i] = std::thread(writerThread, i, i+1);

    for (auto& thread : readers)
        thread.join();

    for (auto& thread : writers) 
        thread.join();

    return 0;
}
