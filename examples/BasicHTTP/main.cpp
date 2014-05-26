#include <iostream>
#include <Apricot/Log.hpp>
#include <Apricot/Argument.hpp>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    Argument *Parser = new Argument(argc, argv);
    Log::trigger(ERROR) << "Da is "  << Parser -> get("da");
    Log::trigger(ERROR) << "Port is " << Parser -> getInt("port");
    /* code */
    return 0;
}
