/**
* @author : Wayne Maysuik (wmaysuik)
* @brief  : Gets the current date, formats it, and returns it as a string.
*/

#include "Date.h"

Date::Date() {

}

/**
* @returns : String - The formatted date and time.
* @brief   : Gets the date as numbers using the ctime library.
*/
std::string Date::getDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::stringstream stream;
    stream << getDay(ltm->tm_wday) << ", ";
    stream << getMonth(ltm->tm_mon) << " ";
    stream << ltm->tm_mday << ", ";
    stream << getYear(ltm->tm_year) << "\n"; 
    return stream.str();
}


/**
* @parameters : int day - The day of the week to be converted to a string.
* @returns    : String - The day of the week in string format.
* @brief      : Converts the day of the week into a string representation.
*/
std::string Date::getDay(int day) {

    switch(day) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Error";
    }
}

/**
* @parameters : int month - The month to be converted to a string.
* @returns    : String - The month in string format.
* @brief      : Converts the month into a string representation.
*/
std::string Date::getMonth(int month) {
    switch(month) {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default:
            return "Error";
    }
}

/**
* @parameters : int year - The year to be converted into the correct year.
* @returns    : String - The corerect year in string format.
* @brief : Converts the year into the proper year.
*/
std::string Date::getYear(int year) {
    return std::to_string(year + 1900);
}
