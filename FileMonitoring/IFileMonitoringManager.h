#ifndef IFILEMONITORINGMANAGER_H
#define IFILEMONITORINGMANAGER_H
#include <QString>

class IFileMonitoringManager {
public:

    virtual ~IFileMonitoringManager() = default;
    virtual void addFile(const QString& filePath) = 0;
    virtual void removeFile(const QString& filePath) = 0;
};
#endif // IFILEMONITORINGMANAGER_H
