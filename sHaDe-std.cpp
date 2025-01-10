// sHaDe-std.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "src/Logger.h"

void logger_test();

int main()
{
    logger_test();
}

void logger_test() {
    Logger l(None);

    for (int i = Error; i <= Trace+1; i++) {
        l.print_level();

        l.log_err("Err msg");
        l.log_warn("Warn msg");
        l.log_debug("Debug msg");
        l.log_trace("Trace msg");
        std::cout << std::endl;

        l.set_level(static_cast<LogLevel>(i));
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
