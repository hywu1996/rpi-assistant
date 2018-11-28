//
//  RecognitionConfig.cpp
//  
//
//  Created by Anthony Wong on 2018-11-08.
//
//

#include "RecognitionConfig.hpp"

using namespace std;
using json = nlohmann::json;

RecognitionConfig::RecognitionConfig(string encoding, int sampleRateHertz, string languageCode, int maxAlternatives, bool profanityFilter, bool enableWordTimeOffsets){
    configJson = {
        {"encoding", encoding},
        {"sampleRateHertz", std::to_string(sampleRateHertz)},
        {"languageCode", languageCode},
        {"maxAlternatives", std::to_string(maxAlternatives)},
        {"profanityFilter", profanityFilter},
        {"enableWordTimeOffsets", enableWordTimeOffsets}
    };
}