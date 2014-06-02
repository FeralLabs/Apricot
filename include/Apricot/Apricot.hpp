#include <iostream>
#include <Apricot/Log.hpp>

#ifndef APRICOT_NO_PARAM_PARSE
    #include <Apricot/Argument.hpp>
#endif

#pragma once

namespace Apricot {

    class Apricot {
        public:
            #ifndef APRICOT_NO_PARAM_PARSE
                // define new parser instance
                ParamParser *Parser;
            #endif
            
            Apricot () {
                #ifndef APRICOT_NO_PARAM_PARSE
                    Parser = new ParamParser();
     
                    #ifndef APRICOT_NO_HELP
                    Parser -> define ( "help", "h", "Help" );
                    #endif
                #endif
            }

            void init (int argc, const char ** argv) {
                #ifndef APRICOT_NO_PARAM_PARSE
                    Parser -> doParse (argc, argv);
                    
                    Parser -> setHelpLine ( "Usage: basicHTTP [OPTIONS]" );
                    Parser -> setHelpLine ( std::string ("Usage: ").append(argv[0]).append(" [OPTIONS]\nIs a simple application") );

                    #ifndef APRICOT_NO_HELP
                        if ( Parser -> getBool ( "help" ) ) {
                            Parser -> printHelp();
                            exit(EXIT_SUCCESS);
                        }
                    #endif
                #endif
            }
    };
}
