#include <iostream>

#pragma once

#define REDFG "\033[31m"
#define YELLOWFG "\033[33m"
#define BLACKFG "\033[30m"
#define RESETFG "\033[0m"

#define ERROR_TEXT      "[  ERROR   ]\t"
#define WARNING_TEXT    "[  WARNING ]\t"
#define NOTICE_TEXT     "[  NOTICE  ]\t"

enum TLogLevel {DEBUG, NOTICE, WARNING, ERROR};
class Log
{
public:
        short logLevel;
	short type;
	bool hasArgs;

	static Log& trigger(short aType = NOTICE)
	{
		static Log instance;
		instance.type = aType;

		if(instance.hasArgs == true)
			std::cout << std::endl;

		instance.hasArgs = false;

		return instance;
	}

	template<typename T>
	Log& operator<<(const T& in)
	{
		if(hasArgs == false && logLevel <= type) {
		    switch(type) {
                        case ERROR:    
                            std::cout << REDFG << ERROR_TEXT << RESETFG;
                        break;
                        
                        case WARNING:
                            std::cout << YELLOWFG << ERROR_TEXT << RESETFG;
                        break;

                        case NOTICE:
                            std::cout << BLACKFG << NOTICE_TEXT << RESETFG;
                        break;
                    }
                }
                
                if (logLevel <= type)
                    std::cout << in;
                
		hasArgs = true;

		return *this;
	}

private:
	Log() : type(NOTICE), hasArgs(false) {
            logLevel = ERROR;
	};
	Log(Log const&);
	void operator=(Log const&);
};
