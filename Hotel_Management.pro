QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookingdialog.cpp \
    bookroomdialog.cpp \
    checkoutdialog.cpp \
    hotel.cpp \
    main.cpp \
    mainwindow.cpp \
    roomavailabledialog.cpp

HEADERS += \
    bookingdialog.h \
    bookroomdialog.h \
    checkoutdialog.h \
    hotel.h \
    mainwindow.h \
    roomavailabledialog.h

FORMS += \
    bookingdialog.ui \
    bookroomdialog.ui \
    checkoutdialog.ui \
    mainwindow.ui \
    roomavailabledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
