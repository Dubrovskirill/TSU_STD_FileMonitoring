#include "FileMonitoringManager.h"

FileMonitoringManager::FileMonitoringManager(QObject* parent)
    : QObject(parent) {}

FileMonitoringManager::~FileMonitoringManager() {
    qDeleteAll(m_fileMonitors);
    m_fileMonitors.clear();
}

void FileMonitoringManager::setLogger(ILogger* logger) {

    m_logger = logger;
    for (FileMonitoring* fileMonitor : m_fileMonitors) {
        fileMonitor->setLogger(m_logger);
    }
}

void FileMonitoringManager::addFile(const QString& filePath) {
    FileMonitoring* fileMonitor = new FileMonitoring(filePath,  m_logger);
    m_fileMonitors.append(fileMonitor);
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
