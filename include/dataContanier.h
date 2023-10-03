#pragma once
#include <dataObject.h>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <fstream>

class dataContainer {
	std::vector<dataObject> data;
public:
	dataContainer();
	dataContainer(std::string infileName);
	dataContainer(dataObject& other);
	dataContainer(std::vector<dataObject>& inData);

	void addObject(dataObject& other);
	dataObject& getObject(int& index);
	void deleteObject(int index);
	void showObjects() const;
	void outputData(std::string infileName) const;
	void inputData(std::string infileName);
	void sort(std::string format);
	void clear();
	int size();

	dataContainer& operator=(const dataContainer& other);

	friend std::unordered_map<std::string, dataContainer> groupDistance(dataContainer& inData);
	friend std::unordered_map<char, dataContainer> groupName(dataContainer& inData);
	friend std::unordered_map<std::string, dataContainer> groupType(dataContainer& inData, int N = 2);
	friend std::unordered_map<std::string, dataContainer> groupTime(dataContainer& inData);
}; 