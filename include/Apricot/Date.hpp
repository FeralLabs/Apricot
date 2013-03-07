#include <ctime>

#pragma once

class DateObject
{
public:
	time_t Date;


	Date(short date) {
		this->Date = time(0);
		struct tm tstruct;
		
	}

	const char* c_string() {
		return string;
	}

	~Date() {

	}

	/* data */
};