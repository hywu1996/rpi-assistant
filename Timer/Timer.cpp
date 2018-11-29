#include "Timer.h"

using namespace std;

//int Timer::_id;

Timer::Timer()
{
	//Timer::_id = id;
}


void Timer::setTimer(int seconds)
{
	chrono::seconds dura( seconds );
	cout << "Alarm set for " << seconds << "s..." << endl;
	this_thread::sleep_for( dura );
	//cout << "\n" << endl;
	//cout << "Sounding alarm " << Timer::_id << endl;
	string command = "aplay ./Timer/alarm.wav";
	system(command.c_str());
	exit(0);
}




