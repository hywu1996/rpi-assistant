#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>
#include <iomanip>
#include <sstream> 
class Calculator
{
	public:
		Calculator(); //constructor
		static std::string calculate(std::vector<float>, std::vector <char>);
};
#endif
