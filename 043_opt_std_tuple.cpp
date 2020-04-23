#include <iostream>
#include <tuple>
#include <algorithm>
#include <numeric>

template <typename T, typename ...Ts>
void print_args(std::ostream& os, const T& v, const Ts& ...vs)
{
    os << v;
    std::initializer_list<int> {((os << ", " << vs), 0)...};
}

template <typename ...Ts>
std::ostream& operator << (std::ostream& os, const std::tuple<Ts...> &t)
{
    auto print_to_os([&os](const auto& ...xs) {
        print_args(os, xs...);
    });
    os << "(";
    std::apply(print_to_os, t);
    return os << ")";
}

template <typename T>
std::tuple<double, double, double, double>
sum_min_max_avg(const T& range)
{
    auto min_max = std::minmax_element(begin(range), end(range));
    auto sum = std::accumulate(begin(range), end(range), 0.0);
    return { sum, *min_max.first, *min_max.second, sum / range.size() };
}

template <typename T1, typename T2>
static auto zip(const T1& a, const T2& b)
{
    auto z = [](auto ...xs) {
        return [xs...](auto ...ys) {
            return std::tuple_cat(std::make_tuple(xs, ys) ...);
        };
    };
    return std::apply(std::apply(z, a), b);
}

#if true
int main()
{
    auto student_desc = std::make_tuple("ID", "Name", "GPA");
    auto student = std::make_tuple(1, "John", 3.7);
    std::cout << student_desc << std::endl;
    std::cout << student << std::endl;
    std::cout << std::tuple_cat(student_desc, student) << std::endl;
    std::cout << zip(student_desc, student) << std::endl;
}
#endif
