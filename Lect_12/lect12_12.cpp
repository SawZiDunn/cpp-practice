#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void print(int id, int loop) { 
    long i;
    int j;
    cout << "Thread " << id << " running!\n"; 
    for (j=0; j<loop; j++) {
        cout << "Thread " << id << " loop " << j << endl;
        for (i=0; i<100; i++) { 
            this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
    cout << "Thread " << id << " finished!\n"; 
}
            

int main() {
    thread t1(print,1, 10); // Create thread to run print()
    thread t2(print,2, 10); // Create thread to run print()
    thread t3(print,3, 20); // Create thread to run print()
    thread t4(print,4, 20); // Create thread to run print()
    thread t5(print,5, 25); // Create thread to run print()
    t1.join();        // Wait for thread to finish
    t2.join();        // Wait for thread to finish
    t3.join();        // Wait for thread to finish
    t4.join();        // Wait for thread to finish
    t5.join();        // Wait for thread to finish
    cout << "Main done\n";
    return 0;
}