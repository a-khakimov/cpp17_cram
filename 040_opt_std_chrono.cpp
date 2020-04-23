#include <iostream>
#include <iomanip>
#include <chrono>

std::ostream& operator << (std::ostream& os, const std::chrono::time_point<std::chrono::system_clock>& t)
{
    const auto tt = std::chrono::system_clock::to_time_t(t);
    const auto loct = std::localtime(&tt);
    return os << std::put_time(loct, "%c");
}

using days = std::chrono::duration<std::chrono::hours::rep, std::ratio_multiply<std::chrono::hours::period, std::ratio<24>>>;

constexpr days operator ""_days(unsigned long long h)
{
    return days{h};
}

using namespace std::chrono_literals;

#if false
int main()
{
    auto now = std::chrono::system_clock::now();
    std::cout << now << std::endl;
    std::chrono::hours chrono_12h {12};
    std::cout << now + chrono_12h << std::endl;
    std::cout << now - 12h - 15min - 12s - 1ms << std::endl;
    std::cout << now - 20_days << std::endl;
}
#endif
