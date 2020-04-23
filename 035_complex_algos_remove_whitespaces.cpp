#include <iostream>
#include <string>
#include <algorithm>

template <typename It>
It remove_multi_whitespaces(It it, It end_it)
{
    return std::unique(it, end_it, [](const auto& a, const auto&b) {
        return std::isspace(a) && std::isspace(b);
    });
}

#if false
int main()
{
 std::string s = "hello      my     little    pony";
 std::cout << s << std::endl;
 s.erase(remove_multi_whitespaces(s.begin(), s.end()), s.end());
 std::cout << s << std::endl;
}
#endif
