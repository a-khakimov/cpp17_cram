#include <iostream>
#include <queue>
#include <tuple>
#include <string>

#if false
int main()
{
    using item_type = std::pair<size_t, std::string>;
    std::priority_queue<item_type> todo;

    std::initializer_list<item_type> il {
        {4, "do homework"},
        {2, "watch movie"},
        {0, "read comics"},
        {3, "eat"},
        {5, "coding"},
        {1, "sleep"}
    };

    for (const auto& p : il) {
        todo.push(p);
    }

    while (not todo.empty()) {
        std::cout << todo.top().first << " : " << todo.top().second << std::endl;
        todo.pop();
    }
}
#endif
