#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

// TODO: разобраться с этим более детально

template <typename Function>
auto map(Function function)
{
    return [=] (auto reduce_function) {
        return [=] (auto accum, auto input) {
            return reduce_function(accum, function(input));
        };
    };
}

template <typename T>
auto filter(T predicate)
{
    return [=] (auto reduce_function) {
        return [=] (auto accum, auto input) {
            if (predicate(input)) {
                return reduce_function(accum, input);
            } else {
                return accum;
            }
        };
    };
}


#if true
int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 6 };

    auto even ([](int i) { return i % 2 == 0; });
    auto twice ([](int i) { return i * 2; });

    auto copy_and_advance([](auto it, auto input) {
        *it = input;
        return ++it;
    });

    std::accumulate(v.begin(), v.end(),
        std::ostream_iterator<int> { std::cout, ", " },
        filter(even)(
            map(twice)(
                copy_and_advance
            )
        )
    );

    std::cout << std::endl;
}
#endif
