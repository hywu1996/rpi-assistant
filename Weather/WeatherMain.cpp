#include "Weather.h"

using namespace std;

int main()
{
	Weather weather;
    //string output = weather.getWeather("London,CA");

    cout << "Test 1: London, CA" << endl;
	vector<string> output = weather.getWeather("London,CA");
    cout << "London,CA" << "  Temp:" << output[0] << "  condition:" << output[1] << endl;


    cout << "Test 2: London, GB" << endl;
	output = weather.getWeather("London,GB");
    cout  << "London,GB" << "  Temp:" << output[0] << "  condition:" << output[1] << endl;


    cout << "Test 3: Shanghai" << endl;
	output = weather.getWeather("Shanghai");
    cout  << "Shanghai" << "  Temp:" << output[0] << "  condition:" << output[1] << endl;


    cout << "Test 4: Nanjing" << endl;
	output = weather.getWeather("Nanjing");
    cout  << "Nanjing" << "  Temp:" << output[0] << "  condition:" << output[1] << endl;

        cout << "Test 5: Shenyang" << endl;
	output = weather.getWeather("Shenyang");
    cout  << "Shenyang" << "  Temp:" << output[0] << "  condition:" << output[1] << endl;
}