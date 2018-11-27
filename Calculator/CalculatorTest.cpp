#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	Calculator calc;

	cout << "TEST 1: 4+9-8*12/2 = ";
	// 4+9-8*12/2 = 4+9-(8*(12/2)) = -35
	vector<float> nums{4.0, 9.0, 8.0, 12.0,2.0};
	vector<char> ops{'+', '-', '*', '/'};
    string output = calc.calculate(nums, ops);

    cout << output << endl;

	if (stof(output) == -35.0)
		cout << "TEST 1 PASSED" << endl;
	else
		cout << "TEST 1 FAILED\n\n" << endl;


	cout << "TEST 2: 16*9/4-12*3 = ";
	// 16*9/4-12*3 = 0
	vector<float> nums1{16.0, 9.0, 4.0, 12.0, 3.0};
	vector<char> ops1{'*', '/', '-', '*'};
    output = calc.calculate(nums1, ops1);

    cout << output << endl;

	if (stof(output) == 0)
		cout << "TEST 2 PASSED" << endl;
	else
		cout << "TEST 2 FAILED\n\n" << endl;

	
	cout << "TEST 3: 3-4*9+1 = ";
	// 3-4*9+1 = -32
	vector<float> nums2{3.0, 4.0, 9.0, 1.0};
	vector<char> ops2{'-', '*', '+'};
    output = calc.calculate(nums2, ops2);

    cout << output << endl;

	if (stof(output) == -32)
		cout << "TEST 3 PASSED" << endl;
	else
		cout << "TEST 3 FAILED\n\n" << endl;


	return 0;
}
