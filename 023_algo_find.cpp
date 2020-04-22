#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

struct city {
    std::string name;
    unsigned population;
};

bool operator==(const city& a, const city& b)
{
    return a.name == b.name && a.population == b.population;
}

std::ostream& operator << (std::ostream& os, const city& c)
{
    return os << "{" << c.name << ", " << c.population << " }";
}

template <typename C>
static auto print(const C& container)
{
    return  [end_it (end(container))] (const auto &item) {
        if (item != end_it) {
            std::cout << *item << std::endl;
        } else {
            std::cout << "<end>" << std::endl;
        }
    };
}

#if false
int main()
{
    const std::vector<city> c {
        { "Moscow", 200000 },
        { "Spb", 150000 },
        { "Ekb", 100000 },
        { "Omsk", 20000 },
    };

    auto print_city = print(c);

    {
        auto found_ekb = std::find(begin(c), end(c), city { "Ekb", 100000 } );
        print_city(found_ekb);
    }

    {
        auto found_spb = std::find_if(begin(c), end(c), [](const auto& item) {
            return item.name == "Spb";
        });
        print_city(found_spb);
    }
    {
        auto populatiion_more_than = [](unsigned i){
            return [=](const city& item) {
                return item.population > i;
            };
        };
        auto found_large = std::find_if(begin(c), end(c), populatiion_more_than(10000));
        print_city(found_large);
    }
    {
        const std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        auto print_int = print(v);
        bool contains_7 = std::binary_search(begin(v), end(v), 7);
        std::cout << contains_7 << std::endl;

        auto [lower_it, upper_it] = std::equal_range(begin(v), end(v), 7);
        print_int(lower_it);
        print_int(upper_it);

        auto lower = std::lower_bound(begin(v), end(v), 7);
        auto upper = std::upper_bound(begin(v), end(v), 7);
        print_int(lower);
        print_int(upper);
    }
}
#endif
