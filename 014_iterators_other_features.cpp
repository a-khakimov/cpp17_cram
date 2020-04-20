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

#if true
int main()
{
    reverse();
}
#endif
