#include <iostream>
#include "Logger.h"
using std::cerr;
using std::endl;

Logger::Logger() : lvl(Error) {}
Logger::Logger(LogLevel init) : lvl(init) {}

void Logger::set_level(LogLevel newLevel) {
    this->lvl = newLevel;
}
void Logger::print_level() const {
    switch (this->lvl) {
        case None:
            cerr << "Level: no logs" << endl;
            break;
        case Error:
            cerr << "Level: Error" << endl;
            break;
        case Warn:
            cerr << "Level: Warn" << endl;
            break;
        case Debug:
            cerr << "Level: Debug" << endl;
            break;
        case Trace:
            cerr << "Level: Trace" << endl;
            break;
        default:
            cerr << "error: invalid level... somehow-" << endl;
    }
}

void Logger::log_err(const char* msg) const {
    if (this->lvl >= LogLevel::Error) {
        cerr << "ERROR: " << msg << endl;
    }
}
void Logger::log_warn(const char* msg) const {
    if (this->lvl >= LogLevel::Warn) {
        cerr << "WARN: " << msg << endl;
    }
}
void Logger::log_debug(const char* msg) const {
    if (this->lvl >= LogLevel::Debug) {
        cerr << "DEBUG: " << msg << endl;
    }
}
void Logger::log_trace(const char* msg) const {
    if (this->lvl >= LogLevel::Trace) {
        cerr << "TRACE: " << msg << endl;
    }
}