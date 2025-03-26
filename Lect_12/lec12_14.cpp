#include <iostream>
#include <thread>
#include <chrono>

const size_t kNumFriends = 6;
void greeting(size_t myNum) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause for 0.1 seconds
    std::cout << myNum << " Hello, world!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause for 0.1 seconds
    std::cout << myNum << " Hello, again!" << std::endl;
}
int main(int argc, char *argv[]) {
    std::cout << "Let's hear from " << kNumFriends << " threads." << std::endl; 
    // declare array of empty thread handles
    std::thread friends[kNumFriends];
    // Spawn threads
    for (size_t i = 0; i < kNumFriends; i++) { 
        friends[i] = std::thread(greeting, i);
    }

    // Wait for threads
    for (size_t i = 0; i < kNumFriends; i++){ 
        if (friends[i].joinable()) {
            friends[i].join(); // It's important to join the threads
        }
    }
    std::cout << "Everyone's said hello!" << std::endl;
    return 0; 
}