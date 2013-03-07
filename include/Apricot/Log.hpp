#include <iostream>

#pragma once

#define ERROR_TEXT  "[ ERROR ] "
#define NOTICE_TEXT "          "

enum TLogLevel { logERROR, logNOTICE, logWARNING, logDEBUG };

class Log
{
public:
	short type;
	bool hasArgs;

	static Log& trigger(short aType = logNOTICE)
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
		switch(type) {
			case logERROR:
				if(hasArgs == false) {
					std::cerr << "[ date ]" <<  ERROR_TEXT;
				}

				std::cerr << in;
			break;
			default:
				if(hasArgs == false) {
					std::cout << "[ date ]" << NOTICE_TEXT;
				}
				std::cout << in;
		}
		
		hasArgs = true;

		return *this;
	}

private:
	Log() : type(logNOTICE), hasArgs(false) {};
	Log(Log const&);
	void operator=(Log const&);
};
