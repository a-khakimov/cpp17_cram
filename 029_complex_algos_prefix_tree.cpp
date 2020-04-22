#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

template <typename T>
class trie {
    std::map<T, trie> tries;
public:
    template<typename It>
    void insert(It it, It end_it) {
        if (it == end_it) { return; }
        tries[*it].insert(std::next(it), end_it);
    }

    template <typename C>
    void insert(const C& container) {
        insert(container.begin(), container.end());
    }

    void insert(const std::initializer_list<T>& il) {
        insert(il.begin(), il.end());
    }

    void print(std::vector<T>& v) const {
        if (tries.empty()) {
            std::copy(v.begin(), v.end(), std::ostream_iterator<T>{std::cout, " "});
            std::cout << std::endl;
        }
        for (const auto& p : tries) {
            v.push_back(p.first);
            p.second.print(v);
            v.pop_back();
        }
    }

    void print() const {
        std::vector<T> v;
        print(v);
    }

    template<typename It>
    std::optional<std::reference_wrapper<const trie>> subtrie(It it, It end_it) const {
        if (it == end_it) {
            return std::ref(*this);
        }
        auto found = tries.find(*it);
        if (found == tries.end()) {
            return {};
        }
        return found->second.subtrie(std::next(it), end_it);
    }

    template <typename C>
    auto subtrie(const C& container) {
        return subtrie(container.begin(), container.end());
    }

};

static void promt()
{
    std::cout << "Next input please: ";
}

/* g++-8 029_complex_algos_prefix_tree.cpp -o a.out -std=c++17 */

#if true
int main()
{
    trie<std::string> t;

    std::fstream infile { "db.txt" };
    for (std::string line; std::getline(infile, line);) {
        std::istringstream iss { line };
        t.insert(std::istream_iterator<std::string> { iss }, { });
    }

    promt();

    for (std::string line; std::getline(std::cin, line);) {
        std::istringstream iss { line };
        if (auto st = t.subtrie(std::istream_iterator<std::string>{iss}, {}); st) {
            st->get().print();
        } else {
            std::cout << "No suggetions found" << std::endl;
        }
        std::cout << "----------------------" << std::endl;
        promt();
    }
}
#endif
