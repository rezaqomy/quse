QT       += core gui network sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller.cpp \
    aboutus.cpp \
    main.cpp \
    mainwindow.cpp\
    apiclient.cpp \
    category.cpp \
    getingcategory.cpp \
    getingqustions.cpp \
    question.cpp \
    repository.cpp \
    score.cpp

HEADERS += \
    aboutus.h \
    mainwindow.h \
    controller.h \
    apiclient.h \
    category.h \
    getingcategory.h \
    getingqustions.h \
    question.h \
    repository.h \
    score.h

FORMS += \
    aboutus.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc


target.path = $$[QT_INSTALL_EXAMPLES]/sql/cachedtable

# Add OpenSSL libraries
unix: LIBS += -L/usr/lib/x86_64-linux-gnu -lssl -lcrypto
unix: INCLUDEPATH += /usr/include/openssl
