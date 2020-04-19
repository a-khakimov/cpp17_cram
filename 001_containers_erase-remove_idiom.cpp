#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

// Quick reomve O(1) by index
template<typename T>
void quick_remove_at(std::vector<T> &v, std::size_t idx)
{
    if (idx < v.size()) {
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

// Quick reomve O(1) by iterator
template<typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it)
{
    if (it != v.end()) {
        *it = std::move(v.back());
        v.pop_back();
    }
}

int main()
{
    // c++11
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 2, 3, 2, 1};
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;
    const auto new_end (remove(v.begin(), v.end(), 2));
    v.erase(new_end, v.end());
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;


    // c++17
    const auto odd ([](int i) {
        return i % 2 != 0;
    });

    v.erase(remove_if(v.begin(), v.end(), odd), v.end());
    v.shrink_to_fit();
    for (auto i : v) { std::cout << i << ", "; } std::cout << std::endl;

    // Using quick remove
    std::vector<int> v2 {1, 2, 3, 4, 5, 6, 7, 8, 2, 3, 2, 1};
    for (auto i : v2) { std::cout << i << ", "; } std::cout << std::endl;
    quick_remove_at(v2, 2); // by index
    for (auto i : v2) { std::cout << i << ", "; } std::cout << std::endl;
    quick_remove_at(v2, v2.begin()); // by iterator
    for (auto i : v2) { std::cout << i << ", "; } std::cout << std::endl;

}
