#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

#if false
int main()
{
    const size_t sig_len = 50;
    std::vector<double> as (sig_len);
    std::vector<int> ds (sig_len);

    auto sig_gen = [n{0}]() mutable {
        return 5.0 * std::sin(n++ * 2.0 * M_PI / 50);
    };

    std::generate(as.begin(), as.end(), sig_gen);
    std::copy(as.begin(), as.end(), ds.begin());

    std::copy(as.begin(), as.end(), std::ostream_iterator<double> { std::cout, " " });
    std::cout << std::endl;
    std::copy(ds.begin(), ds.end(), std::ostream_iterator<double> { std::cout, " " });
    std::cout << std::endl;

    std::cout << std::inner_product(as.begin(), as.end(), ds.begin(), 0.0, std::plus<double>{}, [](double a, double b) {
        return std::pow(a- b, 2);
    });
    std::cout << std::endl;
}
#endif
