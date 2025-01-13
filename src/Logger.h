#pragma once
/*
    I quickly realized this is terrible / impractical. I will keep this for
    history purposes but this probably won't be used until it's replaced.
*/
enum LogLevel
{
    None = 0,
    Error,
    Warn,
    Debug,
    Trace
};

class Logger
{
private:
    LogLevel lvl;
public:
    Logger();
    Logger(LogLevel init);

    void set_level(LogLevel newLevel);
    void print_level() const;

    void log_err(const char* msg) const;
    void log_warn(const char* msg) const;
    void log_debug(const char* msg) const;
    void log_trace(const char* msg) const;
};

void logger_test();