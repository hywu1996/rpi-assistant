//
//  api_utils.cpp
//  
//
//  Created by Anthony Wong on 2018-11-08.
//
//

#include "api_utils.hpp"
using namespace std;
using json = nlohmann::json;

string json_serializer(string encoding, int sampleRateHertz, string languageCode, int maxAlternatives, bool profanityFilter, bool enableWordTimeOffsets, string content){
    
    // creating recognition config json
    RecognitionConfig *recogConfig = new RecognitionConfig(encoding, sampleRateHertz, languageCode, maxAlternatives, profanityFilter, enableWordTimeOffsets);
    
    json configJson = recogConfig->configJson;
    
    // creating recognition audio json
    RecognitionAudio *recogAudio = new RecognitionAudio(content);
    
    json audioJson = recogAudio->audioJson;
    
    // combining previous JSON
    json finalJson = {
        {"config",configJson},
        {"audio",audioJson}
    };
    
    // JSON serialize
    string finalJsonString = finalJson.dump();
    
    return finalJsonString;
}

json json_deserialize(string jsonToParse){
    json j = json::parse(jsonToParse);
    return j;
}