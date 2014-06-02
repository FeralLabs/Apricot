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
    
    class ParamParser
    {
        public:
            bool didParse;

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
                bool found = false;
                for(std::vector<ApricotParam*>::iterator It = ApricotParamContainer.begin(); It != ApricotParamContainer.end(); ++It) {
                    if ( (**It).LongName == what || (**It).ShortName == what) {
                        Container [ (**It).LongName ] = with;
                        found = true;
                        break;
                    }
                }

                if ( found == false ) {
                    std::cout << "Argument not found.";
                }
            }

            bool isset(std::string what) {
                return !Container[what].empty();
            }
            
            ParamParser* undefine(std::string what) {
                bool found = false;
                for(std::vector<ApricotParam*>::iterator It = ApricotParamContainer.begin(); It != ApricotParamContainer.end(); ++It) {
                    if ((**It).LongName == what || (**It).ShortName == what) {
                        It = ApricotParamContainer.erase(It);
                        found = true;
                        break; // otherwise you'll get a nice Seg Fault
                    }
                }

                if ( found == false ) {
                    std::cout << "No param named " << what;
                }

                return this;
            }

            ParamParser* define(std::string LongName, std::string ShortName, std::string Description) {
                if (didParse == true )
                    std::cout << "Aloc after parse";

                ApricotParamContainer.push_back(new ApricotParam(LongName, ShortName, Description));
                return this;
            }

            void printHelp() {
                if (!UsageLine.empty() )
                    std::cout << UsageLine << HelpLine << std::endl << std::endl;
                else
                    std::cout << HelpLine << std::endl << std::endl;

                for(std::vector<ApricotParam*>::iterator It = ApricotParamContainer.begin(); 
                    It != ApricotParamContainer.end(); ++It) {
                    (**It).doPrintHelp();
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
                    didParse = true;
                }
                 
                ArgumentCount = argc + 1;
     
            }
            
            ParamParser* setUsageLine ( std::string what ) {
                UsageLine = what;
                return this;
            }

            ParamParser* setHelpLine ( std::string what ) {
                HelpLine = what;
                return this;
            }

            ParamParser() {
                didParse = false;
                //doParse(argc, argv); BUG FIX :D :D :D
            }

        private:
            int ArgumentCount;
            std::string HelpLine, UsageLine;
            std::vector<ApricotParam*> ApricotParamContainer;
            std::map<std::string, std::string> Container;
        };
    }

