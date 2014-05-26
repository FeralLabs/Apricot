#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>

#pragma once

namespace Apricot {
    class ApricotParam {
        public:
            std::string LongName, ShortName, Description;
            
            ApricotParam(
                std::string LongName, 
                std::string ShortName, 
                std::string Description
            ) {
                this->LongName = LongName; 
                this->ShortName = ShortName;
                this->Description = Description;
            }

            void doPrintHelp() {
                std::cout << "-" << this->LongName << ",  --" << this->ShortName << "\t\t" << this->Description << std::endl;
            }


    };
    
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

            bool getBool(std::string what) {
                return getInt(what);
            }

            void set(std::string what, std::string with) {
                Container [ what ] = with;
            }

            void define(std::string LongName, std::string ShortName, std::string Description) {
                ApricotParamContainer.push_back(new ApricotParam(LongName, ShortName, Description));
            }

            void printHelp() {
                std::cout << HelpLine << std::endl << std::endl;
                for(std::vector<ApricotParam*>::iterator It = ApricotParamContainer.begin(); 
                    It != ApricotParamContainer.end(); ++It) {
                    (**It).doPrintHelp();
                }
            }

            void Debug() {
                for(std::map<std::string, std::string>::iterator It = Container.begin(); It != Container.end(); It++) {
                    std::cout << std::endl << It->first << " is " << It->second;
                }
            }
            
            void doParse(int argc, const char ** argv) {
                std::string Name, Value;
                for(int i = 1; i < argc; i++) {
                    Name = std::string(argv[i]);
                    if ( argv[i][0] == '-' ) {
                        if ( argv[i][1] == '-' ) {
                            // We have a long argument here
                            Name.erase(0, 2);
                        } else {
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
                    
                    set(Name, Value);
                }
                 
                ArgumentCount = argc + 1;
     
            }

            void setHelpLine ( std::string what ) {
                HelpLine = what;
            }

            Argument(int argc, const char ** argv) {
                doParse(argc, argv);
            }

        private:
            int ArgumentCount;
            std::string HelpLine;
            std::vector<ApricotParam*> ApricotParamContainer;
            std::map<std::string, std::string> Container;
        };
    }
