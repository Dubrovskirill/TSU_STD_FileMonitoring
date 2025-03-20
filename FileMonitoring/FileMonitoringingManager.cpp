#include "FileMonitoringManager.h"

FileMonitoringManager::FileMonitoringManager(ILogger* logger, QObject* parent)
    : QObject(parent), m_logger(logger) {}

void FileMonitoringManager::addFile(const QString& filePath) {
    FileMonitoring* fileMonitor = new FileMonitoring(filePath, m_logger);
    m_fileMonitors.append(fileMonitor);

    QObject::connect(fileMonitor, &FileMonitoring::fileStatusChanged,
                     [this](const QString &message) {
                         m_logger->log(message);
                     });
}

void FileMonitoringManager::removeFile(const QString& filePath) {
    for (int i = 0; i < m_fileMonitors.size(); ++i) {
        if (m_fileMonitors[i]->filePath() == filePath) {
            delete m_fileMonitors[i];
            m_fileMonitors.removeAt(i);
            break;
        }
    }
}
