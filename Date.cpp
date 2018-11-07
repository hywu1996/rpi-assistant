#include "Date.h"
Date::Date() {

}

std::string Date::getDate() {
    time_t now = time(0);
    return(ctime(&now));
}