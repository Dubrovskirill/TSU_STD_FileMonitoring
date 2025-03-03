#ifndef FILEOBSERVER_H
#define FILEOBSERVER_H

#include "IFileObserver.h"
#include "ILogger.h"

class FileObserver : public IFileObserver {
private:
    ILogger *logger;

public:
    FileObserver(ILogger *logger) : logger(logger) {}

    void onFileStatusChanged(const QString &status) override {
        logger->log(status);
    }
};
#endif // FILEOBSERVER_H
