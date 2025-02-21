#include <iostream>
#include <thread>

// Function to run in a thread
void printNumbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        std::cout << "Number: " << i << std::endl;
    }
}

int main() {
    std::thread t1(printNumbers, 1, 5); // Create a thread
    std::thread t2(printNumbers, 6, 10); // Another thread

    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish

    std::cout << "Threads completed!" << std::endl;

    return 0;
}
