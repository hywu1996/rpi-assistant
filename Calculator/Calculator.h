#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>

class Calculator
{
	public:
		Calculator(); //constructor
		float calculate(std::vector<float>, std::vector <char>);
};
#endif