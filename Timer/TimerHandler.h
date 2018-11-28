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
		void createTimer(std::vector<std::string>);
	private:
		static int _idcounter;
};
#endif