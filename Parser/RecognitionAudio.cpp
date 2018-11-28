//
//  RecognitionAudio.cpp
//  
//
//  Created by Anthony Wong on 2018-11-08.
//
//

#include "RecognitionAudio.hpp"
using namespace std;
using json = nlohmann::json;

RecognitionAudio::RecognitionAudio(string content){
    audioJson = {
        {"content", content}
    };
}