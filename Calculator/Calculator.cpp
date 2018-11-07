#include "Calculator.h"

using namespace std;

Calculator::Calculator()
{
}

float Calculator::calculate(vector<float> nums, vector<char> ops)
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
        else if (ops[i] == '*')
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

    return nums[0];
}