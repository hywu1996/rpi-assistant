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

/** @brief constructor to serialize configuration to JSON
 *  @parameters string encoding: provide the encoding of the audio
 *  @parameters int sampleRateHertz: provide the sample rate of the audio
 *  @parameters string languageCode: provide the language of the audio
 *  @parameters int maxAlternatives: provide the max number of alternatives to the audio
 *  @parameters bool profanityFilter: choose profanity filter or not of the audio
 *  @parameters bool enableWordTimeOffsets: provide the offset of the audio
 */
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