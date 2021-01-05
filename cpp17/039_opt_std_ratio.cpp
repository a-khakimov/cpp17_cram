#include <iostream>
#include <chrono>
#include <ratio>
#include <cmath>
#include <iomanip>
#include <optional>

using seconds = std::chrono::duration<double>;
using milliseconds = std::chrono::duration<double, std::ratio_multiply<seconds::period, std::milli>>;
using microseconds = std::chrono::duration<double, std::ratio_multiply<seconds::period, std::micro>>;

static std::pair<std::string, seconds> get_input()
{
    std::string s;
    const auto tic = std::chrono::steady_clock::now();
    if (!(std::cin >> s)) {
        return {{}, {}};
    }
    const auto toc = std::chrono::steady_clock::now();
    return {s, toc - tic};
}

#if false
int main()
{
    while (true) {
        std::cout << "Please print 'fuck' as fast you can: ";
        const auto [ input, time ] = get_input();
        if (input.empty()) {
            break;
        } else if (input == "fuck") {
            std::cout << "Bravo! \nYour time " << time.count() << "s, ";
            std::cout << milliseconds(time).count() << "ms, ";
            std::cout << microseconds(time).count() << "us" << std::endl;
        } else {
            std::cout << "Your input does not match. Try again." << std::endl;
        }
    }
}
#endif
