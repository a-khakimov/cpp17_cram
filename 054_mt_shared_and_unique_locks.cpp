#include <iostream>
#include <vector>
#include <thread>
#include <shared_mutex>

using namespace std::chrono_literals;

std::shared_mutex shared_mut;

using shared_lck = std::shared_lock<std::shared_mutex>;
using unique_lck = std::unique_lock<std::shared_mutex>;

static void print_exclusive()
{
    unique_lck l { shared_mut, std::defer_lock };

    if (l.try_lock()) {
        std::cout << "get lock" << std::endl;
    } else {
        std::cout << "unable lock" << std::endl;
    }
}

static void exclusive_throw()
{
    unique_lck { shared_mut };
    throw 123;
}

#if false
int main()
{
    {
        shared_lck sl1 { shared_mut };
        std::cout << "shared lock once" << std::endl;
        {
            shared_lck sl2 { shared_mut };
            std::cout << "shared lock twice" << std::endl;
            print_exclusive();
        }
        std::cout << "shared lock once again" << std::endl;
        print_exclusive();
    }
    std::cout << "lock is free" << std::endl;

    print_exclusive();

    try {
        exclusive_throw();
    } catch (int e) {
        std::cout << "got exception " << e << std::endl;
    }

    print_exclusive();
}
#endif
