#ifndef FILEMONITORINGMANAGER_H
#define FILEMONITORINGMANAGER_H

#include <QObject>
#include <QList>
#include "FileMonitoring.h"


class FileMonitoringManager : public QObject {
    Q_OBJECT

public:
    static FileMonitoringManager& getInstance(QObject* parent = nullptr) {
        static FileMonitoringManager instance(parent);
        return instance;
    }
    void setLogger(ILogger* logger);
    void addFile(const QString& filePath);
    void removeFile(const QString& filePath);

private:
   FileMonitoringManager(QObject* parent = nullptr);
    ~FileMonitoringManager();
    FileMonitoringManager(const FileMonitoringManager&) = delete;
    FileMonitoringManager& operator=(const FileMonitoringManager&) = delete;

    QList<FileMonitoring*> m_fileMonitors;
    ILogger* m_logger=nullptr;
};

#endif // FILEMONITORINGMANAGER_H
