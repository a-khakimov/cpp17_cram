#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>


template <typename InIt, typename OutIt, typename T>
InIt split (InIt it, InIt end_it, OutIt out_it, T split_val)
{
    while (it != end_it) {
        auto slice_end = std::find(it, end_it, split_val);
        //*out_it++ = bin_func(it, slice_end);
        *out_it++ = std::string(it, slice_end);
        if (slice_end == end_it) {
            return end_it;
        }
        it = std::next(slice_end);
    }
    return it;
}

#if false
int main()
{
    const std::string s = {"hello my little pony"};
    /*
    auto binfunc = [](auto it_a, auto it_b) {
        return std::string(it_a, it_b);
    };
    */

    std::list<std::string> l;

    split(s.begin(), s.end(), std::back_inserter(l), ' ');

    for (const auto& i : l) {
        std::cout << i << std::endl;
    }
}
#endif
