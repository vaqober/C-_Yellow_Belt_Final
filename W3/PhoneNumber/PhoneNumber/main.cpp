#include <sstream>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string& number) {
	istringstream iss(number);

	char first = iss.get();
	
	getline(iss, country_code_, '-');
	getline(iss, city_code_, '-');
	getline(iss, local_number_);

	if (first != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + number);
	}

}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetInternationalNumber() const {
	return("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}