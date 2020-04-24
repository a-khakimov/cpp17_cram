#include <iostream>
#include <thread>

using namespace std::chrono_literals;

#if false
int main()
{
    std::cout << "proc: " << std::thread::hardware_concurrency() << std::endl;

    auto some_thread = [](const int i)
    {
        std::this_thread::sleep_for(1ms * i);
        std::cout << "hello from " << i << std::endl;
        std::this_thread::sleep_for(1s * i);
        std::cout << "bye from " << i << std::endl;
    };

    std::thread t1 { some_thread, 1 };
    std::thread t2 { some_thread, 2 };
    std::thread t3 { some_thread, 3 };

    t1.join();
    t2.join();
    t3.detach();

    std::cout << "threads joined" << std::endl;
}
#endif
