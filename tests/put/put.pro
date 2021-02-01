QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_puttest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../api/release/ -lapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../api/debug/ -lapi
else:unix: LIBS += -L$$OUT_PWD/../../api/ -lapi

INCLUDEPATH += $$PWD/../../api
DEPENDPATH += $$PWD/../../api
