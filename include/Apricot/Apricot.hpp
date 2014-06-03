#include <iostream>
#include <Apricot/Log.hpp>
#include <functional>

#ifndef APRICOT_NO_PARAM_PARSE
    #include <Apricot/Argument.hpp>
#endif

#include <Apricot/Log.hpp>

#pragma once

namespace Apricot {

    class Application {
        public:
            #ifndef APRICOT_NO_PARAM_PARSE
                // define new parser instance
                ParamParser *Parser;
            #endif
                Apricot::Logger *Log;
           

            Application () {
                Log = new Apricot::Logger();
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
                    
                    Parser -> setUsageLine (std::string("Usage: ").append(argv[0]).append(" [OPTIONS]\n"));
                    Parser -> setHelpLine ("Is a simple application");

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
