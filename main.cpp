#include <QtWidgets/QApplication>
#include "QtdataFilter.h"

int main(int argc, char *argv[])
{   

    QApplication a(argc, argv);
    QtdataFilter myWindow;
    Ui::QtdataFilterClass caller;
    caller.setupUi(&myWindow);
    myWindow.console = caller.console;
    myWindow.table = caller.tableWidget;
    myWindow.show();
    return a.exec();
}
