#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>

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

#if true
int main()
{
    trie<std::string> t;
    t.insert({ "hi", "how", "are", "you" });
    t.insert({ "hi", "i", "am", "great", "thanks" });
    t.insert({ "what", "are", "you", "doing" });
    t.insert({ "i", "am", "watching", "a", "movie" });
    t.insert({ "hi", "who", "are", "you" });
    t.insert({ "what", "the", "fuck" });
    t.insert({ "fuck", "you" });
    t.insert({ "suck", "my", "dick" });
    t.insert({ "are", "you", "from" });

    std::cout << "--- tree ---" << std::endl;
    t.print();

    std::cout << "--- hi ---" << std::endl;
    if (auto st = t.subtrie(std::initializer_list<std::string>{"hi"}); st) {
        st->get().print();
    }

    std::cout << "--- are ---" << std::endl;
    if (auto st = t.subtrie(std::initializer_list<std::string>{"are"}); st) {
        st->get().print();
    }

    std::cout << "--- what ---" << std::endl;
    if (auto st = t.subtrie(std::initializer_list<std::string>{"what"}); st) {
        st->get().print();
    }

    std::cout << "--- you ---" << std::endl;
    if (auto st = t.subtrie(std::initializer_list<std::string>{"you"}); st) {
        st->get().print();
    }
}
#endif
