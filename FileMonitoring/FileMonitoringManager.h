#ifndef FILEMONITORINGMANAGER_H
#define FILEMONITORINGMANAGER_H

#include <QObject>
#include <QList>
#include "FileMonitoring.h"

class FileMonitoringManager : public QObject {
    Q_OBJECT

public:
    FileMonitoringManager(ILogger* logger);

    void addFile(const QString& filePath);

private slots:
    void handleFileStatusChanged(const QString& message);

signals:
    void fileStatusChanged(const QString& message);

private:
    QList<FileMonitoring*> m_monitors;
    ILogger* m_logger;
};
#endif // FILEMONITORINGMANAGER_H
