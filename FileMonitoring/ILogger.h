#ifndef ILOGGER_H
#define ILOGGER_H

#include <QString>
#include <QObject>

//interface for logging messages
class ILogger: public QObject {
     Q_OBJECT
public:
    virtual ~ILogger() = default;
public slots:
    virtual void log(const QString &message) = 0;

};

#endif // ILOGGER_H
