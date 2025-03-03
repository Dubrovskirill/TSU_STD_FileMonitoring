#ifndef ILOGGER_H
#define ILOGGER_H

#include <QString>

//interface for logging messages
class ILogger {
public:
    virtual void log(const QString &message) = 0;
};

#endif // ILOGGER_H
