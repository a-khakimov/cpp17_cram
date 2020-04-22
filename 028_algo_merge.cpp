#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <tuple>
#include <string>
#include <vector>

#if false
int main()
{
    using dict_t = std::pair<std::string, std::string>;
    std::deque<dict_t> dict1 = { { "aa", "AA" }, { "bb", "BB" }, { "ee", "EE" }, { "mm", "MM" } };
    std::deque<dict_t> dict2 = { { "cc", "CC" }, { "rr", "RR" }, { "kk", "KK" }, { "ll", "LL" } };

    std::deque<dict_t> dict3;

    std::sort(dict1.begin(), dict1.end());
    std::sort(dict2.begin(), dict2.end());

    std::merge(dict1.begin(), dict1.end(),
               dict2.begin(), dict2.end(),
               std::back_inserter(dict3));

    for (const auto i : dict1) { std::cout << i.first << " " << i.second << ", "; }
    std::cout << std::endl;

    for (const auto i : dict2) { std::cout << i.first << " " << i.second << ", "; }
    std::cout << std::endl;

    for (const auto i : dict3) { std::cout << i.first << " " << i.second << ", "; }
    std::cout << std::endl;
}
#endif
