#include "Weather.h"

using namespace std;

Weather::Weather(){

}

vector<string> Weather::getWeather(string city)
{
    string arguments = city;  //location
    string filename = "./weatherapi.py "; //python script
    string command = "python3 "; //python shell command
    
    command = command + filename + arguments;
    system(command.c_str()); // execute python script

    //python script is being used to expediate the process of making an API call
    //with time (hopefully by final submission) code will be refactored into c++
    //this was communicated to Professor Katchabaw

    size_t size = 2; 
    vector<string> ret(size); // 0: temperature || 1: condition
    
    ifstream res; // response file from API call
    string line; // read line 
    res.open("temp_results.txt"); // open response file
    getline(res, line);
    ret[0] = line; //temperature
    getline(res, line);
    ret[1] = line; //condition
    res.close();
    return ret;

}