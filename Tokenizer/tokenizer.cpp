//
//  tokenizer.cpp
//  
//
//  Created by Anthony Wong on 2018-11-19.
//
//

#include "tokenizer.hpp"
using namespace std;

vector<string> TokenizerClass::tokenize(string input){
    vector<string> tokens;
    vector<string> command;
    
    int commandFlag = 0;
    int argumentFlag = 0;
    
    stringstream is(input);
    string intermediate;
    while(getline(is, intermediate, ' ')){
        tokens.push_back(intermediate);
    }
    for(int i = 0; i < tokens.size(); i++){
        //cout << tokens[i] << endl;
        
        if(argumentFlag == 0 && commandFlag == 0 && tokens[i] == "run"){
            commandFlag = 1;
        }
        else if(commandFlag == 1 && argumentFlag == 0){
            command.push_back(tokens[i]);
            commandFlag = 0;
            argumentFlag = 1;
        }
        else if(argumentFlag == 1){
            command.push_back(tokens[i]);
        }
    }
    //for(int j = 0; j < command.size(); j++){
        //cout << command[j] << endl;
    //}
    return command;
    
}
