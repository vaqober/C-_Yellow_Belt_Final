#include "date.h"

#include <iomanip>
#include <sstream>
#include <tuple>

Date::Date() : year_(0), month_(0), day_(0) {};
Date::Date(const int& year, const int& month, const int& day) : 
	year_(year), month_(month), day_(day) {};

tuple<int, int, int> Date::GetDate() const {
	return tie(year_, month_, day_);
}

Date ParseDate(istream& is) {
	int year, month, day;

	is >> year;
	is.ignore(1);
	is >> month;
	is.ignore(1);
	is >> day;

	return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date) {
	auto d = date.GetDate();
	os << setfill('0') <<
		setw(4) << get<0>(d) << '-' <<
		setw(2) << get<1>(d) << '-' <<
		setw(2) << get<2>(d);
	return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.GetDate() < rhs.GetDate();
}

bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.GetDate() == rhs.GetDate();
}

bool operator>(const Date& lhs, const Date& rhs) {
	return lhs.GetDate() > rhs.GetDate();
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return lhs.GetDate() != rhs.GetDate();
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return lhs.GetDate() <= rhs.GetDate();
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return lhs.GetDate() >= rhs.GetDate();
}