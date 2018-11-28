#include "Timer.h"

using namespace std;

string Timer::_command = "aplay alarm.wav";
int Timer::_id;

Timer::Timer(int id)
{
	Timer::_id = id;
}


void Timer::setTimer(int seconds)
{
	chrono::seconds dura( seconds );
	cout << "Alarm set for " << seconds << "s..." << endl;
	this_thread::sleep_for( dura );
	cout << "\n" << endl;
	cout << "Sounding alarm " << Timer::_id << endl;
	system(_command.c_str());
	exit(0);
}




