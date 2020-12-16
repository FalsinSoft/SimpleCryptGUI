QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    Main.cpp \
    MainWindow.cpp \
    SimpleCrypt.cpp

HEADERS += \
    MainWindow.h \
    SimpleCrypt.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    SimpleCryptGUI.qrc

