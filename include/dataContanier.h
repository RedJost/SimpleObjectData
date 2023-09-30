#pragma once
#include <dataObject.h>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <fstream>

class dataContanier {
	std::vector<dataObject> data;
public:
	dataContanier();
	//dataContanier(std::string& infileName);
	dataContanier(dataObject& other);
	dataContanier(std::vector<dataObject>& inData);

	void addObject(dataObject& other);
	void deleteObject(int index);
	void showObjects() const;
	void outputData(std::string infileName) const;
	void outputData() const;
	void sort(std::string format);

	dataContanier& operator=(const dataContanier& other);

	friend std::unordered_map<std::string, dataContanier> groupDistance(dataContanier& inData);
	friend std::unordered_map<char, dataContanier> groupName(dataContanier& inData);
	friend std::unordered_map<std::string, dataContanier> groupType(dataContanier& inData, int N = 2);
	friend std::unordered_map<std::string, dataContanier> groupTime(dataContanier& inData);
}; 