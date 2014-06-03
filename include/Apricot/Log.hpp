#include <iostream>

#pragma once

enum TLogLevel {DEBUG, NOTICE, WARNING, ERROR};

namespace Apricot {
    class Logger {
        public:
            short state;
            
            Logger& doLog(short level) {
                state = level;
                return *this;
            }
            
            template <typename T>
            Logger& operator<<(const T& in) {
                std::cout << in;
                return *this;
            }
    };
}
