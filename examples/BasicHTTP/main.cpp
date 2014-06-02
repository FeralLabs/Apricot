#include <iostream>
#include <Apricot/Log.hpp>
#include <Apricot/Argument.hpp>

using namespace Apricot;

int main(int argc, const char *argv[])
{
    ParamParser *Parser = new Apricot::ParamParser();
    Parser -> setHelpLine ( "Usage: basicHTTP [OPTIONS]\nDoes some cool stuff" );
    Parser -> define ( "port", "p", "Sets the current port for the server");
    Parser -> define ( "threads", "t", "Number of Threads");
    Parser -> define ( "help", "h", "Help");
    Parser -> doParse(argc, argv);
    
    if ( Parser -> getBool ("help")) {
        Parser -> printHelp();
        return 0;
    }

    Log::trigger(ERROR) << "Threads is "  << Parser -> get("threads");
    Log::trigger(ERROR) << "Port is " << Parser -> getInt("port");

    /* code */
    return 0;
}
