#include <iostream>
#include <algorithm>
#include <iterator>
#include <complex>
#include <numeric>
#include <vector>
#include <future>

using cmplx = std::complex<double>;

static auto scaler (int min_from, int max_from,
                    double min_to, double max_to)
{
    const int w_from = max_from - min_from;
    const double w_to = max_to - min_to;
    const int mid_from = (max_from - min_from) / 2 + min_from;
    const double mid_to = (max_to - min_to) / 2 + min_to;
    return [=](int from) {
        return double(from - mid_from) / w_from * w_to + mid_to;
    };
}

template <typename A, typename B>
static auto scaled_cmplx(A scaler_x, B scaler_y)
{
    return [=](int x, int y) {
        return cmplx { scaler_x(x), scaler_y(y) };
    };
}

static auto malderbrot_iterations(cmplx c)
{
    cmplx z {};
    size_t iterations {0};
    const size_t max_iterations { 10000 };
    while (std::abs(z) < 2 && iterations < max_iterations) {
        ++iterations;
        z = std::pow(z, 2) + c;
    }
    return iterations;
}

#if true
int main()
{
    const size_t w = 200;
    const size_t h = 50;
    auto scale = scaled_cmplx(
                scaler(0, w, -2.0, 1.0),
                scaler(0, h, -1.0, 1.0)
            );

    auto i_to_xy = [=](int i) {
        return scale(i % w, i / w);
    };

    auto to_iteration_count = [=](int i) {
        return std::async(std::launch::async, malderbrot_iterations, i_to_xy(i));
    };

    std::vector<int> v (w * h);
    std::vector<std::future<size_t>> r (w * h);
    std::iota(v.begin(), v.end(), 0);
    std::transform(v.begin(), v.end(), r.begin(), to_iteration_count);

    auto binfunc = [n {0}](auto output_it, std::future<size_t>& x) mutable {
        *++output_it = (x.get() > 50 ? '*' : ' ');
        if (++n % w == 0) {
            ++output_it = '\n';
        }
        return output_it;
    };

    std::accumulate(begin(r), end(r), std::ostream_iterator<char> { std::cout }, binfunc);
}
#endif
