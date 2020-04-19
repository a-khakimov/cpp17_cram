#include <iostream>
#include <map>
#include <string>

#if false
int main()
{
    std::map<std::string, std::size_t> m {{"b", 1}, {"v", 4}, {"g", 10}, {"t", 3}};
    auto insert_it (std::end(m));

    // correct hint
    for (const auto &s : {"z", "y", "x", "w"}) {
        insert_it = m.insert(insert_it, {s, 100});
    }

    // incorrect hint
    for (const auto &s : {"a"}) {
        insert_it = m.insert(m.end(), {s, 200});
    }


    for (const auto& [key, value] : m) {
        std::cout << key << " : " << value << std::endl;
    }
}
#endif
