#include "VolumeControl.h"

using namespace std;

VolumeControl::VolumeControl() 
{
}

string VolumeControl::setVolume(string volume)
{
	string command = "amixer set PCM " + volume + "% -M"; 
	cout << "\nVOLUMECONTROL\n" << command << endl;
	system(command.c_str()); //execute system call to change volume level
	string ret = "Volume set to " + volume + "%";
	
	return ret;
}
