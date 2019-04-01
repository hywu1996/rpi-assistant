/**
 * @class:  Timer
 *
 * @brief:  using chrono to set a alarm for certain
 * 			time period, and execute to play alarm sound when
 * 			time is up.
 *
 * @author: Min Zhu
 *
 * @date $Date: 2018-11-29
 *
 * Contact: mzhu92@uwo.ca
 *
 * Created on: 2018-11-29
 */

#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>

class Timer
{
	public:
		Timer(); //constructor
		static void setTimer(int);

};

#endif
