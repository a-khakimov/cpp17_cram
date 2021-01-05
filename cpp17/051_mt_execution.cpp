#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <execution>

/* RESULTS
-------------------------------
 * with std::execution::par = 16,551s
-------------------------------
$ time ./a.out
generate... ok
sort... ok
reverce... ok
count odds... 49855949

real	0m16,551s
user	2m6,199s
sys	0m0,519s
-------------------------------
 * without std::execution::par = 45,691s
-------------------------------
$ time ./a.out
generate... ok
sort... ok
reverce... ok
count odds... 50002619

real	0m45,691s
user	0m45,594s
sys	0m0,096s
-------------------------------
*/

#if false
int main()
{
    std::vector<int> v (100000000);
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis(0, 1000000);
    auto rand_num = [=]() mutable {
        return dis(gen);
    };

    std::cout << "generate... ";
    std::generate(std::execution::par, v.begin(), v.end(), rand_num);
    std::cout << "ok" << std::endl;

    std::cout << "sort... ";
    std::sort(std::execution::par, v.begin(), v.end());
    std::cout << "ok" << std::endl;

    std::cout << "reverce... ";
    std::reverse(std::execution::par, v.begin(), v.end());
    std::cout << "ok" << std::endl;

    auto odd = [](int n) -> bool {
        return n % 2;
    };

    std::cout << "count odds... ";
    auto odds = std::count_if(std::execution::par, v.begin(), v.end(), odd);
    std::cout << 100.0 * odds / v.size() << "%" << std::endl;
}
#endif
