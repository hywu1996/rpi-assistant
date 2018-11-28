#include "TimerHandler.h"
#include "Timer.h"

using namespace std;

int main()
{
	TimerHandler handler;
	vector<string> args = {"5", "seconds"};
	vector<string> args0 = {"10", "second"};
	vector<string> args1 = {"1", "minute"};
	cout << "Setting alarm for 5 seconds..." << endl;
	handler.createTimer(args);
	cout << "Setting alarm for 10 seconds..." << endl;
	handler.createTimer(args0);
	cout << "Setting alarm for 1 minute..." << endl;
	handler.createTimer(args1);

	return 0;
}
