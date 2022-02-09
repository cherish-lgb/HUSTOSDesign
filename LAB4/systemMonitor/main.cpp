#include "systemMonitor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    systemMonitor process;
    process.show();
    return a.exec();
}
