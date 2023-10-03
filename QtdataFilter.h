#pragma once
#include <QtWidgets/QMainWindow>
#include "QFileDialog.h"
#include "QInputDialog.h"
#include "ui_QtdataFilter.h"
#include "dataContanier.h"

class QtdataFilter : public QMainWindow
{
    Q_OBJECT

    dataContainer* container;

public:
    QtdataFilter(QWidget *parent = nullptr);
    ~QtdataFilter();

    QLabel* console;
    QTableWidget* table;

public slots:
    void addObject();
    void showObjects();
    void save();
    void stringCount();
    void deleteObject();
    void sortNameUp();
    void sortNameDown();
    void sortDistanceUp();
    void sortDistanceDown();
    void sortTimeUp();
    void sortTimeDown();
    void groupNameq();
    void groupDistanceq();
    void groupTimeq();
    void groupTypeq();
    void open();

};


