#include <iostream>
#include <vector>
#include <numeric>
#include <valarray>

class zip_iterator {
    using it_type = std::vector<double>::iterator;
    it_type it1;
    it_type it2;
public:
    zip_iterator(it_type i1, it_type i2) : it1 {i1}, it2 {i2} {}
    zip_iterator& operator++()
    {
        ++it1;
        ++it2;
        return *this;
    }
    bool operator != (const zip_iterator& o) const
    {
        return it1 != o.it1 && it2 != o.it2;
    }
    bool operator == (const zip_iterator& o) const
    {
        return not operator != (o);
    }
    std::pair<double, double> operator*() const
    {
        return { *it1, *it2 };
    }
};

namespace std {
template <>
struct iterator_traits<zip_iterator> {
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::pair<double, double>;
    using difference_type = long int;
};
}

class zipper {
    using vec_type = std::vector<double>;
    vec_type& v1;
    vec_type& v2;
public:
    zipper(vec_type& va, vec_type& vb) : v1{va}, v2{vb} {}
    zip_iterator begin() const
    {
        return { std::begin(v1), std::begin(v2) };
    }
    zip_iterator end() const
    {
        return { std::end(v1), std::end(v2) };
    }
};

#if false
int main()
{
    {
        std::vector<double> a { 1.0, 2.0, 3.0 };
        std::vector<double> b { 1.0, 3.0, 5.0 };
        zipper zipped { a, b };
        const auto add_product ([](double sum, const auto& p){
            return sum + p.first * p.second;
        });
        const auto dot_product = std::accumulate(std::begin(zipped), std::end(zipped), 0.0, add_product);
        std::cout << dot_product << std::endl;
    }
    {   // simple way - use valarray
        std::valarray<double> a { 1.0, 2.0, 3.0 };
        std::valarray<double> b { 1.0, 3.0, 5.0 };
        std::cout << (a * b).sum() << std::endl;

    }
}
#endif
