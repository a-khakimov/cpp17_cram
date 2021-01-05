#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <random>

template <typename RD>
void histogram(size_t partitions, size_t samples)
{
    using rand_t = typename RD::result_type;
    partitions = std::max<size_t>(partitions, 10);
    RD rd;
    rand_t div = (double(RD::max()) + 1) / partitions;
    std::vector<size_t> v (partitions);
    for (size_t i = 0; i < samples; ++i) {
        ++v[rd() / div];
    }

    rand_t max_lem = *std::max_element(v.begin(), v.end());
    rand_t max_div = std::max(max_lem / 100, rand_t(1));

    for (size_t i = 0; i < partitions; ++i) {
        std::cout << std::setw(2) << i << ": " << std::string(v[i] / max_div, '*') << std::endl;
    }
}

#if false
int main()
{
    size_t partitions = 15;
    size_t samples = 2000;
    std::cout << "-- random_device --" << std::endl;
    histogram<std::random_device>(partitions, samples);
    std::cout << "-- default_random_engine --" << std::endl;
    histogram<std::default_random_engine>(partitions, samples);
    std::cout << "-- minstd_rand --" << std::endl;
    histogram<std::minstd_rand>(partitions, samples);
    std::cout << "-- minstd_rand0 --" << std::endl;
    histogram<std::minstd_rand0>(partitions, samples);
    std::cout << "-- knuth_b --" << std::endl;
    histogram<std::knuth_b>(partitions, samples);
    std::cout << "-- ranlux24 --" << std::endl;
    histogram<std::ranlux24>(partitions, samples);
    std::cout << "-- ranlux48 --" << std::endl;
    histogram<std::ranlux48>(partitions, samples);
    std::cout << "-- ranlux24_base --" << std::endl;
    histogram<std::ranlux24_base>(partitions, samples);
    std::cout << "-- ranlux48_base --" << std::endl;
    histogram<std::ranlux48_base>(partitions, samples);
    std::cout << "-- mt19937 --" << std::endl;
    histogram<std::mt19937>(partitions, samples);
    std::cout << "-- mt19937_64 --" << std::endl;
    histogram<std::mt19937_64>(partitions, samples);
}
#endif
