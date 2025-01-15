#include <iostream>
#include <fstream>
#include "Timer.h"

Timer::Timer() {
    m_start = std::chrono::high_resolution_clock::now();
}
Timer::~Timer() {
    using namespace std::chrono;

    auto end = time_point_cast<microseconds>(high_resolution_clock::now())
        .time_since_epoch()
        .count();
    auto start = time_point_cast<microseconds>(m_start)
        .time_since_epoch()
        .count();
    auto duration = end - start;

    //std::ofstream file("???.txt", std::ios_base::app);

    std::cerr << "Executed in " << duration << " microseconds "
        << "(" << duration * 0.001 << " milliseconds)."
        << std::endl;

    //file << duration << std::endl;
    //file.close();
}