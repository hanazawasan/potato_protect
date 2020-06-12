#include "mainscene.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mywindow w;
    w.show();
    return a.exec();
}
