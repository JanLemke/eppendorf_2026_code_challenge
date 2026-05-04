#ifndef TASKS_HPP
#define TASKS_HPP
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

class task : public std::thread{
    public:
        task();
        virtual ~task();
};

#endif //TASKS_HPP
