/**
 * TimerHandler.cpp
 *
 * @brief:  using thread and to fork process, split
 * 		    different alarm cases for second, minute and hour.
 * 			after program catch the argument of certain time period,
 * 			use function setTimer to set a alarm.
 *
 * @author: Min Zhu
 *
 */

#include "TimerHandler.h"
#include <unistd.h>
#include <sys/types.h>

using namespace std;

//int TimerHandler::_idcounter = 0;

TimerHandler::TimerHandler() 
{
}

/**
* @parameters : vector<string> args - pass in args where args[0]=numerical and args[1]=units
* 				e.g. args = ["30", "minutes"]
* @brief      : set different cases for args[1], then set the alarm with args[0] time period
* 				using setTimer function in Timer.cpp.
*/

string TimerHandler::createTimer(vector<string> args)
{
	pid_t pid = fork();
	if (pid==0)
	{
		if(args[1]=="second" || args[1]=="seconds")
		{
			//Timer newTimer();
			Timer::setTimer(stoi(args[0]));
		}
		else if(args[1]=="minute" || args[1]=="minutes")
		{
			//Timer newTimer();
			int seconds = stoi(args[0]) * 60;
			Timer::setTimer(seconds);
		}
		else if(args[1]=="hour" || args[1]=="hours")
		{
			//Timer newTimer();
			int seconds = stoi(args[0]) * 60 * 60;
			Timer::setTimer(seconds);		
		}
		else if(args[1]=="day" || args[1]=="days")
		{
			//Timer newTimer();
			int seconds = stoi(args[0]) * 60 * 60 * 24;
			Timer::setTimer(seconds);
		}
	}
	else 
	{
		string ret = "Timer set for " + args[0] + " " + args[1];
		return ret;
	}
}
