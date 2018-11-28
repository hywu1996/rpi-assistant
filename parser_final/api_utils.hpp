//
//  api_utils.hpp
//  
//
//  Created by Anthony Wong on 2018-11-08.
//
//

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
