/**
 * @class: Weather
 *
 * @brief: generate weather condition.
 *
 * This class is meant to use user's input (name of a city)
 * and use python script to make an API call, and put output
 * result into a text file, which contain the temperature and
 * weather condition for the city.
 *
 * @author: Min Zhu
 *
 * @date $Date: 2018-11-29
 *
 * Contact: mzhu92@uwo.ca
 *
 * Created on: 2018-11-29
 */

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class Weather
{
	public:
		Weather(); //constructor
		static std::string getWeather(std::string);

};
