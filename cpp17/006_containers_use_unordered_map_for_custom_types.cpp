#include <iostream>
#include <unordered_map>

struct coord {
    int x;
    int y;
};

/* Без этого блока пользовательские типы в unordered_map в качестве ключа не засунуть */
#if true

/* Перегрузка условного оператора == */
bool operator==(const coord& l, const coord& r)
{
    return r.x == l.x && r.y == l.y;
}

/* Вычисление хэша для класса coord */
namespace std
{
template <>
struct hash<coord>
{
    using argument_type = coord;
    using result_type = size_t;

    result_type operator()(const argument_type& c) const
    {
        return static_cast<result_type>(c.x) + static_cast<result_type>(c.y);
    }
};
}
#endif

#if false
int main()
{
    std::unordered_map<coord, int> m {
        {{1, 1}, 0},
        {{2, 0}, 1},
        {{3, 1}, 2},
        {{4, 0}, 3},
    };

    for (const auto& [key, value] : m) {
        std::cout << key.x << ":" << key.y << std::endl;
    }
}
#endif
