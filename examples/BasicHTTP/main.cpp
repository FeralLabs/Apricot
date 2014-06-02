#include <iostream>
#include <Apricot/Apricot.hpp>

using namespace Apricot;

int main(int argc, const char *argv[])
{
    Apricot::Apricot *Application = new Apricot::Apricot ();
    
    Apricot::ParamParser *Parser = Application -> Parser;
    
    Parser -> define ( "hello", "hw", "Says Hi" ) 
           -> define ("da", "da", "daaa");

    Application -> init (argc, argv);

    if ( Parser -> isset ( "hello" ) ) {
        std::cout << Parser -> get ( "hello" );
    }

    /* code */
    return 0;
}
