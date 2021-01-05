#include <iostream>
#include <optional>
#include <exception>

using oint = std::optional<int>;

oint read_int()
{
    int i;
    if (std::cin >> i) {
        return {i};
    }
    return {};
}

oint operator + (oint a, oint b)
{
    if (!a or !b) {
        return {};
    }
    return { *a + *b };
}


oint operator + (oint a, int b)
{
    if (!a) {
        return {};
    }
    return { *a + b };
}

#if false
int main()
{
    std::cout << "Enter 2 integers: ";
#if 0
    {
        auto a = read_int();
        auto b = read_int();
        auto sum = a + b;
        if (sum) {
            std::cout << *a << " + " << *b << " = " << *sum << std::endl;
        } else {
            std::cout << "Fuck you!" << std::endl;
        }
    }
#else
    {
        try {
            auto a = read_int();
            auto b = read_int();
            auto sum = *a + *b;
            std::cout << *a << " + " << *b << " = " << sum << std::endl;
        } catch (const std::bad_optional_access& e) { // Где исключение при некорректных данных???
            std::cout << "bad_optional_access: " << e.what() << std::endl;
        }
    }
#endif
}
#endif
