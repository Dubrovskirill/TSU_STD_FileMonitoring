#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QTimer>
#include <iostream>
#include <thread>
#include <chrono>
#include "ILogger.h"


class FileMonitoring : public QObject {
    Q_OBJECT

public:
    FileMonitoring(const QString& filePath, ILogger* logger)
        : m_filePath(filePath), m_logger(logger), m_lastSize(-1), m_fileExists(false) {
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &FileMonitoring::checkFile);
        m_timer->start(100);
    }

signals:
    void fileChanged(const QString& filePath, bool exists, qint64 size);

private slots:
    void checkFile() {
        QFile file(m_filePath);
        bool exists = file.exists();
        qint64 size = exists ? file.size() : -1;

        if (exists && size != m_lastSize) {
            m_logger->log(QString("The file exists, the file has been modified. Size: %1 byte").arg(size));
            emit fileChanged(m_filePath, exists, size);
        } else if (exists && size == 0) {
            m_logger->log("The file exists, but it is empty.");
        } else if (!exists && m_fileExists) {
            m_logger->log("The file does not exist.");
        }

        m_lastSize = size;
        m_fileExists = exists;
    }

private:
    QString m_filePath;
    ILogger* m_logger;
    QTimer* m_timer;
    qint64 m_lastSize;
    bool m_fileExists;
};

#endif // FILEMONITORING_H
