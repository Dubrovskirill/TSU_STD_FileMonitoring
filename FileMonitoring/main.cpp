#include <QCoreApplication>
#include "FileMonitoring.h"
#include "ConsoleLogger.h"

int main(int argc, char *argv[]) {

    QCoreApplication a(argc, argv);

    ConsoleLogger logger;
    FileMonitoring fileMonitor("D:\\STD\\test.txt", &logger); // Укажите путь к файлу

    // Подключаем сигнал к слоту
    QObject::connect(&fileMonitor, &FileMonitoring::fileStatusChanged, &logger, &ConsoleLogger::log);



    return a.exec();
}
