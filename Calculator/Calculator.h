#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>

class Calculator
{
	public:
		Calculator(); //constructor
		std::string calculate(std::vector<float>, std::vector <char>);
};
#endif