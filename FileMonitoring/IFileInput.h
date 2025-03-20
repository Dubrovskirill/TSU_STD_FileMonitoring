#ifndef IFILEINPUT_H
#define IFILEINPUT_H
#include <QString>

class IFileInput {
public:
    virtual void inputFiles() = 0;
    virtual ~IFileInput() = default;
    virtual QList<QString> getFiles() const = 0;
};
#endif // IFILEINPUT_H
