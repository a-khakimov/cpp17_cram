#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cassert>

template <typename C, typename T>
void insert_sorted(C& c, const T& item)
{
    const auto insert_pos (std::lower_bound(begin(c), end(c), item));
    c.insert(insert_pos, item);
}


#if false
int main()
{
    std::vector<std::string> v {"hello", "my", "little", "pony", "aaa", "yyy"};
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;

    // insert_sorted works with only sorted containers
    assert(false == std::is_sorted(begin(v), end(v)));
    std::sort(v.begin(), v.end());
    assert(true == std::is_sorted(begin(v), end(v)));
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;

    insert_sorted(v, "zzz");
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;
}
#endif
