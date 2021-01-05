#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono_literals;

#if false
int main()
{
    cout << "5s..." << endl;
    this_thread::sleep_for(5s + 300ms);
    cout << "ok" << endl;

    cout << "3s..." << endl;
    this_thread::sleep_until(chrono::high_resolution_clock::now() + 3s);
    cout << "ok" << endl;
}
#endif
