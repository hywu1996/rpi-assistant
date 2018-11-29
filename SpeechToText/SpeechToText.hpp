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
