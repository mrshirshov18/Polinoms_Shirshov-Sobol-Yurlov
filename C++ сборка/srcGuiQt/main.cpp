#include "PolinomMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PolinomMain w;
    w.show();
    return a.exec();
}
