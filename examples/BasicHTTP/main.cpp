#include <iostream>
#include <Apricot/Log.hpp>
#include <Apricot/Argument.hpp>

int main(int argc, const char *argv[])
{
    Apricot::Argument *Parser = new Apricot::Argument(argc, argv);
    Parser -> setHelpLine ( "Usage: basicHTTP [OPTIONS]\nDoes some cool stuff" );
    Parser -> define ( "p", "port", "Sets the current port for the server");
    Parser -> define ( "t", "threads", "Number of Threads");
    
    if ( Parser -> getBool ("help")) {
        Parser -> printHelp();
        return 0;
    }

    Log::trigger(ERROR) << "Da is "  << Parser -> get("da");
    Log::trigger(ERROR) << "Port is " << Parser -> getInt("port");

    //Parser -> Debug();
    /* code */
    return 0;
}
