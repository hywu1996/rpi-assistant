Group 32 - PiAssist

A basic virtual assistant program using the Raspberry Pi in conjunction with Google's Speech API.

Prerequisites:
1. Install and initialize the Google Cloud SDK (https://cloud.google.com/sdk/docs/)
2. Install nlohmann's JSON library for C++ (https://github.com/nlohmann/json)
3. Initialize the following environment variables as such:
	AUDIODEV=
	AUDIODRIVER=
	GOOGLE_APPLICATION_CREDENTIALS="~/Downloads/"

Functions:
SpeechToText - g++ api_utils.cpp RecognitionAudio.cpp RecognitionConfig.cpp SpeechToText.cpp W-o SpeechToText -Wno-psabi
