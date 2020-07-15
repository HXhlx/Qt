#include "HX.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HX hx;
    hx.show();
    return a.exec();
}
