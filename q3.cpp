#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>

struct requestStructure {
    int request_id;
    std::string ip_address;
    std::string page_requested;
};

std::mutex mtx; // Mutex for thread-safe output
std::condition_variable cv; // Condition variable for synchronization
bool request_available = false; // Flag to indicate request presence in the queue

std::queue<requestStructure> msg_queue; // Queue for client requests

const std::string webPages[10] = {"google.com", "yahoo.com", "instagram.com, "youtube.com", "twitch.com", "discord.com", "bing.com", "facebook.com", "tiktok.com", "at&t.com"}; // List of web pages

void listen() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(std::rand()
