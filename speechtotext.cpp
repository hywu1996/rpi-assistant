#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
    system("gcloud ml speech recognize audio.flac --language-code='en-US'"); //uses gcloud command line input to retrieve the transcript of the audio file; will become a variable
}