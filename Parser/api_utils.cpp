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


/** @brief Serializer for an input string to a JSON string that complies with Google Speech API
 *  @parameters string encoding: choose the encoding of the audio file to send to the Google API
 *  @parameters int samepleRateHertz: choose the sample rate of the audio file to send to the Google API
 *  @parameters string languageCode: choose the language of the audio file to send to the Google API
 *  @parameters int maxAlternatives: choose the max alternatives of Google API's return
 *  @parameters bool profanityFilter: profanity filter on or off for Google API's return
 *  @parameters bool enableWordTimeOffsets: enable word time offsets in Google API's return
 *  @parameters string content: choose the input text to send to the Google API
 *
 *  @returns string: JSON representation of input string
 */
string json_serializer(string encoding, int sampleRateHertz, string languageCode, int maxAlternatives, bool profanityFilter, bool enableWordTimeOffsets, string content){
    
    /** Note that the JSON contains 2 nested JSON strings: config and audio
     */
    
    /// creating recognition config json
    RecognitionConfig *recogConfig = new RecognitionConfig(encoding, sampleRateHertz, languageCode, maxAlternatives, profanityFilter, enableWordTimeOffsets);
    
    json configJson = recogConfig->configJson;
    
    /// creating recognition audio json
    RecognitionAudio *recogAudio = new RecognitionAudio(content);
    
    json audioJson = recogAudio->audioJson;
    
    /// combining previous JSON to create final JSON
    json finalJson = {
        {"config",configJson},
        {"audio",audioJson}
    };
    
    /// JSON serialize
    string finalJsonString = finalJson.dump();
    
    return finalJsonString;
}

/** @brief JSON deserializer for an input string in JSON format
 *  @parameters string jsonToParse: deserialize input string into a JSON object
 *  @returns json object of the string input
 */
json json_deserialize(string jsonToParse){
    json j = json::parse(jsonToParse);
    return j;
}