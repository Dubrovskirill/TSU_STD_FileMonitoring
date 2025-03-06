#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QCoreApplication>
#include <QObject>
#include <QFile>
#include <QTimer>
#include <QProcess>
#include <iostream>
#include <thread>
#include <chrono>
#include "ILogger.h"


class FileMonitoring : public QObject {
    Q_OBJECT

public:
    //accepts a file path and a pointer to the logger object. Initializes variables, creates a timer, and connects it to the slot.
    FileMonitoring(const QString& filePath, ILogger* logger)
        : m_filePath(filePath), m_logger(logger), m_lastSize(-1), m_fileExists(false) {
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &FileMonitoring::checkFile);
        m_timer->start(100);
    }

    void initialize() {
        checkFile(); // Вызываем проверку после подключения сигналов и слотов
    }

signals:
    void fileStatusChanged(const QString& message);

private slots:
    void checkFile() {
        QFile file(m_filePath);
        bool exists = file.exists();
        qint64 size = exists ? file.size() : -1;

        if (exists && !m_fileExists) {
            emit fileStatusChanged(QString("The %1 file has been created. Size: %2 bytes").arg(m_filePath).arg(size));
        } else if (!exists && m_fileExists) {
            emit fileStatusChanged(QString("The %1 file has been deleted.").arg(m_filePath));
        } else if (exists && size != m_lastSize) {

            emit fileStatusChanged(QString("The %1 file has been changed. New size: %2 bytes").arg(m_filePath).arg(size));
        }

        m_lastSize = size;
        m_fileExists = exists;
    }

public slots:
    void logMessage(const QString& message) {
        m_logger->log(message);
    }


private:
    QString m_filePath;
    ILogger* m_logger;
    QTimer* m_timer;
    qint64 m_lastSize;
    bool m_fileExists;
};

#endif // FILEMONITORING_H
