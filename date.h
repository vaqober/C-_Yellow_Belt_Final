#pragma once
#include <iostream>

using namespace std;

class Date {
public:
	Date();
	Date(const int& year, const int& month, const int& day);
	tuple<int, int, int> GetDate() const;
private:
	int year_;
	int day_;
	int month_;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);