/**
 * @class RecognitionAudio
 *
 * @brief serializer for audio part of JSON string with Google Speech API
 *
 *  This class serializes audio in string representation in JSON.
 *  Audio input is sent to Google's API where it utilizes the information to
 *  perform speech to text.
 *
 * @author: Anthony Wong
 *
 * @date $Date: 2018-11-29
 *
 * Contact: awong655@uwo.ca
 *
 * Created on: 2018-11-08
 */

#ifndef RecognitionAudio_hpp
#define RecognitionAudio_hpp

#include <stdio.h>
#include "json.hpp"

/** @brief takes in string representation of Audio and serializes it in JSON
 */
class RecognitionAudio{
public:
    nlohmann::json audioJson;
    RecognitionAudio(std::string);
};

#endif /* RecognitionAudio_hpp */
