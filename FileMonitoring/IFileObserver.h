#ifndef IFILEOBSERVER_H
#define IFILEOBSERVER_H

#include <QString>

//observer interface
class IFileObserver {
public:
    virtual void onFileStatusChanged(const QString &status) = 0;
};

#endif // IFILEOBSERVER_H
