/* Task in Replit(Compiler) - https://replit.com/@Bgns/Synchronous-Executor-with-Multithreading-or-96

Task: Given an AsyncExecutor class that performs tasks asynchronously using its execute() method, your
task is to modify the execution behaviour to make it synchronous without altering the original class implementation.
The main thread should wait until the asynchronous execution is complete before proceeding further. You can only
work with the compiled binaries and cannot modify the source code of the AsyncExecutor class. */

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

class AsyncExecutor
{
public: 
    template<typename Callback>
    void execute(Callback callback)
    {
        std::thread([callback]() {
             std::this_thread::sleep_for(std::chrono::seconds(5)); callback(); }
         ).detach();
    }
};

class SyncExecutor : public AsyncExecutor 
{
public:
    template<typename Callback>
    void execute(Callback callback)
    {
        std::mutex mutex;
        std::condition_variable cv;
        bool completeTask = false;

        AsyncExecutor::execute( [&]() {
            callback();
            std::unique_lock<std::mutex> lock(mutex);
            completeTask = true;
            cv.notify_one();
        });
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [&]() { return completeTask; });
    }
};

int main() {
    SyncExecutor executor;
    
    executor.execute([]() {
        std::cout << "Asynchronous work is done!" << std::endl;
    });

    std::cout << "Main thread continues execution." << std::endl;
    return 0;
}
