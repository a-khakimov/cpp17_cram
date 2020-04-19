#include <iostream>
#include <map>

template <typename T>
void print(const T& v)
{
    std::cout << "====== TOP ======" << std::endl;
    for (const auto& [placement, driver] : v) {
        std::cout << placement << " : " << driver << std::endl;
    }
    std::cout << "=================" << std::endl;
}

#if false
int main()
{
    std::map<int, std::string> races_board {
        {1, "Migel"},
        {2, "Mario"},
        {3, "Oleg"},
        {4, "Igor"},
        {5, "Marta"},
        {6, "Batman"},
        {7, "Stark"},
        {8, "James"},
        {9, "Piter"}
    };
    print(races_board);

    {
        auto a (races_board.extract(3));
        auto b (races_board.extract(6));

        if (a.empty()) {
            std::cout << "a empty" << std::endl;
            return 1;
        }
        if (b.empty()) {
            std::cout << "b empty" << std::endl;
            return 1;
        }

        std::cout << "a: " << a.key() << std::endl;
        std::cout << "b: " << b.key() << std::endl;

        std::swap(a.key(), b.key());

        std::cout << "swap.. a <-> b" << std::endl;
        std::cout << "a: " << a.key() << std::endl;
        std::cout << "b: " << b.key() << std::endl;

        races_board.insert(std::move(a));
        print(races_board);
    }

}
#endif
