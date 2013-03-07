#include <iostream>

#pragma once

#define ERROR_TEXT  "[ ERROR ] "
#define NOTICE_TEXT "          "


enum TLogLevel {ERROR, NOTICE, WARNING, DEBUG};

class Log
{
public:
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
	Log& operator<<(T in)
	{
		if(hasArgs == false)
			std::cout << "[*] ";

		std::cout << in;
		
		hasArgs = true;

		return *this;
	}

private:
	Log() : type(NOTICE), hasArgs(false) {

	};
	Log(Log const&);
	void operator=(Log const&);
};
