#ifndef FILEMONITORING_H
#define FILEMONITORING_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTimer>
#include <QList>
#include "IFileObserver.h"
#include "ILogger.h"


class FileMonitoring: public QObject{
    Q_OBJECT

public:
    FileMonitoring();
};

#endif // FILEMONITORING_H
