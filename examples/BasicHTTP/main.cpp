#include <iostream>
#include <Apricot/Log.hpp>

int main(int argc, char const *argv[])
{
	Log::trigger(NOTICE) << "da";

	Log::trigger(ERROR) << "This is a long text";
	/* code */
	return 0;
}