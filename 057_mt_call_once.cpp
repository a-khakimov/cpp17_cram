#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <vector>

std::once_flag callflag;

#if true
int main()
{
    auto print_once = []() {
        std::cout << "!";
    };

    auto print = [&](const int i) {
        std::call_once(callflag, print_once);
        std::cout << i;
    };

    std::vector<std::thread> v;

    for (size_t i = 0; i < 10; ++i) {
        v.emplace_back(print, i);
    }
    for (auto& t : v) { t.join(); }

    std::cout << std::endl << "threads joined" << std::endl;
}
#endif
