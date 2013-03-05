#include <QApplication>
#include "clocks.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clocks w;
    w.show();
    
    return a.exec();
}
