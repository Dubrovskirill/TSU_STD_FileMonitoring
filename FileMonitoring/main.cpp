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

    for (const QString& file : files) {
       fileManager.addFile(file);
    }

    fileManager.setLogger(&logger);


    return a.exec();
}
