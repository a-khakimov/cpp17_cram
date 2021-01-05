#include <memory>
#include <iostream>
#include <string>

class Foo {
    std::string s;
    Foo(const std::string& n) : s{n} {
        std::cout << "C:" << s << std::endl;
    }
    ~Foo() {
        std::cout << "D:" << s << std::endl;
    }
public:
    static Foo* create(std::string n) {
        return new Foo { std::move(n) };
    }
    static void destroy(Foo* p) {
        delete p;
    }
};

static std::shared_ptr<Foo> make_shared_foo(std::string s)
{
    return { Foo::create(std::move(s)), Foo::destroy };
}


static std::unique_ptr<Foo, void (*)(Foo*)> make_unique_foo(std::string s)
{
    return { Foo::create(std::move(s)), Foo::destroy };
}

#if false
int main()
{
    auto ps = make_shared_foo("ps");
    auto pu = make_unique_foo("pu");
    std::cout << typeid (ps).name() << std::endl;
    std::cout << typeid (pu).name() << std::endl;
}
#endif
