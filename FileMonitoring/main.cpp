#include <QCoreApplication>
#include "FileMonitoringManager.h"
#include "ConsoleLogger.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ConsoleLogger logger;
    FileMonitoringingManager manager(&logger);


    manager.addFile("D:\\STD\\test1.txt");
    manager.addFile("D:\\STD\\test2.txt");


    QObject::connect(&manager, &FileMonitoringingManager::fileStatusChanged, &logger, &ConsoleLogger::log);

    return a.exec();
}
