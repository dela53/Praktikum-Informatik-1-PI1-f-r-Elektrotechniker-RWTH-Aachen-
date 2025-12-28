QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractmap.cpp \
    addstreet_dialog.cpp \
    bigtown.cpp \
    city.cpp \
    dialog.cpp \
    dijkstra.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mapio.cpp \
    mapiofileinput.cpp \
    mapionrw.cpp \
    smalltown.cpp \
    street.cpp

HEADERS += \
    abstractmap.h \
    addstreet_dialog.h \
    bigtown.h \
    city.h \
    dialog.h \
    dijkstra.h \
    mainwindow.h \
    map.h \
    mapio.h \
    mapiofileinput.h \
    mapionrw.h \
    smalltown.h \
    street.h

FORMS += \
    addstreet_dialog.ui \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS += \
    Streetplanner_de_DE.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Downloads/GGI/Vorlagen/Versuch09/TestFunktionen.txt \
    Doxyfile/html/index.html
