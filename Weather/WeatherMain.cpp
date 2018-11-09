#include "Weather.h"

using namespace std;

int main()
{
	Weather weather;
    //string output = weather.getWeather("London,CA");
	vector<string> output = weather.getWeather("London,CA");

    cout << "OUTPUT" << endl;
    cout << "Temp:" << output[0] << "  condition:" << output[1] << endl;
}