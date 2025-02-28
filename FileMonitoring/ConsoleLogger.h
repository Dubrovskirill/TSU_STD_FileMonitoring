#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"
#include <QDebug>
//implementation of the logging interface.
class ConsoleLogger : public ILogger {
public:
    void log(const QString &message) override {
        qDebug() << message; // logging in to the console
    }
};

#endif // CONSOLELOGGER_H
