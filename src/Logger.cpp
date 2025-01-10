#include <iostream>
#include "Logger.h"
using std::cout;
using std::endl;

Logger::Logger(LogLevel init)
    : lvl(init)
{}

void Logger::set_level(LogLevel newLevel) {
    this->lvl = newLevel;
}
void Logger::print_level() const {
    switch (this->lvl) {
        case None:
            cout << "Level: no logs" << endl;
            break;
        case Error:
            cout << "Level: Error" << endl;
            break;
        case Warn:
            cout << "Level: Warn" << endl;
            break;
        case Debug:
            cout << "Level: Debug" << endl;
            break;
        case Trace:
            cout << "Level: Trace" << endl;
            break;
        default:
            cout << "error: invalid level... somehow-" << endl;
    }
}

void Logger::log_err(const char* msg) const {
    if (this->lvl >= LogLevel::Error) {
        cout << "ERROR: " << msg << endl;
    }
}
void Logger::log_warn(const char* msg) const {
    if (this->lvl >= LogLevel::Warn) {
        cout << "WARN: " << msg << endl;
    }
}
void Logger::log_debug(const char* msg) const {
    if (this->lvl >= LogLevel::Debug) {
        cout << "DEBUG: " << msg << endl;
    }
}
void Logger::log_trace(const char* msg) const {
    if (this->lvl >= LogLevel::Trace) {
        cout << "TRACE: " << msg << endl;
    }
}