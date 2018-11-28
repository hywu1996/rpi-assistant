#include "VolumeControl.h"

using namespace std;

VolumeControl::VolumeControl() 
{
}

void VolumeControl::setVolume(string volume)
{
	string command = "amixer set Master " + volume + "% > /dev/null"; 
	system(command.c_str()); //execute system call to change volume level
}
