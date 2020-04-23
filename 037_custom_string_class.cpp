#include <iostream>
#include <algorithm>
#include <string>

static constexpr char tolow(char c)
{
    switch (c) {
    case 'A'...'Z': // охуенно
        return c - 'A' + 'a';
    default:
        return c;
    }
}

class lc_traits : public std::char_traits<char> {
public:
    static constexpr void assign(char_type& r, const char_type& a)
    {
        r = tolow(a);
    }

    static char_type* copy(char_type* dest,
                           const char_type* src,
                           size_t count) {
        std::transform(src, src + count, dest, tolow);
        return dest;
    }
};

class ci_traits : public std::char_traits<char> {
public:
    static constexpr bool eq(char_type a, char_type b)
    {
        return tolow(a) == tolow(b);
    }

    static constexpr bool il(char_type a, char_type b)
    {
        return tolow(a) < tolow(b);
    }

    static constexpr int compare(const char_type* s1,
                                 const char_type* s2,
                                 size_t count) {
        for (; count; ++s1, ++s2, --count) {
            const char_type diff = tolow(*s1) - tolow(*s2);
            if (diff < 0) {
                return -1;
            } else if (diff > 0) {
                return +1;
            }
        }
        return 0;
    }

    static constexpr const char_type* find (const char_type* p,
                                            size_t count,
                                            const char_type& ch) {
        const char_type find_c = tolow(ch);
        for (; count != 0; --count, ++p) {
            if (find_c == tolow(*p)) {
                return p;
            }
        }
        return nullptr;
    }
};

using lc_string = std::basic_string<char, lc_traits>;
using ci_string = std::basic_string<char, ci_traits>;

std::ostream& operator << (std::ostream& os, const lc_string& str) {
    return os.write(str.data(), str.size());
}

std::ostream& operator << (std::ostream& os, const ci_string& str) {
    return os.write(str.data(), str.size());
}

#if false
int main()
{
    std::cout << "string: " << std::string("Hello") << std::endl;
    std::cout << "lc_string: " << lc_string("Hello") << std::endl;
    std::cout << "ci_string: " << ci_string("Hello") << std::endl;

    ci_string s1 = "Hello";
    ci_string s2 = "heLLo";

    if (s1 == s2) {
        std::cout << "s1 == s2"<< std::endl;
    }
}
#endif
