#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	Calculator calc;
	vector<float> nums{4.0, 9.0, 8.0, 12.0,2.0};
	vector<char> ops{'+', '-', '*', '/'};

    float output = calc.calculate(nums, ops);

    cout << output << endl;
	
	return 0;
}
