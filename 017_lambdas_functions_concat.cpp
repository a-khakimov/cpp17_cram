#include <iostream>
#include <functional>

// непонятно, но круто

// typename ...Ts - переменное количество аргументов шаблона
// sizeof... (ts) - так мы узнаем количество аргументов
// почему без constexpr не работает?
// [=](auto ...parameters) - чтооооо?

template <typename T, typename ...Ts>
auto concat(T t, Ts ...ts)
{
    if constexpr (sizeof... (ts) > 0) {
        return  [=](auto ...parameters) {
            return t(concat(ts...)(parameters...));
        };
    } else {
        return t;
    }
}

#if true
int main()
{
    auto twice ([](int i) { return i * 2; });
    auto thrice ([](int i) { return i * 3; });
    auto combined = concat(twice, thrice, twice, std::plus<int>{});
    std::cout << combined(2, 3) << std::endl;
}
#endif
