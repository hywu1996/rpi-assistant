//
//  tokenizer.cpp
//  
//
//  Created by Anthony Wong on 2018-11-19.
//
//

#include "tokenizer.hpp"
using namespace std;

/*  @brief Take in parsed user mic input and output vector of recognized words
 *  @parameters std:: string input representing parsed user mic input
 *  @returns std::vector<string> representing [command, args..] to call the corresponding command
 */
vector<string> TokenizerClass::tokenize(string input){
    
    /// tokens vector holds individual words delimited by spaces.
    vector<string> tokens;
    
    /// command vector holds only the command portion of the input string- detected after user says 'run'
    vector<string> command;
    
    /// command flag will be 1 when the word 'run' is detected- the next word will be the command and added to vector
    int commandFlag = 0;
    
    /// argument flag will be after the command is detected and added to the vector, add the rest to vector
    int argumentFlag = 0;
    
    /// use stringstream to tokenize input
    stringstream is(input);
    string intermediate;
    while(getline(is, intermediate, ' ')){
        
        /// add tokens to vector
        tokens.push_back(intermediate);
    }
    if(tokens.size() < 2){
        return command;
    }

    /// iterate through vector and  add tokens to the command vector depending on the flags active
    for(int i = 0; i < tokens.size(); i++){
        if (tokens[i] == "" || tokens[i]== " ")
        {
            continue;
        }
        
        /// detect the 'run' phrase will add the next word as the command
        if(argumentFlag == 0 && commandFlag == 0 && tokens[i] == "run"){
            commandFlag = 1;
        }
        
        /// add next word as command
        else if(commandFlag == 1 && argumentFlag == 0){
            command.push_back(tokens[i]);
            commandFlag = 0;
            argumentFlag = 1;
        }
        
        // add remaining words as arguments
        else if(argumentFlag == 1){
            command.push_back(tokens[i]);
        }
    }

    return command;
    
}
