/**
 * @class: TimerHandler
 *
 * @brief:  using thread and to fork process, split
 * 			different alarm cases for second, minute and hour.
 * 			after program catch the argument of certain time period,
 * 			use function setTimer to set a alarm.
 *
 * @author: Min Zhu
 *
 * @date $Date: 2018-11-29
 *
 * Contact: mzhu92@uwo.ca
 *
 * Created on: 2018-11-29
 */

#ifndef TIMERHANDLER_H
#define TIMERHANDLER_H

#include <thread>
#include <vector>
#include <string>
#include "Timer.h"

class TimerHandler
{
	public:
		TimerHandler(); //constructor
		static std::string createTimer(std::vector<std::string>);

};
#endif
