#include <memory>
#include <iostream>

struct dick {
    size_t length;
    size_t width;
    dick(size_t l, size_t w)
        : length { (l) }, width { w } {
        std::cout << "Dick: " << length << ", " << width << std::endl;
    }
    dick(dick&& d)
        : length { (d.length) }, width { d.width } {
        std::cout << "Dick move: " << length << ", " << width << std::endl;
    }
    dick& operator = (dick& o) {
        length = o.length;
        width = o.width;
        return *this;
    }
    ~dick() {
        std::cout << "Dick d: " << length << ", " << width << std::endl;
    }
};

std::ostream& operator << (std::ostream& os, const dick& d)
{
    return os << " { " << d.length << ", " << d.width << " }";
}

struct person {
    std::string name;
    size_t age;
    dick my_d;

    person(std::string n, size_t a, dick d)
        : name { std::move(n) }, age { a }, my_d { std::move(d) } {
        std::cout << "C: " << name << std::endl;
    }
    ~person() {
        std::cout << "D: " << name << std::endl;
    }
};

#if true
int main()
{
    std::shared_ptr<std::string> sh_name;
    std::shared_ptr<size_t> sh_age;
    std::shared_ptr<dick> sh_dick;

    std::cout << " - " << std::endl;

    {
        auto sh_person = std::make_shared<person>("Rick", 60, dick(20, 5));
        sh_name = std::shared_ptr<std::string>(sh_person, &sh_person->name);
        sh_age = std::shared_ptr<size_t>(sh_person, &sh_person->age);
        sh_dick = std::shared_ptr<dick>(sh_person, &sh_person->my_d);
    }

    std::cout << " - " << std::endl;
    std::cout << *sh_name << " " << *sh_age << *sh_dick << std::endl;
}
#endif
