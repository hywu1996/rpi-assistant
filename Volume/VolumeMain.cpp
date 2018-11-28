#include "VolumeControl.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	VolumeControl vol;
	string command = "aplay test.wav &";
	cout << "PLAYING test.wav\n---------" << endl;
	system(command.c_str());
	std::chrono::seconds dura( 3 );
	this_thread::sleep_for( dura );
	cout << "---------\nVolume: 25%\n---------" << endl;
	vol.setVolume("25");
	this_thread::sleep_for( dura );
	cout << "Setting volume to 50%\n---------" << endl;
	vol.setVolume("50");
	this_thread::sleep_for( dura );
	cout << "Setting volume to 100%\n---------" << endl;
	vol.setVolume("100");
	this_thread::sleep_for( dura );
	command = "pkill aplay";
	system(command.c_str());

	return 0;
}
