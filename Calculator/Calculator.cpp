/**
* @author : Harry Wu
* @brief  : Calculator function for +,-,*,/
* Takes in two vectors as args. One has the
* numbers in the mathematical equation and 
* the other has the operators. Calculate the
* result and return it to 2 decimal places
* as a string.
*/

#include "Calculator.h"

using namespace std;

/*  @brief  : Empty constructor
 */
Calculator::Calculator()
{
}
/*  @brief      : Take in vector of numbers and vector of operations to calculate equation result
 *  @parameters : vector<float> nums - vector of type float that contains the numerical terms in the equation
 *  @parameters : vector<char> ops - vector of type char that contains the operators in the equation
 *  @return     : string ret - the answer to the equation to two decimal places
 */
string Calculator::calculate(vector<float> nums, vector<char> ops)
{
    //division and multiplication
    for (int i = 0; i < ops.size(); i++)
    {
        if (ops[i] == '/')
        {
            float quotient = nums[i]/nums[i+1];
            ops.erase(ops.begin() + i);
            nums[i] = quotient;
            nums.erase(nums.begin() + i + 1);
            i--;
        }
        else if (ops[i] == '*' || ops[i]=='x')
        {
            float product = nums[i] * nums[i+1];
            ops.erase(ops.begin() + i);
            nums[i] = product;
            nums.erase(nums.begin() + i + 1);
            i--;
        }
    }
    //addition and subtraction
    for (int i = 0; i < ops.size(); i++)
    {
        if (ops[i] == '+')
        {
            float sum = nums[i] + nums[i+1];
            ops.erase(ops.begin() + i);
            nums[i] = sum;
            nums.erase(nums.begin() + i + 1);
            i--;
        }
        else if (ops[i] == '-')
        {
            float diff = nums[i] - nums[i+1];
            ops.erase(ops.begin() + i);
            nums[i] = diff;
            nums.erase(nums.begin() + i + 1);
            i--;
        }
    }

    stringstream stream;
    stream << fixed << setprecision(2) << nums[0]; //round to two decimal places
    string ret = stream.str();
    return ret;
}
