#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore sem1(1); // Initial value 1 
std::counting_semaphore sem2(0); // Initial value 0

void runMeFirst() {
    std::cout << "Run me first" << std::endl;
    sem2.release(); // que to runMeSecond 
}

void runMeSecond() {
    sem1.acquire(); // Waiting for runMeFirst to release first semaphore
    std::cout << "I run second" << std::endl;
    sem2.release(); // Signal runMeThird to run
}

void runMeThird() {
    sem2.acquire(); // Waiting for both runMeFirst and runMeSecond to release the second semaphore
    std::cout << "I run third" << std::endl;
}

int main() {
    std::thread thread1(runMeFirst);
    std::thread thread2(runMeSecond);
    std::thread thread3(runMeThird);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
