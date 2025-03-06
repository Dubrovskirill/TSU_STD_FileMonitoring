#ifndef FileMonitoringINGMANAGER_H
#define FileMonitoringINGMANAGER_H

#include <QObject>
#include <QList>
#include "FileMonitoring.h"

class FileMonitoringingManager : public QObject {
    Q_OBJECT

public:
    FileMonitoringingManager(ILogger* logger) : m_logger(logger) {}

    void addFile(const QString& filePath) {
        FileMonitoring* monitor = new FileMonitoring(filePath, m_logger);
        connect(monitor, &FileMonitoring::fileStatusChanged, this, &FileMonitoringingManager::handleFileStatusChanged);
        m_monitors.append(monitor);
    }

private slots:
    void handleFileStatusChanged(const QString& message) {
        emit fileStatusChanged(message);
    }

signals:
    void fileStatusChanged(const QString& message);

private:
    QList<FileMonitoring*> m_monitors;
    ILogger* m_logger;
};
#endif // FileMonitoringINGMANAGER_H
