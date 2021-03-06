QT -= gui
QT += network

TEMPLATE = lib
DEFINES += API_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delete.cpp \
    get.cpp \
    post.cpp \
    put.cpp \
    restmethod.cpp


HEADERS += \
    api_global.h \
    delete.h \
    get.h \
    httpmethods.h \
    parameter.h \
    post.h \
    put.h \
    restmethod.h \
    unittest.h


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
