#include <dataContanier.h>





dataContainer::dataContainer(){
}

dataContainer::dataContainer(std::string infileName) {
	std::ifstream file(infileName);
	if (file.is_open() ) {
		std::string element;
		dataObject cur;
		std::string time = "";
		std::string mounth = "";
		coordinats a;
		while (!file.eof()) {
			for (int i = 0; i < 9; i++) {
				file >> element;
				if (i == 0) {
					cur.setName(element);
				}
				else  if (i == 1) {
					a.x = std::stod(element);
				}
				else if (i == 2) {
					a.y = std::stod(element);
					cur.setCoord(a);
				}
				else if (i == 3) {
					cur.setType(element);
				}
				else if (i == 5) {
					mounth = mounthStr(element);
				}
				else if (i == 6) {
					time += element + "." + mounth + ".";
				}
				else if (i == 8) {
					time += element;
					cur.setTime(createTimeFromString(time));
					time = "";
				}
			}
			data.push_back(cur);
		}
	}
	else {
		std::cout << "log invalid file\n";
	}
}

dataContainer::dataContainer(dataObject& other) {
	this->data.push_back(other);
}

dataContainer::dataContainer(std::vector<dataObject>& inData) {
	this->data.resize(inData.size());
	for (int i = 0; i < inData.size(); i++) {
		data[i] = inData[i];
	}
}

void dataContainer::addObject(dataObject& other) {
	this->data.push_back(other);
}

dataObject& dataContainer::getObject(int& index)
{
	if (index >= 0 && index < data.size()) {
		return (data[index]);
	}
	return dataObject();
}

void dataContainer::deleteObject(int index) {
	if (index < 0 || index >= data.size()) {
		std::cout << "log: invalid index\n";
	}
	else {
		data.erase(data.begin() + index);
	}
}

void dataContainer::showObjects() const {
	for (auto it : data) {
		it.showObject();
	}
}

void dataContainer::outputData(std::string infileName) const {
	std::ofstream file(infileName);
	if (file.is_open()) {
		
		for (int i = 0; i < data.size(); i++) {
			file << data[i].getName() << " " << data[i].getCoord().x << " " << data[i].getCoord().y << " " << data[i].getType() << " " << std::asctime(&data[i].getTime());
		}
	}
	else {
		std::cout << "log: invalid file\n";
	}
}

void dataContainer::inputData(std::string infileName) {
	data.clear();
	std::ifstream file(infileName);
	if (file.is_open()) {
		std::string element;
		dataObject cur;
		std::string time = "";
		std::string mounth = "";
		coordinats a;
		while (!file.eof()) {
			for (int i = 0; i < 9; i++) {
				file >> element;
				if (i == 0) {
					cur.setName(element);
				}
				else  if (i == 1) {
					a.x = std::stod(element);
				}
				else if (i == 2) {
					a.y = std::stod(element);
					cur.setCoord(a);
				}
				else if (i == 3) {
					cur.setType(element);
				}
				else if (i == 5) {
					mounth = mounthStr(element);
				}
				else if (i == 6) {
					time += element + "." + mounth + ".";
				}
				else if (i == 8) {
					time += element;
					cur.setTime(createTimeFromString(time));
					time = "";
				}
			}
			data.push_back(cur);
		}
	}
	else {
		std::cout << "log invalid file\n";
	}
}

void dataContainer::sort(std::string format) {
	if (format == "DistanceDown") {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				if ( std::sqrt(std::pow(data[j].getCoord().x, 2) + std::pow(data[j].getCoord().y, 2)) < std::sqrt(std::pow(data[i].getCoord().x, 2) + std::pow(data[i].getCoord().y, 2))) {
					auto tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}
					
			}
		}
	}
	else if (format == "DistanceUp") {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				if (std::sqrt(std::pow(data[j].getCoord().x, 2) + std::pow(data[j].getCoord().y, 2)) > std::sqrt(std::pow(data[i].getCoord().x, 2) + std::pow(data[i].getCoord().y, 2))) {
					auto tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}

			}
		}
	}
	else if (format == "NameUp") {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				if (data[i].getName().compare(data[j].getName()) < 0) {
					auto tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}
			}
		}

	}
	else if (format == "NameDown") {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				if (data[i].getName().compare(data[j].getName()) > 0) {
					auto tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}
			}
		}
	}
	else if (format == "TimeUp") {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				std::time_t timeI = std::mktime(&data[i].getTime());
				std::time_t timeJ = std::mktime(&data[j].getTime());
				if (timeI < timeJ) {
					auto tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}
			}
		}
	}
	else if (format == "TimeDown") {
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				std::time_t timeI = std::mktime(&data[i].getTime());
				std::time_t timeJ = std::mktime(&data[j].getTime());
				if (timeI > timeJ) {
					auto tmp = data[i];
					data[i] = data[j];
					data[j] = tmp;
				}
			}
		}
	}
	else {
		std::cout << "log: Unknown format\n";
	}
}

void dataContainer::clear() {
	data.clear();
}

