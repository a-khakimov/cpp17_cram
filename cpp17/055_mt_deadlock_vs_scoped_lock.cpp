#include <iostream>
#include <thread>
#include <mutex>

using namespace std::chrono_literals;

std::mutex mut_a;
std::mutex mut_b;

#if false
int main()
{
    std::cout << "proc: " << std::thread::hardware_concurrency() << std::endl;

    auto deadlock_func_a = []()
    {
        std::cout << "A mutex a .." << std::endl;
        std::lock_guard<std::mutex> la { mut_a };
        std::this_thread::sleep_for(100ms);

        std::cout << "A mutex b .." << std::endl;
        std::lock_guard<std::mutex> lb { mut_b };

        std::cout << "A got mutexes" << std::endl;
    };    

    auto deadlock_func_b = []()
    {
        std::cout << "B mutex b .." << std::endl;
        std::lock_guard<std::mutex> lb { mut_b };
        std::this_thread::sleep_for(100ms);

        std::cout << "B mutex a .." << std::endl;
        std::lock_guard<std::mutex> la { mut_a };

        std::cout << "B got mutexes" << std::endl;
    };

    auto norm_func_a = []()
    {
        std::scoped_lock l { mut_a, mut_b };
        std::cout << "norm A got mutexes" << std::endl;
    };


    auto norm_func_b = []()
    {
        std::scoped_lock l { mut_a, mut_b };
        std::cout << "norm B got mutexes" << std::endl;
    };


    {
        std::thread t1 { norm_func_a };
        std::thread t2 { norm_func_b };
        t1.join();
        t2.join();
    }

    { // run deadlock
        std::thread t1 { deadlock_func_a };
        std::thread t2 { deadlock_func_b };
        t1.join();
        t2.join();
    }

    std::cout << "threads joined" << std::endl;
}
#endif
