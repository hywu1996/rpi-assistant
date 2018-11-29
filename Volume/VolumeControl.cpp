//
//  VolumeControl.cpp
//  
//
//  Created by Harry Wu on 2018-11-27.
//
//

#include "VolumeControl.h"

using namespace std;

/*  @brief Empty constructor
 */
VolumeControl::VolumeControl() 
{
}

/*  @brief 			Take in volume level between 0 and 100 as string and set system volume to that
 *  @param volume 	string of volume level
 *  @return     	string: success response to setting volume level
 */
string VolumeControl::setVolume(string volume)
{
	string command = "amixer set PCM " + volume + "% -M"; 
	cout << "\nVOLUMECONTROL\n" << command << endl;
	system(command.c_str()); //execute system call to change volume level
	string ret = "Volume set to " + volume + "%";
	
	return ret;
}
