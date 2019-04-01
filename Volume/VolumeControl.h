/**
 * @class VolumeControl
 *
 * @brief Set system volume
 *
 *  Takes in volume as a string between
 *	0-100 and will set volume to that %
 *
 * @author: Harry Wu
 *
 * @date: 2018-11-29
 *
 * Contact: ywu582@uwo.ca
 *
 * Created on: 2018-11-27
 */
#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H
#include <string>
#include <vector>

#include <iostream>

class VolumeControl
{
	public:
		VolumeControl(); //constructor
		/** Takes in volume level as string (between 0 and 100)
     	 *  Sets the volume to that percent and returns string with success response.
     	 * */
		static std::string setVolume(std::string);
};
#endif
