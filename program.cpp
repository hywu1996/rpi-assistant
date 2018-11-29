#include <iostream>
#include <string>
#include "./SpeechToText/SpeechToText.hpp"
#include "./Tokenizer/tokenizer.hpp"
#include "./Weather/Weather.h"
#include "./Date/Date.h"
#include "./Volume/VolumeControl.h"
#include "./Timer/TimerHandler.h"
#include "./Calculator/Calculator.h"

using namespace std;

// ensure that tokenizer returns at least 1 argument
int validateInput(vector<string> argv) 
{
	if (argv.size() > 0)
		return 1;
	else
		return 0;
}

string recordAudioToText()
{
	recordAudio();
	speechToText("temp.flac", "temp.txt");
	return parseJSON("temp.txt");
}

void isQuit(string voiceText)
{
	if (voiceText=="run quit" || voiceText=="quit")
	{
		cout << "Exiting program..." << endl;
		textToSpeech("Exiting program.");
		cleanupFiles();
		exit(0);
	}
}


int main()
{
	TimerHandler th;
	while(true)
	{
		string enter;
		getline(std::cin, enter);
		if (enter.empty()) 
		{
			
			string apiText = recordAudioToText();
			cout << "Voice to Text: " << apiText << endl; //debugging
			isQuit(apiText);
			
			
			vector<string> args = TokenizerClass::tokenize(apiText);
			
			string output;
			
			if (validateInput(args))
			{								
				if (args[0]=="weather" || args[0]=="whether")
				{
					string city = "";
					for(int i = 1; i < args.size(); i++) 
					{
						city = city + " " + args[i];
					}
					output = Weather::getWeather(city);
					cout << "OUTPUT: " << output << endl; //debugging
				}
				else if (args[0]=="date" || args[0]=="dates")
				{
					output = Date::getDate();
				}
				else if (args[0]=="volume")
				{
					output = VolumeControl::setVolume(args[1]);
				}
				else if  (args[0]=="timer")
				{
					vector<string> timerArgs = {args[1], args[2]};
					output = th.createTimer(timerArgs);
				}
				else if (args[0]=="calculate")
				{
					vector<float> nums;
					vector<char> ops;
					for ( int i = 1; i < args.size(); i++ )
					{
						if ( i % 2 != 0 )
							nums.push_back(stof(args[i]));
						else
							ops.push_back(args[i][0]);
					}
					output = Calculator::calculate(nums, ops);
				}
				else
				{
					output = "Command not valid. Please try again.";
				}
			}
			else
			{
				output = "Please start command with the word run.";
			}
			cout << output << endl; //debugging
			textToSpeech(output);
			
			cleanupFiles(); //remove temp files
		}
	}
}
