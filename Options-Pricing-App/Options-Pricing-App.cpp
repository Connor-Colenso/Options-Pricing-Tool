#include <iostream>
#include "../Options-Pricing-Library/Options-Pricing-Lib.h"
#include "../Options-Pricing-Library/Brownian_Motion.cpp"
#include "../Options-Pricing-Library/Monte_Carlo.cpp"
#include "../Options-Pricing-Library/Payoff.cpp"

#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main() {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    u

    auto time_1 = high_resolution_clock::now();

    uint64_t number_of_elements = 1000 * 1000 * 1000;
    uint64_t step = number_of_elements / number_of_threads;
    std::vector<std::thread> threads;
    std::vector<uint64_t> partial_sums(number_of_threads);

    for (uint64_t i = 0; i < number_of_threads; i++) {
        threads.push_back(std::thread([i, &partial_sums, step] {
            for (uint64_t j = i * step; j < (i + 1) * step; j++) {
                partial_sums[i] += j;
            }
            }));
    }

    for (std::thread& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    uint64_t total = std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));

    auto time_2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = time_2 - time_1;

    std::cout << ms_double.count() << "ms ";

    std::cout << "Thread count: " << number_of_threads << " Total: " << total << std::endl;
            auto time_1 = high_resolution_clock::now();

    uint64_t number_of_elements = 1000 * 1000 * 1000;
    uint64_t step = number_of_elements / number_of_threads;
    std::vector<std::thread> threads;
    std::vector<uint64_t> partial_sums(number_of_threads);

    for (uint64_t i = 0; i < number_of_threads; i++) {
        threads.push_back(std::thread([i, &partial_sums, step] {
            for (uint64_t j = i * step; j < (i + 1) * step; j++) {
                partial_sums[i] += j;
            }
            }));
    }

    for (std::thread& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    uint64_t total = std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));

    auto time_2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = time_2 - time_1;

    std::cout << ms_double.count() << "ms ";

    std::cout << "Thread count: " << number_of_threads << " Total: " << total << std::endl;


    return 0;
}
