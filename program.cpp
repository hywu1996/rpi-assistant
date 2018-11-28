#include <iostream>
#include <string>
#include "./SpeechToText/SpeechToText.hpp"
#include "./Tokenizer/tokenizer.hpp"
#include "./Weather/Weather.h"
#include "./Date/Date.h"
#include "./Volume/VolumeControl.h"
#include "./Timer/TimerHandler.h"

using namespace std;

int main()
{
	TokenizerClass tokenizer;
	Weather w;
	Date d;
	VolumeControl vol;
	TimerHandler th;
	while(true)
	{
		string enter;
		getline(std::cin, enter);
		if (enter.empty()) 
		{
			recordAudio();
			speechToText("temp.flac", "temp.txt");
			string apiText = parseJSON("temp.txt");
			
			if (apiText=="run quit")
			{
				exit(0);
			}
			
			cout << "Voice to Text: " << apiText << endl; //debugging
			vector<string> args = tokenizer.tokenize(apiText);
			
			//----TESTING----
			cout << "Tokenized Vector" << endl;
			for(int j = 0; j < args.size(); j++){
				cout << args[j] << endl;
			}
			//----
			
			string output;
			
			if (args[0]=="weather" || args[0]=="whether")
			{
				string city = "";
				for(int i = 1; i < args.size(); i++) 
				{
					city = city + " " + args[i];
				}
				output = w.getWeather(city);
				cout << "OUTPUT: " << output << endl; //debugging
			}
			else if (args[0]=="date" || args[0]=="dates")
			{
				output = d.getDate();
			}
			else if (args[0]=="volume")
			{
				output = vol.setVolume(args[1]);
			}
			else if  (args[0]=="timer")
			{
				vector<string> timerArgs = {args[1], args[2]};
				output = th.createTimer(timerArgs);
			}
			
			textToSpeech(output);
			cleanupFiles();
		}
	}
}
