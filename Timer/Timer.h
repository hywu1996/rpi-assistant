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
	//private:
		//static int _id;
		//static std::string _command;
};
#endif
