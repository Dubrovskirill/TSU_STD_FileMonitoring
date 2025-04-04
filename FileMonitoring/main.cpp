#include <QCoreApplication>
#include "FileMonitoringManager.h"
#include "ConsoleLogger.h"
#include "TestFileInput.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ConsoleLogger logger;
    FileMonitoringManager& fileManager = FileMonitoringManager::getInstance();

    TestFileInput fileInput;
    fileInput.inputFiles();
    QList<QString> files = fileInput.getFiles();
    fileManager.setLogger(&logger);
    for (const QString& file : files) {
       fileManager.addFile(file);
    }


    return a.exec();
}
