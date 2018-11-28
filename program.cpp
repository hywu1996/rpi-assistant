#include "./SpeechToText/SpeechToText.hpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	while(true)
	{
		string enter;
		getline(std::cin, enter);
		if (enter.empty()) 
		{
			recordAudio();
			speechToText("temp.flac", "temp.txt");
			string apiText = parseJSON("temp.txt");
			// tokenize apiText, run the appropriate functions based on the command
			textToSpeech(resultingStringHere);
			cleanupFiles();	
		}

	}

}