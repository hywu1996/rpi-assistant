#include <iostream>
#include "Date.h"
#include "Date.cpp"

int main(int argc, char const *argv[])
{
    Date* date = new Date();
    std::cout << date->getDate();

    return 0;
}
