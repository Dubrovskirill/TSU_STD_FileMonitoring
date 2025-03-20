#ifndef FILEMONITORINGMANAGER_H
#define FILEMONITORINGMANAGER_H

#include <QObject>
#include <QList>
#include "FileMonitoring.h"
#include "IFileMonitoringManager.h"

class FileMonitoringManager : public QObject, public IFileMonitoringManager {
    Q_OBJECT

public:
    static FileMonitoringManager& getInstance(ILogger* logger, QObject* parent = nullptr) {
        static FileMonitoringManager instance(logger, parent);
        return instance;
    }

    void addFile(const QString& filePath) override;
    void removeFile(const QString& filePath) override;

private:
    FileMonitoringManager(ILogger* logger, QObject* parent = nullptr);
    FileMonitoringManager(const FileMonitoringManager&) = delete;
    FileMonitoringManager& operator=(const FileMonitoringManager&) = delete;

    QList<FileMonitoring*> m_fileMonitors;
    ILogger* m_logger;
};

#endif // FILEMONITORINGMANAGER_H
