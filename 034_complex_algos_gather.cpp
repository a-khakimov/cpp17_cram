#include <iostream>
#include <algorithm>
#include <string>
#include <functional>


template <typename It, typename F>
std::pair<It, It> gather(It first, It last, It gather_pos, F predicate)
{
    return { std::stable_partition(first, gather_pos, std::not_fn(predicate)),
                std::stable_partition(gather_pos, last, predicate) };
}

template <typename It, typename F>
void gather_sort(It first, It last, It gather_pos, F comp_func)
{
    auto inv_comp_func = [&](const auto& ...ps) {
        return ! comp_func(ps...);
    };

    std::stable_sort(first, gather_pos, inv_comp_func);
    std::stable_sort(gather_pos, last, comp_func);
}

#if false
int main()
{
    auto is_a = [](char c) {
        return  c == 'a';
    };
    {
        std::string a {"a_a_a_a_a_a_a_a_a_a_a"};
        auto middle = a.begin() + a.size() / 2;
        gather(a.begin(), a.end(), middle, is_a);
        std::cout << a << std::endl;
    }
    {
        std::string a {"a_a_a_a_a_a_a_a_a_a_a"};
        gather(a.begin(), a.end(), a.begin(), is_a);
        std::cout << a << std::endl;
    }
    {
        std::string a {"a_a_a_a_a_a_a_a_a_a_a"};
        auto middle = a.begin() + a.size() / 2;
        gather(a.begin(), a.end(), middle, is_a);
        std::cout << a << std::endl;
        gather(a.begin(), a.end(), a.end(), is_a);
        std::cout << a << std::endl;
    }
    {
        std::string a {"_1_2_3_4_5_6_7_8_9_0_"};
        gather_sort(a.begin(), a.end(), a.begin() + a.size() / 2, std::less<char>{});
        std::cout << a << std::endl;
    }
}
#endif
