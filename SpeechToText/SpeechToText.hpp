/**
* @author : Brandon Kong (bkong9)
* @brief  : Handles all the requisite audio recordings and API calls.
* This utility handles the USB microphone recordings, Google Speech-To-Text API call, and the Google Text-To-Speech API call.
* Its current iteration uses system calls with gcloud & CURL requests to handle the API calls, and uses the JSON parser functions in order to parse the resulting JSON from Google's Speech-To-Text API for use in functions.
*/

#ifndef STT_H
#define STT_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string>
#include <cstring>
#include <algorithm>
#include "json.hpp"
#include "../Parser/api_utils.hpp"

void recordAudio(void);
void speechToText(std::string audiofile, std::string targetJSON);
std::string parseJSON(std::string filename);
void textToSpeech(std::string text);
void cleanupFiles(void);

#endif
