#include "FileTest.h"
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QStandardPaths>

FileTest::FileTest()
{
}

void FileTest::writeFilesToDisk()
{
    QString name = "test.txt";

    QAndroidJniObject dataDir = QAndroidJniObject::callStaticObjectMethod("android/os/Environment", "getDataDirectory", "()Ljava/io/File;");
    QAndroidJniObject dataPath = dataDir.callObjectMethod( "getAbsolutePath", "()Ljava/lang/String;" );
    qWarning() << "Data Directory Path: " << dataPath.toString();

    QString homePath = QDir::homePath();
    qWarning() << "Home Path: " << homePath;

    QString homePath2 = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qWarning() << "Home Path2: " << homePath;

    QAndroidJniObject mediaDir = QAndroidJniObject::callStaticObjectMethod("android/os/Environment", "getExternalStorageDirectory", "()Ljava/io/File;");
    QAndroidJniObject mediaPath = mediaDir.callObjectMethod( "getAbsolutePath", "()Ljava/lang/String;" );
    QString mediaAbsPath = mediaPath.toString()+"/PIM/";
    qWarning() << "SD Card Path: " << mediaAbsPath;

    QAndroidJniEnvironment env;
    if (env->ExceptionCheck())
    {
        // Handle exception here.
        env->ExceptionClear();
    }

    QFile file(homePath + "/" + name);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text ))
    {
       qDebug() << "File Has Been Created" << endl;
       file.write("TEST DATA");
       file.close();
    }
    else
    {
       qDebug() << "Failed to Create File: " << file.fileName() << endl << file.errorString() << endl;
    }
}

void FileTest::readFilesFromDisk()
{

}
