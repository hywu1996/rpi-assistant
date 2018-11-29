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

/** @brief only a constructor to populate JSON class attribute audioJSON
 *  @parameters string content: audio encoded into string representation
 */
RecognitionAudio::RecognitionAudio(string content){
    audioJson = {
        {"content", content}
    };
}