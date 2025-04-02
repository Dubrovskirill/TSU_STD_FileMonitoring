#ifndef FILEMONITORINGMANAGER_H
#define FILEMONITORINGMANAGER_H

#include <QObject>
#include <QList>
#include "FileMonitoring.h"


class FileMonitoringManager : public QObject {
    Q_OBJECT

public:
    static FileMonitoringManager& getInstance(ILogger* logger, QObject* parent = nullptr) {
        static FileMonitoringManager instance(logger, parent);
        return instance;
    }

    void addFile(const QString& filePath);
    void removeFile(const QString& filePath);

private:
    FileMonitoringManager(ILogger* logger, QObject* parent = nullptr);
    ~FileMonitoringManager();
    FileMonitoringManager(const FileMonitoringManager&) = delete;
    FileMonitoringManager& operator=(const FileMonitoringManager&) = delete;

    QList<FileMonitoring*> m_fileMonitors;
    ILogger* m_logger;
};

#endif // FILEMONITORINGMANAGER_H
