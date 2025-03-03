#ifndef IFILEOBSERVER_H
#define IFILEOBSERVER_H

#include <QString>

//used to notify about changes in a file
class IFileObserver {
public:
    virtual void onFileChanged(const QString& filePath, bool exists, qint64 size) = 0;
};

#endif // IFILEOBSERVER_H
