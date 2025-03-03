#include <QCoreApplication>
#include "FileMonitoring.h"
#include "ConsoleLogger.h"

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    ConsoleLogger logger;
    FileMonitoring fileMonitor("D:\\STD\\test.txt", &logger);

    return a.exec();
}
