#include "QtdataFilter.h"

QtdataFilter::QtdataFilter(QWidget *parent) : QMainWindow(parent) {
	container = new dataContainer();
}

QtdataFilter::~QtdataFilter() {
	delete container;
}

//watch
void QtdataFilter::addObject() {
	console->setText("");
	
	for (int i = 0; i < table->rowCount(); i++) {
		bool empty = false;
		coordinats a;
		dataObject cur;
		for (int j = 0; j < table->columnCount(); j++) {
			auto tmp = table->item(i, j);
			if (tmp == NULL) {
				console->setText(console->text() + QString::fromLocal8Bit("Объект не добавлен (Первое пустое поле найденно под индексами: ") + QString::number(i) + " " + QString::number(j) + ")\n");
				empty = true;
				break;
			}
			else {

				if (j == 0) {
					cur.setName(tmp->text().toStdString());
				} 
				if (j == 1) {
					a.x = tmp->text().toDouble();
				} 
				if (j == 2) {
					a.y = tmp->text().toDouble();
					cur.setCoord(a);
				}
				if (j == 3) {
					cur.setType(tmp->text().toStdString());
				}
				if (j == 4) {
					auto time = createTimeFromString(tmp->text().toStdString());
					cur.setTime(time);
				}			
			}	
		}
		if (!empty) {
			container->addObject(cur);
			console->setText(console->text() + QString::fromLocal8Bit("Объект добавлен в контейнер\n"));
		}
	}
	table->clearContents();
}

void QtdataFilter::showObjects() {
	console->setText("");
	console->setText(QString::fromLocal8Bit("Объекты в контейнере (") + QString::number(container->size()) + ")\n");
	for (int i = 0; i < container->size(); i++) {
		auto cur = container->getObject(i);
		auto coord = cur.getCoord();
		auto qName = QString::fromStdString(cur.getName().c_str()).toUtf8();
		auto qType = QString::fromStdString(cur.getType().c_str()).toUtf8();
		console->setText(console->text() + qName + " " + QString::number(coord.x) + " " + QString::number(coord.y) + " " + qType + " " + std::asctime(&cur.getTime()));
	}

}

void QtdataFilter::save() {
	console->setText("");
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("TXT (*.txt)"));
	container->outputData(fileName.toStdString());
	console->setText(QString::fromLocal8Bit("Контейнер сохранен в файл: ") + fileName);
}

void QtdataFilter::stringCount() {
	console->setText("");
	bool flag;
	int count = QInputDialog::getInt(this, tr("QInputDialog::getInt()"), tr("count"), 3, 0, 100, 1, &flag);
	if (flag) {
		console->setText(QString::fromLocal8Bit("Изменено количество строк в таблице: ") + QString::number(count));
		table->setRowCount(count);
	}
}

void QtdataFilter::deleteObject() {
	console->setText("");
	bool flag;
	int toDelete = QInputDialog::getInt(this, tr("QInputDialog::getInt()"), tr("count"), 3, 0, 100, 1, &flag);
	if (flag) {
		container->deleteObject(toDelete);
		console->setText(QString::fromLocal8Bit("Удален элемент с индексом ") + QString::number(toDelete));
	}
}

void QtdataFilter::sortNameUp() {
	console->setText("");
	container->sort("NameUp");
	console->setText(QString::fromLocal8Bit("Контейнер остортирован по имени по возрастанию"));
}

void QtdataFilter::sortNameDown() {
	console->setText("");
	container->sort("NameDown");
	console->setText(QString::fromLocal8Bit("Контейнер остортирован по имени по убыванию"));
}

void QtdataFilter::sortDistanceUp() {
	console->setText("");
	container->sort("DistanceUp");
	console->setText(QString::fromLocal8Bit("Контейнер остортирован по дистанции по возрастанию"));
}

void QtdataFilter::sortDistanceDown() {
	console->setText("");
	container->sort("DistanceDown");
	console->setText(QString::fromLocal8Bit("Контейнер остортирован по дистанции по убыванию"));
}

void QtdataFilter::sortTimeUp() {
	console->setText("");
	container->sort("TimeUp");
	console->setText(QString::fromLocal8Bit("Контейнер остортирован по времени по возрастанию"));
}

void QtdataFilter::sortTimeDown() {
	console->setText("");
	container->sort("TimeDown");
	console->setText(QString::fromLocal8Bit("Контейнер остортирован по времени по убыванию"));
}

void QtdataFilter::groupNameq() {
	console->setText("");
	auto groups = groupName(*container);
	for (auto it : groups) {
		for (int i = 0; i < it.second.size(); i++) {
			auto cur = it.second.getObject(i);
			auto coord = cur.getCoord();
			console->setText(console->text() + QString::fromStdString(cur.getName()) + " " + QString::number(coord.x) + " " + QString::number(coord.y) + " " + QString::fromStdString(cur.getType()) + " " + std::asctime(&cur.getTime()));
			console->setText(console->text() + "\n");
		}
		console->setText(console->text() + "\n");
	}
}

void QtdataFilter::groupDistanceq() {
	console->setText("");
	auto groups = groupDistance(*container);
	for (auto it : groups) {
		for (int i = 0; i < it.second.size(); i++) {
			auto cur = it.second.getObject(i);
			auto coord = cur.getCoord();
			console->setText(console->text() + QString::fromStdString(cur.getName()) + " " + QString::number(coord.x) + " " + QString::number(coord.y) + " " + QString::fromStdString(cur.getType()) + " " + std::asctime(&cur.getTime()));
			console->setText(console->text() + "\n");
		}
		console->setText(console->text() + "\n");
	}
}

void QtdataFilter::groupTimeq() {
	console->setText("");
	auto groups = groupTime(*container);
	for (auto it : groups) {
		for (int i = 0; i < it.second.size(); i++) {
			auto cur = it.second.getObject(i);
			auto coord = cur.getCoord();
			console->setText(console->text() + QString::fromStdString(cur.getName()) + " " + QString::number(coord.x) + " " + QString::number(coord.y) + " " + QString::fromStdString(cur.getType()) + " " + std::asctime(&cur.getTime()));
			console->setText(console->text() + "\n");
		}
		console->setText(console->text() + "\n");
	}
}

void QtdataFilter::groupTypeq() {
	console->setText("");
	bool flag;
	int minCount = QInputDialog::getInt(this, tr("QInputDialog::getInt()"), tr("count"), 2, 0, 100, 1, &flag);
	if (flag) {
		auto groups = groupType(*container, minCount);
		for (auto it : groups) {
			for (int i = 0; i < it.second.size(); i++) {
				auto cur = it.second.getObject(i);
				auto coord = cur.getCoord();
				console->setText(console->text() + QString::fromStdString(cur.getName()) + " " + QString::number(coord.x) + " " + QString::number(coord.y) + " " + QString::fromStdString(cur.getType()) + " " + std::asctime(&cur.getTime()));
				console->setText(console->text() + "\n");
			}
			console->setText(console->text() + "\n");
		}
	}
}

void QtdataFilter::open() {
	console->setText("");
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("TXT (*.txt)"));
	container->inputData(fileName.toStdString());
	console->setText(QString::fromLocal8Bit("Контейнер взят из файла: ") + fileName);

}
