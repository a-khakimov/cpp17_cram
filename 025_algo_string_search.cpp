#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>

template <typename itr>
static void print (itr it, size_t chars)
{
    std::copy_n(it, chars, std::ostream_iterator<char> { std::cout });
    std::cout << std::endl;
}

#if true
int main()
{
    const std::string long_string = "In mathematical logic, a predicate is "
                                    "commonly understood to be a Boolean-valued "
                                    "function P: X→ {true, false}, called a predicate on X.";

    const std::string pattern = "predicate";

    {
        auto match = std::search(long_string.begin(), long_string.end(), pattern.begin(), pattern.end());
        print(match, pattern.length());
    }

    {
        auto match = std::search(long_string.begin(), long_string.end(),
                                 std::default_searcher(pattern.begin(), pattern.end()));
        print(match, pattern.length());
    }

    {
        auto match = std::search(long_string.begin(), long_string.end(),
                                 std::boyer_moore_searcher(pattern.begin(), pattern.end()));
        print(match, pattern.length());
    }


    {
        auto match = std::search(long_string.begin(), long_string.end(),
                                 std::boyer_moore_horspool_searcher(pattern.begin(), pattern.end()));
        print(match, pattern.length());
    }
}
#endif
