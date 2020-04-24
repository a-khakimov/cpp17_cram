#include <iostream>
#include <queue>
#include <tuple>
#include <thread>
#include <condition_variable>
#include <sstream>
#include <iomanip>

// TODO: разобраться с этим досконально

using namespace std::chrono_literals;

struct pcout : public std::stringstream {
    static inline std::mutex cout_mutex;
    ~pcout() {
        std::lock_guard<std::mutex> l { cout_mutex };
        std::cout << rdbuf();
        std::cout.flush();
    }
};

#if true
int main()
{
    std::queue<size_t> q;
    std::mutex mut;
    //bool production_stopped = false;
    std::condition_variable go_produce;
    std::condition_variable go_consume;

    auto producer = [&](const size_t id, const size_t stock) {
        for (size_t i = 0; ; ++i) {
            std::unique_lock<std::mutex> lock(mut);
            go_produce.wait(lock, [&] {
                return q.size() < stock;
            });
            q.push(id * 100 + i);
            pcout{} << "Producer " << id << " --> item " << std::setw(3) << q.back() << std::endl;
            go_consume.notify_all();
            std::this_thread::sleep_for(80ms);
        }
        pcout{} << "EXIT: Producer " << id << std::endl;
    };

    auto consumer = [&](const size_t id) {
        while (/*not production_stopped or not q.empty()*/true) {
            std::unique_lock<std::mutex> lock (mut);
            if (go_consume.wait_for(lock, 1s, [&] { return not q.empty(); })) {
                pcout {} << "               item " << std::setw(3) << q.front() << " -- > Consumer " << id << std::endl;
                q.pop();
            }
            go_produce.notify_all();
            std::this_thread::sleep_for(1ms);
        }
        pcout{} << "EXIT: Consumer " << id << std::endl;
    };

    std::vector<std::thread> workers;
    std::vector<std::thread> consumers;

    for (size_t i = 0; i < 9; ++i) {
        workers.emplace_back(producer, i, 20);
    }

    for (size_t i = 0; i < 20; ++i) {
        consumers.emplace_back(consumer, i);
    }

    for (auto& t : workers) {
        t.join();
    }

    //production_stopped = true;

    for (auto& t : consumers) {
        t.join();
    }

    std::cout << "finished!" <<std::endl;
}
#endif
