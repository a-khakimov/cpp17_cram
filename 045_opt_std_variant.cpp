#include <iostream>
#include <list>
#include <variant>
#include <string>
#include <variant>
#include <algorithm>

class cat {
    std::string name;
public:
    cat(const std::string& name) : name { name } {
        std::cout << "> cat" << std::endl;
    }
    void meow() const {
        std::cout << name << " says Meow!" << std::endl;
    }
    ~cat() {
        std::cout << "~ cat" << std::endl;
    }
};

class dog {
    std::string name;
public:
    dog(const std::string& name) : name { name } {
        std::cout << "> dog" << std::endl;
    }
    void woof() const {
        std::cout << name << " says Woof!" << std::endl;
    }
    ~dog() {
        std::cout << "~ dog" << std::endl;
    }
};

using animal = std::variant<dog, cat>;

template <typename T>
bool is_type(const animal& a)
{
    return std::holds_alternative<T>(a);
}

struct animal_voice
{
    void operator()(const dog& d) const { d.woof(); }
    void operator()(const cat& c) const { c.meow(); }
};

#if false
int main()
{
    std::list<animal> l { cat {"Jerry"}, dog { "Pluto" }, cat { "Gav" } };

    // способ немного странный
    for (const auto& a : l) {
        switch (a.index()) {
        case 0:
            std::get<dog>(a).woof();
            break;
        case 1:
            std::get<cat>(a).meow();
            break;
        }
    }

    // этот вариант мне нравится больше
    for (const auto& a : l) {
        if (const auto d = std::get_if<dog>(&a); d) {
            d->woof();
        } else if (const auto c = std::get_if<cat>(&a); c) {
            c->meow();
        }
    }

    // а это вообще круть
    for (const auto& a : l) {
        std::visit(animal_voice{}, a);
    }

    std::cout << "cats: " << std::count_if(l.begin(), l.end(), is_type<cat>) << std::endl;
    std::cout << "dogs: " << std::count_if(l.begin(), l.end(), is_type<dog>) << std::endl;

}
#endif
