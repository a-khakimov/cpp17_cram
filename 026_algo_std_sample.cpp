#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <map>
#include <iomanip>

#if false
int main()
{
    const size_t data_points = 1000;
    const size_t sample_points = 100;

    const int mean = 10;
    const size_t dev = 3;

    std::random_device r_dev;
    std::mt19937 gen { r_dev() };
    //std::normal_distribution<> d { mean, dev };
    std::extreme_value_distribution<> d { mean, dev };
    //std::extreme_value_distribution()

    std::vector<int> v;
    v.reserve(data_points);
    std::generate_n(std::back_inserter(v), data_points, [&] {
        return d(gen);
    });

    std::vector<int> samples;
    samples.reserve(sample_points);
    std::sample(v.begin(), v.end(), std::back_inserter(samples),
                sample_points, std::mt19937{ std::random_device{}() });

    std::cout << "====== DATA POINTS ======" << std::endl;
    std::map<int, size_t> hist_v;
    for (int i : v) {  ++hist_v[i];   }
    for (const auto& [value, count] : hist_v) {
        std::cout << std::setw(2) << value << " " << std::string(count, '*') << std::endl;
    }

    std::cout << "====== SAMPLE POINTS ======" << std::endl;
    std::map<int, size_t> hist_s;
    for (int i : samples) {  ++hist_s[i];   }
    for (const auto& [value, count] : hist_s) {
        std::cout << std::setw(2) << value << " " << std::string(count, '*') << std::endl;
    }
}
#endif
