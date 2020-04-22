#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

static auto norm (int min, int max, int new_max)
{
    const double diff = max - min;
    return [=](int val) {
        return int((val - min) / diff * new_max);
    };
}

static auto clampval (int min, int max)
{
    return [=] (int val) -> int {
        return std::clamp(val, min, max);
    };
}

#if true
int main()
{
    std::vector<int> v { 0, 1000, 500, 1, 200, 900, 521, 233, 12 };

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>{ std::cout, ", " });
    std::cout << std::endl;

    const auto [ min_it, max_it ] = std::minmax_element(begin(v), end(v));

    std::vector<int> v_norm;
    std::transform(begin(v), end(v), std::back_inserter(v_norm), norm(*min_it, *max_it, 500));
    std::copy(v_norm.begin(), v_norm.end(), std::ostream_iterator<int>{ std::cout, ", " });
    std::cout << std::endl;

    std::transform(begin(v), end(v), v_norm.begin(), clampval(0, 500));
    std::copy(v_norm.begin(), v_norm.end(), std::ostream_iterator<int>{ std::cout, ", " });
    std::cout << std::endl;

}
#endif
