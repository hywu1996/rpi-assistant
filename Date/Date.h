#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <sstream>
#include <string>

class Date {
    public:
        Date();
        static std::string getDate();
    private:
        static std::string getDay(int);
        static std::string getMonth(int);
        static std::string getYear(int);
};
#endif
