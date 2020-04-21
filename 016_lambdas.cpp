#include <iostream>
#include <string>

#if true
int main()
{
    auto just_one ( [](){ return 1; } );
    auto just_two ( []  { return 2; } );
    //std::cout << just_one << ", " << just_two << std::endl; // bad
    std::cout << just_one() << ", " << just_two() << std::endl; // good

    auto plus ( [](const auto l, const auto r) { return l + r; } );
    std::cout << plus(1, 2) << std::endl;
    std::cout << plus(std::string{"Hello "}, " home") << std::endl;

    auto plus_ten = [=](int x) { return  plus(10, x); }; // каррирование
    std::cout << plus_ten(2) << std::endl;

    std::cout << [](const auto l, const auto r){return l + r;}(1, 2) << std::endl; // if you're crazy

    //
    auto counter (
        [count = 0]() mutable { return ++count; }
    );
    std::cout << "counter = " << counter() << std::endl;
    std::cout << "counter = " << counter() << std::endl;

    auto plus2 = [](const int l, const int r) -> int { return l + r; };
}
#endif



/*
[список захвата](параметры)
    mutable             (необязательный)
    constexpr           (необязательный)
    exceptionattr       (необязательный)
    -> возвращаемый тип (необязательный)
{
    // тело
}
*/
