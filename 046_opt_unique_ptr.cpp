#include <iostream>
#include <memory>

class Foo {
    std::string _s;
public:
    Foo(std::string s) : _s(std::move(s)) {
        std::cout << "> Foo " << _s << std::endl;
    }
    void foo() {
        std::cout << "= Foo " << _s << std::endl;
    }
    ~Foo() {
        std::cout << "< Foo " << _s << std::endl;
    }

};

void some_func_unique_ptr(const std::unique_ptr<Foo> foo)
{
    if (!foo) {
        return;
    }

    foo->foo();
}

#if true
int main()
{
    {
        std::unique_ptr<Foo> foo1 { new Foo("foo1") };
        auto foo2 { std::make_unique<Foo>("foo2") };
        //some_func_unique_ptr(foo1); // fail
        foo1->foo();
        some_func_unique_ptr(std::move(foo1));
        some_func_unique_ptr(std::make_unique<Foo>("foo3"));
        //foo1->foo(); // bad
    }
}
#endif