int dataContainer::size()
{
	return data.size();
}

dataContainer& dataContainer::operator=(const dataContainer& other) {
	this->data.resize(other.data.size());
	for (int i = 0; i < other.data.size(); i++) {
		this->data[i] = other.data[i];
	}
	return *this;
}

std::unordered_map<std::string, dataContainer> groupDistance(dataContainer& inData) {
	std::unordered_map<std::string, dataContainer> result;
	for (int i = 0; i < inData.data.size(); i++) {
		auto dis = std::sqrt(std::pow(inData.data[i].getCoord().x, 2) + std::pow(inData.data[i].getCoord().y, 2));
		if (dis < 100) {
			auto ptr = result.find("До 100");
			if (ptr == result.end()) {
				result["До 100"].addObject(inData.data[i]);
			}
			else {
				ptr->second.addObject(inData.data[i]);
			}
		}
		else if (dis < 1000) {
			auto ptr = result.find("До 1000");
			if (ptr == result.end()) {
				result["До 1000"].addObject(inData.data[i]);
			}
			else {
				ptr->second.addObject(inData.data[i]);
			}
		}
		else if (dis < 10000) {
			auto ptr = result.find("До 10000");
			if (ptr == result.end()) {
				result["До 10000"].addObject(inData.data[i]);
			}
			else {
				ptr->second.addObject(inData.data[i]);
			}
		}
		else {
			auto ptr = result.find("Далеко");
			if (ptr == result.end()) {
				result["Далеко"].addObject(inData.data[i]);;
			}
			else {
				ptr->second.addObject(inData.data[i]);
			}
		}
	}
	return result;
}

std::unordered_map<char, dataContainer> groupName(dataContainer& inData) {
	std::unordered_map<char, dataContainer> result;
	bool hashCreate = true;
	for (int i = 0; i < inData.data.size(); i++) {
		auto curSym = inData.data[i].getName().at(0);
		if (curSym > 'а' && curSym < 'я' || curSym > 'А' && curSym < 'Я') {
			auto ptr = result.find(curSym);
			if (ptr == result.end()) {
				result[curSym].addObject(inData.data[i]);
			}
			else {
				ptr->second.addObject(inData.data[i]);
			}
		}
		else if (hashCreate) {
			hashCreate = false;
			result['#'].addObject(inData.data[i]);
		}
		else {
			result['#'].addObject(inData.data[i]);
		}
	}
	return result;
}

std::unordered_map<std::string, dataContainer> groupType(dataContainer& inData, int N) {
	std::unordered_map<std::string, dataContainer> result;
	for (int i = 0; i < inData.data.size(); i++) {
		auto ptr = result.find(inData.data[i].getType());
		if (ptr == result.end()) {
			result[inData.data[i].getType()].addObject(inData.data[i]);
		}
		else {
			ptr->second.addObject(inData.data[i]);
		}
	}


	// watch
	std::vector<dataContainer> dataSave;
	for (auto it = result.begin(); it != result.end(); it++) {
		if ( (it->second.data.size()) < N) {
			dataSave.push_back(it->second.data);
			result.erase(it--);
		}
	}

	if (dataSave.empty()) {
		return result;
	} 
	result["Разное"] = dataContainer();
	for (int i = 0; i < dataSave.size(); i++) {
		for (int j = 0; j < dataSave[i].data.size(); j++) {
			result["Разное"].addObject(dataSave[i].data[j]);
		}
	}
	return result;
	
}

std::unordered_map<std::string, dataContainer> groupTime(dataContainer& inData) {
	std::unordered_map<std::string, dataContainer> result;
	for (int i = 0; i < inData.data.size(); i++) {
		std::tm time = inData.data[i].getTime();
		std::time_t now = std::time(nullptr);
		
		if (std::mktime(&time) > now) {
			std::cout << "log: invalid time in index " << i << " \n";
			continue;
		}
		std::tm* now_tm = std::localtime(&now);
		now = std::mktime(now_tm);
		if ((time.tm_mday == now_tm->tm_mday) && (time.tm_mon == now_tm->tm_mon) && (time.tm_year == now_tm->tm_year)) {
			result["Сегодня"].addObject(inData.data[i]);
		}
		else if ((time.tm_mday == now_tm->tm_mday - 1) && (time.tm_mon == now_tm->tm_mon) && (time.tm_year == now_tm->tm_year)) {
			result["Вчера"].addObject(inData.data[i]);
		}
		else if ((now_tm->tm_mday - time.tm_mday < 7) && (now_tm->tm_wday - time.tm_wday > 0)) {
			result["На этой неделе"].addObject(inData.data[i]);
		}
		else if ((time.tm_mon == now_tm->tm_mon) && (time.tm_year == now_tm->tm_year)) {
			result["В этом месяце"].addObject(inData.data[i]);
		}
		else if (time.tm_year == now_tm->tm_year) {
			result["В этом году"].addObject(inData.data[i]);
		}
		else {
			result["Ранее"].addObject(inData.data[i]);
		}	
	}
	return result;
}
