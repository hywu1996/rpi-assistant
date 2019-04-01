/**
 * @class RecognitionAudio
 *
 * @brief serializer for configuration part of JSON string with Google Speech API
 *
 *  This class serializes the audio's configuration into JSON.
 *  Audio configuration is set by the programmer to be sent to Google Speech API
 *
 *
 * @author: Anthony Wong
 *
 * @date $Date: 2018-11-29
 *
 * Contact: awong655@uwo.ca
 *
 * Created on: 2018-11-08
 */


#ifndef RecognitionConfig_hpp
#define RecognitionConfig_hpp

#include <stdio.h>
#include "json.hpp"

/** @brief serialize configuration set by programmer and sets it to the JSON attribute configJson
 *
 */
class RecognitionConfig{
public:
    nlohmann::json configJson;
    RecognitionConfig(std::string, int, std::string, int, bool, bool);
};

#endif /* RecognitionConfig_hpp */
