#pragma once
#include <chrono>
#include <sstream>

/*
    Everything done on 1/15/25 follows The Cherno's tutorial to start:
    https://youtu.be/YG4jexlSAjc?si=q7HEBsAzfKTR4AH5
*/
class Timer
{
public:
    Timer();
    ~Timer();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};