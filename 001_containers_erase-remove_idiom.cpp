#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 2, 3, 2, 1};
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;
    const auto new_end (remove(v.begin(), v.end(), 2));
    v.erase(new_end, v.end());
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;


    const auto odd ([](int i) {
        return i % 2 != 0;
    });

    v.erase(remove_if(v.begin(), v.end(), odd), v.end());
    v.shrink_to_fit();
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;
}
