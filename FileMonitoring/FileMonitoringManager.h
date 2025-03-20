#ifndef FILEMONITORINGMANAGER_H
#define FILEMONITORINGMANAGER_H

#include <QObject>
#include <QList>
#include "FileMonitoring.h"
#include "IFileMonitoringManager.h"

class FileMonitoringManager : public QObject, public IFileMonitoringManager {
    Q_OBJECT

public:
    FileMonitoringManager(ILogger* logger, QObject* parent = nullptr);

    void addFile(const QString& filePath) override;
    void removeFile(const QString& filePath) override;

private:
    QList<FileMonitoring*> m_fileMonitors;
    ILogger* m_logger;
};

#endif // FILEMONITORINGMANAGER_H
