#include "Weather.h"

using namespace std;

Weather::Weather(){

}

vector<string> Weather::getWeather(string city)
{
    string arguments = city;  //location
    string filename = "./weatherapi.py ";
    string command = "python3 ";

    size_t size = 2;
    vector<string> ret(size);
    
    command = command + filename + arguments;
    system(command.c_str());

    ifstream res;
    string line;
    res.open("temp_results.txt");
    getline(res, line);
    ret[0] = line; //temperature
    //string temperature = line;
    getline(res, line);
    ret[1] = line; //condition
    //string conditions = line;
    res.close();
    //return temperature + " " + conditions;
    return ret;

}