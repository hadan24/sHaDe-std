#pragma once
enum LogLevel {
    None = 0,
    Error,
    Warn,
    Debug,
    Trace
};

class Logger {
private:
    LogLevel lvl = Error;
public:
    Logger(LogLevel init);

    void set_level(LogLevel newLevel);
    void print_level() const;

    void log_err(const char* msg) const;
    void log_warn(const char* msg) const;
    void log_debug(const char* msg) const;
    void log_trace(const char* msg) const;
};