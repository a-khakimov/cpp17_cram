#include <iostream>
#include <queue>
#include <tuple>
#include <thread>
#include <condition_variable>

using namespace std::chrono_literals;

#if false
int main()
{
    std::mutex mut;
    std::queue<size_t> q;
    std::condition_variable cv;

    auto producer = [&mut, &cv, &q](const size_t items) {
        while (true) {
            for (size_t i = 0; i < items; ++i) {
                std::this_thread::sleep_for(500ms);
                std::lock_guard<std::mutex> lk { mut };
                q.push(i);
                std::cout << "-> " << i << std::endl;
                cv.notify_all();
            }
        }
    };

    auto consumer = [&mut, &cv, &q]() {
        while (true) {
            std::unique_lock<std::mutex> l { mut };
            cv.wait(l, [&q] {
                return not q.empty();
            });

            while (not q.empty()) {
                std::cout << "<- " << q.front() << std::endl;
                q.pop();
            }
        }
    };

    std::thread t1 { producer, 10 };
    std::thread t2 { consumer };
    t1.join();
    t2.join();

    std::cout << "finished!" <<std::endl;
}
#endif
