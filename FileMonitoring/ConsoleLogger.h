#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"
#include <QDebug>
#include <iostream>
//implementation of the ILogger interface that outputs messages to the console
class ConsoleLogger : public ILogger {
public:
    void log(const QString& message) override {
        std::cout << message.toStdString() << std::endl;
    }
};

#endif // CONSOLELOGGER_H
