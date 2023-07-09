/* Task in Replit(Compiler) - https://replit.com/@Bgns/Calculate-Sum-with-Multithreading-or-93#main.cpp

Task:Write a C++ program that utilizes multiple threads to calculate the sum of elements in an array. 
The program should divide the array among the threads, assigning each thread a specific portion of the array to process.
Each thread should calculate the sum of its assigned portion. The main thread should wait for all the threads to finish 
their calculations, and then calculate the final sum by combining the results from each thread. The program should output the final sum */

#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

void calculateSum(const std::vector<int>& arr, int start, int end, long long& partialSum)
{
    partialSum = 0;
    for (int i = start; i < end; ++i)
    {
        partialSum += arr[i];
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int nThreads = 4;

    if (arr.size() == 0)
    {
        std::cerr << "Error: Array size is not divisible by the number of threads." << std::endl;
        return 1;
    }

    int portionSize = arr.size() / nThreads;

    std::vector<long long> partialSums(nThreads);
    std::vector<std::thread> threads(nThreads);

    for (int i = 0; i < nThreads; ++i)
    {
        int start = i * portionSize;
        int end = (i == nThreads - 1) ? arr.size() : start + portionSize;
        threads[i] = std::thread(calculateSum, std::cref(arr), start, end, std::ref(partialSums[i]));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    long long finalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0LL);
    std::cout << "Sum of arr = " << finalSum << std::endl;

    return 0;
}
