/**
 * @class Tokenizer
 *
 * @brief Tokenize the user's mic input.
 *
 *  This class is meant to take the user's
 *  mic input as a string after it has been
 *  translated to text by Google's speech API
 *  and parsed from JSON in our api_utils.
 *
 * @author: Anthony Wong
 *
 * @date $Date: 2018-11-29
 *
 * Contact: awong655@uwo.ca
 *
 * Created on: 2018-11-19
 */

#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <sstream>
#include <vector>
//#include "Command.hpp"

class TokenizerClass{
public:
    /** Input is the user mic input in text form
     *  The output is a vector of format [command, args...]
     * */
    static std::vector<std::string> tokenize(std::string);
    
};

#endif /* tokenizer_hpp */
