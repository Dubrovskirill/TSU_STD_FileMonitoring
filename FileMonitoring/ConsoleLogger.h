#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"
#include <QDebug>
#include <QObject>
#include <iostream>
//implementation of the ILogger interface that outputs messages to the console
class ConsoleLogger : public QObject, public ILogger {
    Q_OBJECT
public:
    void log(const QString& message) override {
        system("cls");
        std::cout << message.toStdString() << std::endl;
    }
};

#endif // CONSOLELOGGER_H
