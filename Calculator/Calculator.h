/**
 * @class Calculator
 *
 * @brief Calculator function for +,-,*,/
 *
 *  Takes in two vectors as args. One has the
 *  numbers in the mathematical equation and 
 *  the other has the operators.
 *
 * @author: Harry Wu
 *
 * @date: 2018-11-29
 *
 * Contact: ywu582@uwo.ca
 *
 * Created on: 2018-11-18
 */

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
	    /** Takes in the numbers and operators as two vectors.
     	 *  Outputs the result of equation as a two decimal place string.
     	 * */
		static std::string calculate(std::vector<float>, std::vector <char>);
};
#endif
