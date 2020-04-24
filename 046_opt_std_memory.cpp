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

void some_func_shared_ptr(const std::shared_ptr<Foo> foo)
{
    if (!foo) {
        return;
    }

    std::cout << "use_count=" << foo.use_count() << " for ";
    foo->foo();
}

void weak_ptr_info(const std::weak_ptr<Foo>& p)
{
    std::cout << "expired: " << p.expired() << ", use_count: " << p.use_count() << " > ";
    if (const auto sp = p.lock(); sp) {
        sp->foo();
    } else {
        std::cout << "null" << std::endl;
    }
}

#if false
int main()
{
    std::cout << "=== unique_ptr ===" << std::endl;
    {
        std::unique_ptr<Foo> foo1 { new Foo("foo1") };
        auto foo2 { std::make_unique<Foo>("foo2") };
        //some_func_unique_ptr(foo1); // fail
        foo1->foo();
        some_func_unique_ptr(std::move(foo1));
        some_func_unique_ptr(std::make_unique<Foo>("foo3"));
        //foo1->foo(); // bad
    }
    std::cout << "=== shared_ptr ===" << std::endl;
    {
        std::shared_ptr<Foo> foo1 { new Foo("foo1") };
        some_func_shared_ptr(foo1);
        some_func_shared_ptr(std::move(foo1));
        //foo1->foo(); // bad
        auto foo2 { std::make_shared<Foo>("foo2") };
        auto foo2_copy0 = foo2;
        {
            auto foo2_copy2 = foo2;
            some_func_shared_ptr(foo2_copy2);
        }
        auto foo2_copy1 = foo2;
        some_func_shared_ptr(foo2_copy1);
    }
    std::cout << "=== weak_ptr ===" << std::endl;
    {
        std::weak_ptr<Foo> weak_foo1;
        weak_ptr_info(weak_foo1);
        {
            auto shared_foo = std::make_shared<Foo>("shared_foo");
            weak_foo1 = shared_foo;
            weak_ptr_info(weak_foo1);
        }
        weak_ptr_info(weak_foo1);
    }
}
#endif
