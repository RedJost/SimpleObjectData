#include "secondaryFunc.h"



std::tm createTime(int day, int mounth, int year, int hour, int min , int sec, int spec) {
	std::tm res{};
	if (year < 1900) {
		std::cout << "log: invalid time, year must be more than 1900 \n";
		return res;
	}
	if (mounth < 1 || mounth > 11) {
		std::cout << "log: invalid time, mounth interval \n";
		return res;
	}
	if (day < 1) {
		std::cout << "log: invalid time, day interval \n";
		return res;
	}
	res.tm_year = year - 1900;
	res.tm_mon = mounth - 1;
	res.tm_mday = day;
	res.tm_hour = hour;
	res.tm_min = min;
	res.tm_sec = sec;
	res.tm_isdst = spec;
	return (res);
}

std::tm createTimeFromString(std::string date) {
	int d = -1, m = -1, y = -1;
	std::string number = "";

	for (int i = 0; i < date.length(); i++) {
		if (date[i] != '.') {
			number += date[i];
		}
		else {
			if (d == -1) {
				d = std::stoi(number);
			}
			else if (m == -1) {
				m = std::stoi(number);
			}
			number = "";
			continue;
		}

		y = std::stoi(number);
	}

	return createTime(d, m, y);
}

std::string mounthStr(std::string mounth) {
	if (mounth == "Jan") return "0";
	if (mounth == "Feb") return "1";
	if (mounth == "Mar") return "2";
	if (mounth == "Apr") return "3";
	if (mounth == "May") return "4";
	if (mounth == "Jun") return "5";
	if (mounth == "Jul") return "6";
	if (mounth == "Aug") return "7";
	if (mounth == "Sep") return "8";
	if (mounth == "Oct") return "9";
	if (mounth == "Nov") return "10";
	if (mounth == "Dec") return "11";
	return "";
}