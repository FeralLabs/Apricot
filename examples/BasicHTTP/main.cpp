#include <iostream>
#include <Apricot/Apricot.hpp>
#include <Apricot/Worker.hpp>

using namespace Apricot;

int main(int argc, const char *argv[])
{
    Apricot::Application *Application = new Apricot::Application ();

    Apricot::ParamParser *Parser = Application -> Parser;

    Parser -> define ( "hello", "hw", "Says Hi" ) 
           -> define ( "port", "p", "Prints the current port status");

    Application -> init (argc, argv);

    RequestPool<Request*> Pool;
    Worker* w1 = new Worker(Pool);
    w1->start();
    
    if ( Parser -> isset ( "hello" ) ) {
        *Application -> Log << "da";
    }

    return 0;
}
