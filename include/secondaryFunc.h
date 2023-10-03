#pragma once

#include "ctime"
#include "iostream"
#include "string"


std::tm createTime(int day, int mounth, int year, int hour = 6, int min = 45, int sec = 45, int spec = 1);
std::tm createTimeFromString(std::string date);
std::string mounthStr(std::string mounth);