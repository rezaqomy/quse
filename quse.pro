<<<<<<< HEAD
QT       += core gui
=======
QT       += core gui network sql widgets
>>>>>>> connect-requests

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
<<<<<<< HEAD
=======
TEMPLATE = app
>>>>>>> connect-requests

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h
=======
    apiclient.cpp \
    category.cpp \
    getingcategory.cpp \
    getingqustions.cpp \
    main.cpp \
    mainwindow.cpp \
    question.cpp \
    repository.cpp

HEADERS += \
    apiclient.h \
    category.h \
    getingcategory.h \
    getingqustions.h \
    mainwindow.h \
    question.h \
    repository.h
>>>>>>> connect-requests

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
<<<<<<< HEAD
=======

target.path = $$[QT_INSTALL_EXAMPLES]/sql/cachedtable

# Add OpenSSL libraries
unix: LIBS += -L/usr/lib/x86_64-linux-gnu -lssl -lcrypto
unix: INCLUDEPATH += /usr/include/openssl
>>>>>>> connect-requests
