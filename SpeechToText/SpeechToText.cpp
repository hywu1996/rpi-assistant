#include "SpeechToText.hpp"

using namespace std;
using json = nlohmann::json;

void recordAudio(void) {
    system("rec temp.flac rate 32k silence 2 0.1 3% 1 1.0 3%");
}

void speechToText(std::string audiofile, std::string targetJSON) {
    string line = string("gcloud ml speech recognize ") + string(audiofile) + string(" --language-code=\'en-US\' > ") + string(targetJSON);
    system(line.c_str());
}

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

void textToSpeech(std::string text) {
    string line = string("curl -H \"Authorization: Bearer \"$(gcloud auth application-default print-access-token) -H \"Content-Type: application/json; charset=utf-8\" --data \"{ \'input\':{ \'text\': \'")
    + string(text) + string("\' }, \'voice\':{ \'languageCode\':\'en-gb\', \'name\':\'en-GB-Standard-A\', \'ssmlGender\':\'FEMALE\' }, \'audioConfig\':{ \'audioEncoding\':\'MP3\' } }\" \"https://texttospeech.googleapis.com/v1/text:synthesize\" > synthesize.txt");
    system(line.c_str());
    string line2 = string("sed \'s|audioContent| |\' < synthesize.txt > tmp-output.txt && tr -d \'\n \":{}\' < tmp-output.txt > tmp-output-2.txt && base64 tmp-output-2.txt --decode > audio.mp3 && rm tmp-output*.txt");
    system(line2.c_str());
    system("mpg123 audio.mp3");
}

void cleanupFiles(void) {
    system("rm *.txt");
    system("rm *.flac");
    system("rm *.mp3");
}
