#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <sstream>
#include <string>

class Date {
    public:
        Date();
        std::string getDate();
    private:
        std::string getDay(int);
        std::string getMonth(int);
        std::string getYear(int);
};
#endif