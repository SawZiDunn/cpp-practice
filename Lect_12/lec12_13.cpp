// Mul-thred
#include <iostream>
#include <thread>
#include <chrono>


void threadFunction() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << " " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for 2 seconds
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Start main" << std::endl;
    std::thread myThread(threadFunction); // Create a thread that runs threadFunction
    myThread.join(); // Wait for the thread to complete
    // myThread.detach(); 
    std::cout << "End main" << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(20));
    return 0;
}
