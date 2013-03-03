#include <iostream>
#include <Apricot/Log.hpp>

int main(int argc, char const *argv[])
{
	Log::trigger(logNOTICE) << "da" << true;


	int var = 176;
	Log::trigger(logERROR) << "This is a long text" << var;
	/* code */
	return 0;
}