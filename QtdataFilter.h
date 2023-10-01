#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtdataFilter.h"
#include "ui_add.h"

class QtdataFilter : public QMainWindow
{
    Q_OBJECT

public:
    QtdataFilter(QWidget *parent = nullptr);
    ~QtdataFilter();

private:
    Ui::QtdataFilterClass ui;
};
