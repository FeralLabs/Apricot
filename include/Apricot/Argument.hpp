#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

#pragma once


class Argument
{
    public:
        std::string get(std::string what) {
            if(what != "" && what.find(" ") == std::string::npos) {
                return Container[what];
            }
        }

        int getInt(std::string what) {
            return atoi(get(what).c_str());
        }

        Argument(int argc, const char ** argv) {
            std::string Name, Value;
            for(int i = 1; i < argc; i++) {
                if ( argv[i][0] == '-' ) {
                    if ( argv[i][1] == '-' ) {
                        // We have a long argument here
                        Name = std::string(argv[i]);
                        Name.erase(0, 2);
                    } else {
                        Name = std::string(argv[i]);
                        Name.erase(0, 1);
                    }
                }
                
                // if the next argument is not a param...
                if ( argc > i + 1 ) {
                    if ( argv[i + 1][0] == '-') {
                        Value = "1";    
                    } else {
                        Value = std::string(argv[i + 1]);
                        i++;
                    }
                } else {
                    Value = "1";
                }
                    Container[Name] = Value;
            }
             
            ArgumentCount = argc;
        }

    private:
        int ArgumentCount;
        std::string ArgumentString;
        std::map<std::string, std::string> Container;
};
