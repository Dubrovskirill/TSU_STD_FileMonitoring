#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include "ILogger.h"

class FileMonitoring : public QObject {
    Q_OBJECT

public:
    // Accepts a file path and a pointer to the logger object.
    FileMonitoring(const QString& filePath, ILogger* logger);
    QString filePath() const { return m_filePath; }
    void setLogger(ILogger* logger) {
        m_logger = logger;
    }

signals:
    void fileStatusChanged(const QString& message);

private slots:
    void checkFile();

private:
    QString m_filePath;
    ILogger* m_logger;
    QTimer* m_timer;
    qint64 m_lastSize;
    bool m_fileExists;
};

#endif // FILEMONITORING_H
