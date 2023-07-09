/* Task in Replit(Compiler) - https://replit.com/@Bgns/Dining-Philosophers-with-Multithreading-or-94#main.cpp

Task: Imagine you have five philosophers sitting around a roundtable. The philosophers do only two kinds of activities.
One: they contemplate, and two: they eat. However, they have only five forks between themselves to eat their food.
Each philosopher requires the fork to his left and the fork to his right to eat his food. Design a solution 
where each philosopher can eat his food without causing a deadlock. */

#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>

const int NPhilosophers = 5;
std::mutex forks[NPhilosophers];
std::condition_variable cv[NPhilosophers];

void philosopher(int id) {
  int leftFork = id;
  int rightFork = (id + 1) % NPhilosophers;

  std::unique_lock<std::mutex> leftLock(forks[leftFork]);
  std::unique_lock<std::mutex> rightLock(forks[rightFork]);

  std::cout << "Philosopher #" << id + 1 << " is contemplating\n";

  cv[leftFork].wait(leftLock, [&] { return !forks[leftFork].try_lock(); });
  cv[rightFork].wait(leftLock, [&] { return !forks[rightFork].try_lock(); });

  std::cout << "Philosopher #" << id + 1 << " is eating\n";

  leftLock.unlock();
  rightLock.unlock();
  cv[leftFork].notify_one();
  cv[rightFork].notify_one();
}

int main() {
  std::vector<std::thread> philosophers;

  for (int i = 0; i < NPhilosophers; ++i) {
    philosophers.emplace_back(philosopher, i);
  }

  for (auto &thread : philosophers) {
    thread.join();
  }

  return 0;
}
