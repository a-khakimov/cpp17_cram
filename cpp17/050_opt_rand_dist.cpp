#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <string>
#include <algorithm>


template <typename T>
void print_distro(T distro, size_t samples, const std::string& n)
{
    std::cout << "-- " << n << " --" << std::endl;

    std::default_random_engine e;
    std::map<int, size_t> m;
    for (size_t i = 0; i < samples; ++i) {
        m[distro(e)] += 1;
    }

    const size_t max_elm = std::max_element(m.begin(), m.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    })->second;

    const size_t max_div = std::max(max_elm / 100, size_t(1));

    for (const auto [randval, count] : m) {
        if (count < max_elm / 200) {
            continue;
        }
        std::cout << std::setw(3) << randval << " : " << std::string(count / max_div, '*') << std::endl;
    }
}

using namespace std;

#if false
int main()
{
    size_t samples = 100;
    print_distro(uniform_int_distribution<int>{0, 9}, samples, "uniform_int_distribution"s);
    print_distro(normal_distribution<double>{0.1, 2.0}, samples, "normal_distribution"s);
    initializer_list<double> i {0, 5, 10, 15};
    initializer_list<double> w {0.1, 1.0, 0.1};
    print_distro(piecewise_constant_distribution<double>{i.begin(), i.end(), w.begin()}, samples, "piecewise_constant_distribution"s);
}
#endif
