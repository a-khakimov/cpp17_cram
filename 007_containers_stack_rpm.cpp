#include <iostream>
#include <stack>
#include <iterator>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <cmath>

template <typename IT>
double evaluate_rpn(IT it, IT end)
{
    std::stack<double> val_stack;

    auto pop_stack([&](){
       auto r (val_stack.top());
       val_stack.pop();
       return r;
    });

    std::map<std::string, double (*)(double, double)> ops {
        {"+", [](double a, double b) { return a + b; }},
        {"-", [](double a, double b) { return a - b; }},
        {"*", [](double a, double b) { return a * b; }},
        {"/", [](double a, double b) { return a / b; }},
        {"^", [](double a, double b) { return pow(a, b); }},
        {"%", [](double a, double b) { return fmod(a, b); }}
    };

    for (; it != end; ++it) {
        std::stringstream ss {*it};

        if (double val; ss >> val) {
            val_stack.push(val);
        } else {
            const auto r { pop_stack() };
            const auto l { pop_stack() };

            try {
                const auto& op (ops.at(*it));
                const double result { op(l, r) };
                val_stack.push(result);
                std::cout << l << " " << *it << " " << r << " = " << result << std::endl;
            } catch (const std::out_of_range&) {
                throw std::invalid_argument(*it);
            }
        }
    }
    return val_stack.top();
}

// TODO: с помощью этого примера можно решить кату
//        https://www.codewars.com/kata/59eb1e4a0863c7ff7e000008/train/cpp

#if false
int main()
{
    try {
        std::stringstream s { "1 2 + 3 +" };
        std::cout << s.str() << std::endl;
        std::cout << evaluate_rpn(std::istream_iterator<std::string>{s}, {}) << std::endl;
        // std::cout << evaluate_rpn(std::istream_iterator<std::string>{std::cin}, {}) << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << "Invalid operator: " << e.what() << std::endl;
    }
}
#endif

