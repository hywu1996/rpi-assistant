/**
 * api_utils.hpp
 *
 * @brief serializer and deserializer for communicating with Google Speech API
 *
 *  This utility is meant to take the user's
 *  mic input as a string after it has been
 *  translated to text by Google's speech API
 *  and parsed from JSON in our api_utils.
 *
 * @author: Anthony Wong
 *
 * @date $Date: 2018-11-29
 *
 * Contact: awong655@uwo.ca
 *
 * Created on: 2018-11-08
 */

#ifndef api_utils_hpp
#define api_utils_hpp

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include "RecognitionAudio.hpp"
#include "RecognitionConfig.hpp"
#include "json.hpp"


std::string json_serializer(std::string, int, std:: string, int, bool, bool, std:: string);
nlohmann::json json_deserialize(std::string);

#endif /* api_utils_hpp */
