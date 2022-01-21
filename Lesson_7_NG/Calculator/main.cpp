#include "shellcalculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShellCalculator w;
    w.show();
    return a.exec();
}
