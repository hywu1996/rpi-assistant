Group 32 - PiAssist

A basic virtual assistant program using the Raspberry Pi in conjunction with Google's Speech API.

Prerequisites:
1. Install and initialize the Google Cloud SDK (https://cloud.google.com/sdk/docs/)
2. Install nlohmann's JSON library for C++ (https://github.com/nlohmann/json)
3. Move the secret-meridian file to your Downloads folder, then initialize the following environment variables as such:
	AUDIODEV=hw:1,0
	AUDIODRIVER=alsa
	GOOGLE_APPLICATION_CREDENTIALS="~/Downloads/secret-meridian-221416-2f60aa85d2a0.json"
	*Alternatively, you can move the secret-meridian folder where you wish and set the GOOGLE_APPLICATION_CREDENTIALS appropriately.

Main Program Compilation:
g++ Parser/api_utils.cpp Parser/RecognitionAudio.cpp Parser/RecognitionConfig.cpp Tokenizer/tokenizer.cpp Weather/Weather.cpp Date/Date.cpp Volume/VolumeControl.cpp Timer/TimerHandler.cpp Timer/Timer.cpp Calculator/Calculator.cpp SpeechToText/SpeechToText.cpp program.cpp -o Program -Wno-psabi
