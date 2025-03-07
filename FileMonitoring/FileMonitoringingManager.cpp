#include "FileMonitoringManager.h"


FileMonitoringManager::FileMonitoringManager(ILogger* logger)
    : m_logger(logger) {}


void FileMonitoringManager::addFile(const QString& filePath) {
    FileMonitoring* monitor = new FileMonitoring(filePath, m_logger);
    connect(monitor, &FileMonitoring::fileStatusChanged, this, &FileMonitoringManager::handleFileStatusChanged);
    m_monitors.append(monitor);
}


void FileMonitoringManager::handleFileStatusChanged(const QString& message) {
    emit fileStatusChanged(message);
}
