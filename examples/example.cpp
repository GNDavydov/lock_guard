// Copyright 2021 GNDavydov

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#include <lock_guard.hpp>

void longPrint(const std::string &str) {
    static std::mutex stream_mutex;
    my_lock_guard::lock_guard<std::mutex> lock_stream(stream_mutex);
    std::cout << "Ready to print" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << str << std::endl;
}


int main() {
    std::thread t1(longPrint, "Hello, world!");
    std::thread t2(longPrint, "Hi!");
    std::thread t3(longPrint, "Buy!");

    t1.join();
    t2.join();
    t3.join();

    exit(EXIT_SUCCESS);
}
