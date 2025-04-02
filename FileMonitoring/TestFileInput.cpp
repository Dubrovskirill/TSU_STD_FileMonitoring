#include "TestFileInput.h"

#include "TestFileInput.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

TestFileInput::TestFileInput() {}

void TestFileInput::inputFiles() {
    const int n = 4;
    QString arrayFile[n] = {"test1.txt", "test2.txt", "test3.txt", "test4.txt"};
    for (int i = 0; i < n; ++i) {
        createFile(arrayFile[i]);
        m_files.append(arrayFile[i]);
    }
}

void TestFileInput::createFile(const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    } else {
        qDebug() << "Couldn't open the file for writing:" << file.errorString();
    }
    file.close();
}

QList<QString> TestFileInput::getFiles() const {
    return m_files;
}
