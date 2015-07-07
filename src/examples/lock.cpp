/*
 * lock.cpp
 *
 *  Created on: 2015年7月6日
 *      Author: zhusheng
 */
#include "coroutine/scheduler.h"
#include "coroutine/coroutine.h"
#include "coroutine/lock.h"
#include "log/Logger.h"
#include "iostream"

using namespace coroutine;

int main()
{
    Logger::logger().setDevice(NULL);

    scheduler scheduler1;
    current_scheduler = &scheduler1;
    std::cout << "hello world 0\n";

    lock_t lock;
    lock.lock();
    scheduler1.add([&lock]{
            std::cout << "hello world 1.1\n";
            lock.lock();
            std::cout << "hello world 1.2\n";
    });
    scheduler1.add([&lock]{
            std::cout << "hello world 2.1\n";
            lock.unlock();
            std::cout << "hello world 2.2\n";
    });
    scheduler1.run();
    return 0;
}



