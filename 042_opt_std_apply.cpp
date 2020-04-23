#include <iostream>
#include <string>
#include <functional>

static void print_student(const size_t id, const std::string& name, const double gpa)
{
    std::cout << id << "\t" << name << "\t" << gpa << std::endl;
}

#if false
int main()
{
    using student = std::tuple<size_t, std::string, double>;
    {
        student john { 123, "John", 3.1 };
        const auto& [id, name, gpa] = john;
        print_student(id, name, gpa);
    }
    {
        auto students = {
            std::make_tuple(1, std::string{"John"}, 3.1),
            std::make_tuple(2, std::string{"Bill"}, 4.1),
            std::make_tuple(3, std::string{"Jerry"}, 5.1)
        };

        for (const auto& [id, name, gpa] : students) {
            print_student(id, name, gpa);
        }

        // better
        for (const auto& student : students) {
            std::apply(print_student, student);
        }
    }
}
#endif
