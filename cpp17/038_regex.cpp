#include <iostream>
#include <iterator>
#include <regex>
#include <algorithm>
#include <iomanip>

template <typename InputIt>
void print(InputIt it, InputIt end_it)
{
    while (it != end_it) {
        const std::string link = *it++;
        if (it == end_it) {
            break;
        }
        const std::string desc = *it++;
        std::cout << std::left << std::setw(28) << desc << "  " << link << std::endl;
    }
}


#if false
int main()
{
    /*
     * // curl -s "https://isocpp.org/blog" | ./a.out
    std::cin >> std::noskipws;
    const std::string in { std::istream_iterator<char>{std::cin }, {} };
    const std::regex link_re { "<a href=\"([^\"]*)\"[^<]*>([^<]*)</a>" };
    std::regex_token_iterator it { in.begin(), in.end(), link_re, {1, 2} };
    print(it, {});
    */

    const std::string s = "abc aabbccc";
    const std::regex re { "a(b*)(c*)" };
    std::sregex_token_iterator it { s.begin(), s.end(), re, {1, 2} };
    std::cout << s << std::endl;
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;

}
#endif
