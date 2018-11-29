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
int validateInput(vector<string> argv, int numArgs) 
{
	if (argv.size() >= numArgs)
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
	if (voiceText=="run quit" || voiceText=="quit" || voiceText=="run exit" || voiceText=="exit")
	{
		cout << "Exiting program..." << endl;
		textToSpeech("Exiting program.");
		cleanupFiles();
		exit(0);
	}
}
// Obtained from Michael Mrozek off StackOverflow: Please don't hit us with plagarism.
bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

string replaceDivisonOperands(string text)
{
	string ret = text;
	replace(ret, "/", " / ");
	replace(ret, "divided by", "/");
	return ret;
}
//-----------------------
void execute()
{
	string apiText = recordAudioToText();
	cout << "Voice to Text: " << apiText << endl; //debugging
	isQuit(apiText);
	apiText = replaceDivisonOperands(apiText);
	vector<string> args = TokenizerClass::tokenize(apiText);
	
	string output;
	
	if (validateInput(args, 1))
	{								
		if (args[0]=="weather" || args[0]=="whether")
		{
			if (validateInput(args, 2))
			{
				string city = "";
				for(int i = 1; i < args.size(); i++) 
				{
					city = city + " " + args[i];
				}
				output = Weather::getWeather(city);
			}
			else
			{
				output = "Missing city name for weather";
			}
			
		}
		else if (args[0]=="date" || args[0]=="dates")
		{
			output = Date::getDate();
		}
		else if (args[0]=="volume")
		{
			if (validateInput(args, 2))
			{
				output = VolumeControl::setVolume(args[1]);
			}
			else
			{
				output = "Missing volume level.";
			}
		}
		else if  (args[0]=="timer")
		{
			if (validateInput(args, 3))
			{
				vector<string> timerArgs = {args[1], args[2]};
				output = TimerHandler::createTimer(timerArgs);
			}
			else
			{
				output = "Missing duration and or units for alarm.";
			}
		}
		else if (args[0]=="calculate")
		{
			if (validateInput(args,4) && args.size()%2==0)
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
				output = "Incorrect number of operands and operators";
			}
		}
		else
		{
			output = "Command not valid. Please try again.";
		}
	}
	else
	{
		output = "Please use a valid command.  Start with the key word run.";
	}
	cout << output << endl; //debugging
	textToSpeech(output);
	
	cleanupFiles(); //remove temp files
}

int main()
{
	while(true)
	{
		string enter;
		getline(std::cin, enter);
		if (enter.empty()) 
		{			
			execute();
		}
	}
}
