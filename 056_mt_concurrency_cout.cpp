#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <vector>


struct pcout : public std::stringstream {
    static inline std::mutex cout_mutex;
    ~pcout() {
        std::lock_guard<std::mutex> l { cout_mutex };
        std::cout << rdbuf();
        std::cout.flush();
    }
};

#if true
int main()
{

    auto print_cout = [](const int i) {
        std::cout << "cout from " << i << std::endl;
    };

    auto print_pcout = [](const int i) {
        pcout{} << "pcout from " << i << std::endl;
    };

    std::cout << "===================== " << std::thread::hardware_concurrency() << std::endl;

    std::vector<std::thread> v;

    for (size_t i = 0; i < 10; ++i) {
        v.emplace_back(print_cout, i);
    }
    for (auto& t : v) { t.join(); }

    v.clear();
    std::cout << "===================== " << std::thread::hardware_concurrency() << std::endl;

    for (size_t i = 0; i < 10; ++i) {
        v.emplace_back(print_pcout, i);
    }
    for (auto& t : v) { t.join(); }

    std::cout << "threads joined" << std::endl;
}
#endif
