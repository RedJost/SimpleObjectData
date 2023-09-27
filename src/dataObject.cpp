#include "dataObject.h"

dataObject::dataObject(std::string inName, coordinats inCoord, std::string inType, std::tm inTime) {
	this->name = inName;
	this->coord = inCoord;
	this->type = inType;
	this->time = inTime;
}

dataObject::dataObject() {

}


void dataObject::setName(std::string& inName) {
	this->name = inName;
}

void dataObject::setCoord(coordinats& inCoord) {
	this->coord = inCoord;
}

void dataObject::setType(std::string& inType) {
	this->type = inType;
}

void dataObject::setTime(std::tm& inTime) {
	this->time = inTime;
}

std::string dataObject::getName() const {
	return this->name;
}

coordinats dataObject::getCoord() const {
	return this->coord;
}

std::string dataObject::getType() const {

	return this->type;
}

std::tm dataObject::getTime() const {
	return this->time;
}

void dataObject::showObject() const {
	std::cout <<  this->name << ", " << this->coord.x << ", " << this->coord.y << ", " << this->type << ", " << std::asctime(&time);
}

dataObject& dataObject::operator=(const dataObject& other) {
	this->setName(other.getName());
	this->setTime(other.getTime());
	this->setCoord(other.getCoord());
	this->setType(other.getType());
	return (*this);
}


