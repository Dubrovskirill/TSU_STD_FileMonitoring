#include "FileMonitoring.h"

FileMonitoring::FileMonitoring(const QString& filePath, ILogger* logger)
    : m_filePath(filePath), m_logger(logger), m_lastSize(-1), m_fileExists(false) {
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &FileMonitoring::checkFile);
    m_timer->start(100);
}

void FileMonitoring::checkFile() {
    QFile file(m_filePath);
    bool exists = file.exists();
    qint64 size = exists ? file.size() : -1;

    if (exists && !m_fileExists) {
        QString message = QString("The %1 file has been created. Size: %2 bytes").arg(m_filePath).arg(size);
        m_logger->log(message);
        emit fileStatusChanged(message);
    } else if (!exists && m_fileExists) {
        QString message = QString("The %1 file has been deleted.").arg(m_filePath);
        m_logger->log(message);
        emit fileStatusChanged(message);
    } else if (exists && size != m_lastSize) {
        QString message = QString("The %1 file has been changed. New size: %2 bytes").arg(m_filePath).arg(size);
        m_logger->log(message);
        emit fileStatusChanged(message);
    }

    m_lastSize = size;
    m_fileExists = exists;
}
