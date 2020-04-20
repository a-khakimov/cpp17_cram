#include <iostream>
#include <list>
#include <iterator>

void reverse()
{
    std::list l { 1, 2, 3, 4, 5, 6, 7 };
    std::copy(l.rbegin(), l.rend(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    std::copy(std::make_reverse_iterator(std::end(l)),
              std::make_reverse_iterator(std::begin(l)),
              std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
}

void limiter(const char* argv)
{
    class cstring_iterator_sentinel {};

    class cstring_iterator {
        const char* s { nullptr };
    public:
        explicit cstring_iterator(const char* str) : s {str} {}
        char operator*() const { return *s; }
        cstring_iterator& operator++()
        {
            ++s;
            return *this;
        }
        bool operator!=(const cstring_iterator_sentinel) const
        {
            return s != nullptr && *s != '\0';
        }
    };

    class cstring_range {
        const char* s { nullptr };
    public:
        explicit cstring_range(const char* str) : s { str } {}
        cstring_iterator begin() const
        {
            return cstring_iterator {s};
        }
        cstring_iterator_sentinel end() const
        {
            return {};
        }
    };

    for (const auto& c : cstring_range(argv)) {
        std::cout << c;
    }
    std::cout << std::endl;
}

#if true
int main()
{
    reverse();
    limiter("hello");
    limiter("hel \0 lo");
}
#endif
