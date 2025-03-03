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
        checkFile();
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
        system("cls");



        if (exists) {
            if (size != m_lastSize) {
                m_logger->log(QString("The file '%1' exists, the file has been modified. Size: %2 bytes").arg(m_filePath).arg(size));
            } else if (size == 0) {
                m_logger->log(QString("The file '%1' exists, but it is empty.").arg(m_filePath));
            } else {
                m_logger->log(QString("The file '%1' exists. Size: %2 bytes").arg(m_filePath).arg(size));
            }
        } else {
            // Если файл не существует, выводим сообщение
            m_logger->log(QString("The %1 file does not exist.").arg(m_filePath));
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
