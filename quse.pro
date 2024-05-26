QT       += core gui network sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apiclient.cpp \
    category.cpp \
    getingqustions.cpp \
    main.cpp \
    mainwindow.cpp \
    question.cpp \
    repository.cpp

HEADERS += \
    apiclient.h \
    category.h \
    getingqustions.h \
    mainwindow.h \
    question.h \
    repository.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

target.path = $$[QT_INSTALL_EXAMPLES]/sql/cachedtable

# Add OpenSSL libraries
unix: LIBS += -L/usr/lib/x86_64-linux-gnu -lssl -lcrypto
unix: INCLUDEPATH += /usr/include/openssl