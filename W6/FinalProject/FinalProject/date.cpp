#include "date.h"

#include <string>
#include <algorithm>

using namespace std;

Date ParseDate(istream& is) {
    int year, month, day;

    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;

    return Date(year, month, day);
}
