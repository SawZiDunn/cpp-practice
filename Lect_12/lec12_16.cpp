#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;  // Mutex for synchronization
int shared_data = 0;

void increment() {
    mtx.lock();   // Lock the mutex before accessing shared data
    ++shared_data;
    mtx.unlock(); // Unlock the mutex after accessing shared data
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Shared data: " << shared_data << std::endl;
    return 0;
}
