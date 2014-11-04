QT += quick androidextras positioning multimediawidgets network

CONFIG += debug

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources

SOURCES += \
    main.cpp \
    notificationclient.cpp \
    GpsClient.cpp \
    FileTest.cpp \
    NetworkTest.cpp

OTHER_FILES += \
    qml/main.qml \
    android-sources/src/org/qtproject/example/notification/NotificationClient.java \
    android-sources/AndroidManifest.xml

RESOURCES += \
    main.qrc

HEADERS += \
    notificationclient.h \
    GpsClient.h \
    FileTest.h \
    NetworkTest.h

