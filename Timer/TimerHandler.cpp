#include "TimerHandler.h"
#include <unistd.h>
#include  <sys/types.h>

using namespace std;

int TimerHandler::_idcounter = 0;

TimerHandler::TimerHandler() 
{
}

// pass in args where args[0]=numerical and args[1]=units
// e.g. args = ["30", "minutes"]
string TimerHandler::createTimer(vector<string> args)
{
	pid_t pid = fork();
	if (pid==0)
	{
		if(args[1]=="second" || args[1]=="seconds")
		{
			Timer newTimer(_idcounter);
			newTimer.setTimer(stoi(args[0]));
		}
		else if(args[1]=="minute" || args[1]=="minutes")
		{
			Timer newTimer(_idcounter);
			int seconds = stoi(args[0]) * 60;
			newTimer.setTimer(seconds);
		}
		else if(args[1]=="hour" || args[1]=="hours")
		{
			Timer newTimer(_idcounter);
			int seconds = stoi(args[0]) * 60 * 60;
			newTimer.setTimer(seconds);		
		}
		else if(args[1]=="day" || args[1]=="days")
		{
			Timer newTimer(_idcounter);
			int seconds = stoi(args[0]) * 60 * 60 * 24;
			newTimer.setTimer(seconds);
		}
	}
	else 
	{
		_idcounter += 1;
		string ret = "Timer set for " + args[0] + " " + args[1];
		return ret;
	}
}
