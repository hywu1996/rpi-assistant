#include "Weather.h"

using namespace std;

int main()
{
	Weather weather;
    //string output = weather.getWeather("London,CA");

    cout << "Test 1: London, CA" << endl;
	string output = weather.getWeather("London,CA");
    cout << output << endl;


    cout << "Test 2: London, GB" << endl;
	output = weather.getWeather("London,GB");
	cout << output << endl;

    cout << "Test 3: Shanghai" << endl;
	output = weather.getWeather("Shanghai");
	cout << output << endl;

    cout << "Test 4: Nanjing" << endl;
	output = weather.getWeather("Nanjing");
	cout << output << endl;

    cout << "Test 5: Shenyang" << endl;
	output = weather.getWeather("Shenyang");
	cout << output << endl;
}