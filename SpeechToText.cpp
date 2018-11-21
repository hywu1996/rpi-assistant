#include "SpeechToText.hpp"

using namespace std;
using json = nlohmann::json;

void apiCall(std::string audiofile, std::string targetJSON) {
    system("export GOOGLE_APPLICATION_CREDENTIALS=\"/media/sf_VMShared/group32/secret-meridian-221416-2f60aa85d2a0.json\"");
    string line = string("gcloud ml speech recognize ") + string(audiofile) + string(" --language-code=\'en-US\' > ") + string(targetJSON);
    system(line.c_str());
}

std::string parseJSON(std::string filename) {
    std::ifstream t(filename);
    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    json jsonDeserial = json_deserialize(str);
    return jsonDeserial["results"][0]["alternatives"][0]["transcript"];
}

void cleanupTxt(void) {
    system("rm *.txt");
}

int main(void) {
    apiCall("audio.flac", "audio.txt");
    apiCall("Alarm.flac", "Alarm.txt");
    apiCall("Calculator.flac", "Calculator.txt");
    apiCall("Date.flac", "Date.txt");
    apiCall("Weather.flac", "Weather.txt");
    cout << parseJSON("audio.txt") << endl;
    cout << parseJSON("Alarm.txt") << endl;
    cout << parseJSON("Calculator.txt") << endl;
    cout << parseJSON("Date.txt") << endl;
    cout << parseJSON("Weather.txt") << endl;
    cleanupTxt();
    return 0;
}

