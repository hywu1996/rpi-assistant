//
//  RecognitionConfig.hpp
//  
//
//  Created by Anthony Wong on 2018-11-08.
//
//

#ifndef RecognitionConfig_hpp
#define RecognitionConfig_hpp

#include <stdio.h>
#include "json.hpp"

class RecognitionConfig{
public:
    nlohmann::json configJson;
    RecognitionConfig(std::string, int, std::string, int, bool, bool);
};

#endif /* RecognitionConfig_hpp */
