#include <iostream>
#include <functional>
#include <list>
#include <map>


#if 1
int main()
{
    struct billionaire {
        std::string name;
        double dollars;
        std::string country;
    };

    std::list<billionaire> billionaires {
        {"Bill", 565.5, "USA"},
        {"Hulio", 465.9, "Spain"},
        {"Putin", 365, "Russia"},
        {"Tass", 235, "Mexico"},
        {"Li Po", 135.2, "China"},
        {"Johny", 65.4, "USA"}
    };

    std::map<std::string, std::pair<const billionaire, size_t>> m;
    for (const auto &b : billionaires) {
        auto [iterator, success] = m.try_emplace(b.country, b, 1);
        if (not success) {
            iterator->second.second += 1;
        }
    }

    for (const auto& [key, value] : m) {
        const auto& [b, count] = value;
        std::cout << b.country << " : " << count
                << " billionares. Richest is "
                << b.name << " with " << b.dollars
                << " B$" << std::endl;
    }
}
#endif
