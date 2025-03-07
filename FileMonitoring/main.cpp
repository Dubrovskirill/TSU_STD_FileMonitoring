#include <QCoreApplication>
#include "FileMonitoringManager.h"
#include "ConsoleLogger.h"
void createFile(const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
    } else {
        qDebug() << "Couldn't open the file for writing:" << file.errorString();
    }

    file.close();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ConsoleLogger logger;
    FileMonitoringManager manager(&logger);

    const int n=4;
    QString arrayFile[n] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt"};
    for(int i=0;i<n;++i){
        createFile(arrayFile[i]);
         manager.addFile(arrayFile[i]);
    }


    QObject::connect(&manager, &FileMonitoringManager::fileStatusChanged, &logger, &ConsoleLogger::log);

    return a.exec();
}
