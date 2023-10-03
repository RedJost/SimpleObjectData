#pragma once

#include "secondaryFunc.h"
#include <iomanip>



struct coordinats {
	double x;
	double y;
};


class dataObject {
	std::string name;
	coordinats coord;
	std::string type;
	std::tm time;

public:
	dataObject();
	dataObject(std::string inName, coordinats inCoord, std::string inType, std::tm inTime);

	void setName(std::string& inName);
	void setCoord(coordinats& inCoord);
	void setType(std::string& inType);
	void setTime(std::tm& inTime);

	std::string getName() const;
	coordinats getCoord() const;
	std::string getType() const;
	std::tm getTime() const;

	void showObject() const;

	dataObject& operator=(const dataObject& other);
};
