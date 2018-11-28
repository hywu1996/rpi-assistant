//
//  RecognitionAudio.hpp
//  
//
//  Created by Anthony Wong on 2018-11-08.
//
//

#ifndef RecognitionAudio_hpp
#define RecognitionAudio_hpp

#include <stdio.h>
#include "RecognitionAudio.hpp"
#include "json.hpp"

class RecognitionAudio{
public:
    nlohmann::json audioJson;
    RecognitionAudio(std::string);
};

#endif /* RecognitionAudio_hpp */
