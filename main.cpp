#include "QtdataFilter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtdataFilter w;
    w.show();
    return a.exec();
}
