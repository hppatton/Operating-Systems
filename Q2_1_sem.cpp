#include <iostream>
#include <thread>
#include <semaphore>

std::binary_semaphore sem1(0); // Initial value 0 ensures runMeFirst runs first

void runMeFirst() {
    std::cout << "Run me first" << std::endl;
    sem1.release(); // Signal runMeSecond to proceed
}

void runMeSecond() {
    sem1.acquire(); // Wait for runMeFirst to release the semaphore
    std::cout << "I run second" << std::endl;
}

int main() {
    std::thread thread1(runMeFirst);
    std::thread thread2(runMeSecond);

    thread1.join();
    thread2.join();

    return 0;
}
