#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <tuple>


template <typename It>
std::tuple<It, char, size_t> occurences(It it, It end_it)
{
    if (it == end_it) {
        return { it, '?', 0 };
    }
    const char c = *it;
    const auto diff = std::find_if(it, end_it, [c](char x) {
        return c != x;
    });
    return { diff, c, std::distance(it, diff) };
}

std::string compress(const std::string& s)
{
    std::stringstream r;
    for (auto it = s.begin(); it != s.end();) {
        const auto [ next_diff, c, n ] = occurences(it, s.end());
        r << c << n;
        it = next_diff;
    }
    return r.str();
}

std::string decompress(const std::string& s)
{
    std::stringstream ss {s};
    std::stringstream r;
    char c;
    size_t n;
    while (ss >> c >> n) {
        r << std::string(n, c);
    }
    return r.str();
}

#if false
int main()
{
    std::string s = "abbcccddddeeeeeffffffggggggg";
    std::string cs = compress(s);
    std::cout << s << std::endl;
    std::cout << cs << std::endl;
    std::cout << decompress(cs) << std::endl;
}
#endif
