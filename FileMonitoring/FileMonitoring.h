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
    FileMonitoring(const QString& filePath, ILogger* logger);

signals:
    void fileStatusChanged(const QString& message);

private slots:
    void checkFile();

public slots:
    void logMessage(const QString& message);

private:
    QString m_filePath;
    ILogger* m_logger;
    QTimer* m_timer;
    qint64 m_lastSize;
    bool m_fileExists;
};

#endif // FILEMONITORING_H
