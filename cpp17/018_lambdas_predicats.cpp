#include <iostream>
#include <functional>
#include <string>
#include <iterator>
#include <algorithm>
#include <typeinfo>


template <typename A, typename B, typename F>
auto combine(F binary_func, A a, B b)
{
    return [=](auto param) {
        return binary_func(a(param), b(param));
    };
}

// Модифицированный, более крутой вариант, который может принимать переменное количество условий
template <typename Condition, typename ...Conditions, typename F>
auto combine2(F binary_func, Condition condition, Conditions ...conditions)
{
    return [=](auto param) {
        if constexpr (sizeof... (conditions) > 0) {
            return binary_func(condition(param), combine2(binary_func, conditions...)(param));
        } else {
            return condition(param);
        }
    };
}

#if false
int main()
{
    auto begins_with_a = [](const std::string& s) -> bool {
        return s.find("a") == 0;
    };

    auto ends_with_b = [](const std::string& s) -> bool {
        return s.rfind("b") == s.length() - 1;
    };

    auto begins_with_c = [](const std::string& s) -> bool {
        return s.find("c") == 0;
    };

    {
        auto a_xxx_b = combine2(std::logical_or<>{}, begins_with_a, ends_with_b);
        std::vector<std::string> from { "a", "vvvv", "ab", "a_xxxx_b", "c" };
        std::vector<std::string> to(10);
        std::copy(from.begin(), from.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl << "--" << std::endl;
        std::copy_if(from.begin(), from.end(), to.begin(), a_xxx_b);
        std::copy(to.begin(), to.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }
    {
        auto a_xxx_b = combine2(std::logical_or<>{}, begins_with_c, ends_with_b);
        std::vector<std::string> from { "a", "vvvv", "ab", "a_xxxx_b", "c" };
        std::vector<std::string> to(10);
        std::copy(from.begin(), from.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl << "--" << std::endl;
        std::copy_if(from.begin(), from.end(), to.begin(), a_xxx_b);
        std::copy(to.begin(), to.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }
}
#endif
