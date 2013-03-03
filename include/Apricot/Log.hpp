#include <string>
#include <iostream>

#ifndef __APRICOT_LOG_H__
#define __APRICOT_LOG_H__

class Log
{
public:
	static Log& getInstance()
	{
		static Log instance;
		return instance;
	}
	void doStuff() {

	};
private:
	Log() {}
	Log(Log const&);
	void operator=(Log const&);
};

#endif