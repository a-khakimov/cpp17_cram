#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <future>

static std::map<char, size_t> histogram(const std::string& s)
{
    std::map<char, size_t> m;
    for (auto c : s) ++m[c];
    return m;
}

static std::string sorted(std::string s)
{
    std::sort(s.begin(), s.end());
    return s;
}

static bool is_vowel(const char c)
{
    char vowels[] {"aeiou"};
    return std::end(vowels) != std::find(std::begin(vowels), std::end(vowels), c);
}

static size_t vowels(const std::string& s)
{
    return std::count_if(s.begin(), s.end(), is_vowel);
}

#if false
int main()
{
    std::cin.setf(std::ios::skipws);
    std::string input { std::istream_iterator<char> { std::cin }, {} };
    input.pop_back();

    auto hist = std::async(std::launch::deferred, histogram, input); // deferred is analog of lazy
    auto sorted_str = std::async(std::launch::async, sorted, input);
    auto vowel_count = std::async(std::launch::async | std::launch::deferred, vowels, input); // by default

    for (const auto& [c, count] : hist.get()) {
        std::cout << c << ": " << count << std::endl;
    }

    std::cout << "Sorted: " << std::quoted(sorted_str.get()) << std::endl;
    std::cout << "Total vowels: " << vowel_count.get() << std::endl;
}
#endif


/*
ainr$ g++-9 058_mt_std_async.cpp -o a.out -std=c++1z -ltbb -pthread
ainr$ echo "hello my little pony" | ./a.out
 : 3
e: 2
h: 1
i: 1
l: 4
m: 1
n: 1
o: 2
p: 1
t: 2
y: 2
Sorted: "   eehillllmnoopttyy"
Total vowels: 5
*/
