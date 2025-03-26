#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> productQueue;
const int sentinel = -1; // Sentinel value for signaling termination

// Producer function
void producer(int id) {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        std::cout << "Producer " << id << " producing product " << i << std::endl;
        productQueue.push(i); // Push a new product into the queue
        cv.notify_one(); // Notify one waiting consumer
        lock.unlock(); 
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }

    // Signal consumers to terminate by pushing the sentinel value for each consumer
    for (int i = 0; i < 2; ++i) { // Assuming there are 2 consumers
        std::unique_lock<std::mutex> lock(mtx);
        productQueue.push(sentinel); // Push sentinel value into the queue
        cv.notify_one(); // Notify one waiting consumer
    }
}

// Consumer function
void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        cv.wait(lock, [] { return !productQueue.empty(); }); // Wait until the queue is not empty
        int product = productQueue.front(); // Get the product from the queue
        productQueue.pop(); // Remove the product from the queue
        lock.unlock(); 

        if (product == sentinel) break; // Check for the sentinel value and exit if found

        std::cout << "Consumer " << id << " consuming product " << product << std::endl;
    }
}

int main() {
    std::thread p1(producer, 1);
    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);

    p1.join();
    c1.join();
    c2.join();

    return 0;
}
