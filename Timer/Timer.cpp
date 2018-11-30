/**
 * Timer.cpp
 *
 * @brief:  using chrono to set a alarm for certain
 * 			time period, and execute to play alarm sound when
 * 			time is up.
 *
 * @author: Min Zhu
 *
 */

#include "Timer.h"

using namespace std;


Timer::Timer()
{
}

/**
* @parameters : int - the input time user need the program to sleep for
* @brief      : let the program to sleep for certain assigned time and
*				alarm will goes off when time out.
*/

void Timer::setTimer(int seconds)
{
	chrono::seconds dura( seconds );
	cout << "Alarm set for " << seconds << "s..." << endl;
	this_thread::sleep_for( dura );
	string command = "aplay ./Timer/alarm.wav";
	system(command.c_str());
	exit(0);
}




