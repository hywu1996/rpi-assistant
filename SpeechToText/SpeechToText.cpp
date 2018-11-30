/**
* @author : Brandon Kong (bkong9)
* @brief  : Handles all the requisite audio recordings and API calls.
* This utility handles the USB microphone recordings, Google Speech-To-Text API call, and the Google Text-To-Speech API call.
* Its current iteration uses system calls with gcloud & CURL requests to handle the API calls, and uses the JSON parser functions in order to parse the resulting JSON from Google's Speech-To-Text API for use in functions.
*/

#include "SpeechToText.hpp"

using namespace std;
using json = nlohmann::json;

/**
* @brief : System call to record audio via USB microphone.
*/

void recordAudio(void) {
    system("rec temp.flac rate 32k silence 2 0.1 3% 1 1.0 3%");
}

/**
* @parameters : string audiofile - audiofile to be interpretted by Google's API
* @parameters : string targetJSON - resulting file to write the JSON contents to
* @brief      : Google Speech-To-Text API call, returns a JSON.
* Uses gcloud implementation to make the API call succinctly.
*/

void speechToText(std::string audiofile, std::string targetJSON) {
    string line = string("gcloud ml speech recognize ") + string(audiofile) + string(" --language-code=\'en-US\' > ") + string(targetJSON);
    system(line.c_str());
}

/**
* @parameters : string filename - text file containing the JSON contents to be parsed
* @returns    : string - Returns the 'input' field of the JSON, which contains the text to be processed.
* @brief      : Parses the resulting JSON from Google for use
* Parses the resulting JSON from Google's Speech-To-Text API using nlohmann's C++ JSON library.
*/

std::string parseJSON(std::string filename) {
    try {
        std::ifstream t(filename);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        json jsonDeserial = json_deserialize(str);
        std::string lowercase = jsonDeserial["results"][0]["alternatives"][0]["transcript"];
        std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
        return lowercase;
    }
    catch (...) {
        return "Error. No discernable words detected";
    }
}

/**
* @parameters : Text from a function, to be sent to Google's Text-To-Speech API.
* @brief      : API call to Google's Text-To-Speech API, then plays the resulting mp3.
* Uses the text from a function and sends it to Google's Text-To-Speech API, which returns an mp3 which is then run.
*/

void textToSpeech(std::string text) {
    string line = string("curl -H \"Authorization: Bearer \"$(gcloud auth application-default print-access-token) -H \"Content-Type: application/json; charset=utf-8\" --data \"{ \'input\':{ \'text\': \'")
    + string(text) + string("\' }, \'voice\':{ \'languageCode\':\'en-gb\', \'name\':\'en-GB-Standard-A\', \'ssmlGender\':\'FEMALE\' }, \'audioConfig\':{ \'audioEncoding\':\'MP3\' } }\" \"https://texttospeech.googleapis.com/v1/text:synthesize\" > synthesize.txt");
    system(line.c_str());
    string line2 = string("sed \'s|audioContent| |\' < synthesize.txt > tmp-output.txt && tr -d \'\n \":{}\' < tmp-output.txt > tmp-output-2.txt && base64 tmp-output-2.txt --decode > audio.mp3 && rm tmp-output*.txt");
    system(line2.c_str());
    system("mpg123 audio.mp3");
}

/**
* @brief: Cleans up temp text and audio files.
* Uses system calls to remove temporary text and audio files generated through the API calls. 
*/

void cleanupFiles(void) {
    system("rm *.txt");
    system("rm *.flac");
    system("rm *.mp3");
}
