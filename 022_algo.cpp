#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <iterator>
#include <algorithm>

namespace std {
ostream& operator << (ostream& os, const pair<int, string> p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}
}

#if true
int main()
{
    {   // copy
        std::cout << "-- copy --" << std::endl;
        std::vector<std::pair<int, std::string>> v {
            { 1, "one"   },
            { 2, "two"   },
            { 3, "three" },
            { 4, "four"  },
            { 5, "five"  }
        };
        std::map<int, std::string> m;
        std::copy_n(begin(v), 3, std::inserter(m, begin(m)));
        // std::copy(begin(v), end(v), std::inserter(m, begin(m)));
        auto shell_it ( std::ostream_iterator<std::pair<int, std::string>>{ std::cout, ", " } );
        std::copy(begin(m), end(m), shell_it);
        std::cout << std::endl;
    }

    {   // move
        std::cout << "-- move -- " << std::endl;
        std::vector<std::pair<int, std::string>> v {
            { 1, "one"   },
            { 2, "two"   },
            { 3, "three" },
            { 4, "four"  },
            { 5, "five"  }
        };
        std::map<int, std::string> m;
        std::move(begin(v), end(v), std::inserter(m, begin(m)));
        auto shell_it ( std::ostream_iterator<std::pair<int, std::string>>{ std::cout, ", " } );
        std::copy(begin(v), end(v), shell_it); // should be empty
        std::cout << std::endl;
        std::copy(begin(m), end(m), shell_it);
        std::cout << std::endl;
    }

}
#endif
