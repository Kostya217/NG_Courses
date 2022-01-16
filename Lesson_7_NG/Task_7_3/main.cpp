#include "spinbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpinBox w;
    w.show();
    return a.exec();
}
