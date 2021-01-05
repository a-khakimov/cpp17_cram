#include <iostream>
#include <any>
#include <list>
#include <iterator>

using namespace std;

using int_list = list<int>;

void print_anything(const std::any& a)
{
    if (not a.has_value()) {
        cout << "Nothing." << endl;
    } else if (a.type() == typeid (string)) {
        cout << "String: " << any_cast<const string&>(a) << endl;
    } else if (a.type() == typeid (int)) {
        cout << "Int: " << any_cast<const int>(a) << endl;
    } else if (a.type() == typeid (int_list)) {
        const auto& l (any_cast<const list<int> >(a));
        cout << "List<Int>: ";
        copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    } else {
        cout << "Hui znaet chto eto za type" << endl;
    }
}


#if false
int main()
{
    print_anything({});
    print_anything("abs"s);
    print_anything(123);
    print_anything(int_list{1, 2, 3});
    print_anything(3.14);
}
#endif
