#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#if false
int main()
{
    std::vector<std::string> v { "hello", "my", "little", "pony" };
    std::sort(v.begin(), v.end());
    do {
        std::copy(v.begin(), v.end(), std::ostream_iterator<std::string> {std::cout, ", "});
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
}
#endif
