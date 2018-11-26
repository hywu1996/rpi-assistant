//
//  tokenizer.cpp
//  
//
//  Created by Anthony Wong on 2018-11-19.
//
//

#include "tokenizer.hpp"
using namespace std;

void TokenizerClass::tokenize(string input){
    vector<string> tokens;
    
    stringstream is(input);
    string intermediate;
    while(getline(is, intermediate, ' ')){
        tokens.push_back(intermediate);
    }
    for(int i = 0; i < tokens.size(); i++){
        cout << tokens[i] << endl;
    }
}