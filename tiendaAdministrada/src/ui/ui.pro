QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formanadirproducto.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    formanadirproducto.h \
    mainwindow.h

FORMS += \
    formanadirproducto.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../bibliotecaTarea3/release/ -lbibliotecaTarea3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../bibliotecaTarea3/debug/ -lbibliotecaTarea3
else:unix: LIBS += -L$$OUT_PWD/../bibliotecaTarea3/ -lbibliotecaTarea3

INCLUDEPATH += $$PWD/../bibliotecaTarea3
DEPENDPATH += $$PWD/../bibliotecaTarea3

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../bibliotecaTarea3/release/libbibliotecaTarea3.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../bibliotecaTarea3/debug/libbibliotecaTarea3.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../bibliotecaTarea3/release/bibliotecaTarea3.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../bibliotecaTarea3/debug/bibliotecaTarea3.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../bibliotecaTarea3/libbibliotecaTarea3.a
