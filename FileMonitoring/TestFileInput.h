#ifndef TESTFILEINPUT_H
#define TESTFILEINPUT_H

#include "IFileInput.h"
#include <QString>
#include <QList>

//creating empty files for further testing
class TestFileInput : public IFileInput {
public:
    explicit TestFileInput();

    void inputFiles() override;
    QList<QString> getFiles() const override;

private:
    QList<QString> m_files;
    void createFile(const QString& filePath);
};

#endif // TESTFILEINPUT_H
