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

#include <iostream>
#include <string>

#if false
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


// Полиморфизм с лямбда-выражениями
/* понял плохо, но круто
 * надо искать способы применения этого примера
 */

#include <deque>
#include <list>
#include <vector>
#include <functional>

static auto consumer(auto& container)
{
    return [&] (auto value) {
        container.push_back(value);
    };
}

static void print(const auto& c)
{
    for (const auto i : c) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

#if false
int main()
{
    std::deque<int> d;
    std::vector<int> v;
    std::list<int> l;

    const std::vector<std::function<void(int)>> consumers {
        consumer(d), consumer(l), consumer(v)
    };

    for (size_t i = 0; i < 10; ++i) {
        //  почему && ?
        for (auto&& consume : consumers) {
            consume(i);
        }
    }

    print(d);
    print(l);
    print(v);
}
#endif

