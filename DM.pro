QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mainwindow.cpp \
    modules/Integer/Integer.cpp \
    modules/Natural/Natural.cpp \
    modules/Polynomial/Polynomial.cpp \
    modules/Rational/Rational.cpp \
    modules/utils/utils.cpp \
    main.cpp \

HEADERS += \
    UI/mainwindow.h \
    modules/Integer/Integer.h \
    modules/Interfaces/Model.h \
    modules/Natural/Natural.h \
    modules/Polynomial/Polynomial.h \
    modules/Rational/Rational.h \
    modules/utils/utils.h \

FORMS += \
    UI/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = DM.ico
ICON = myapp.icns
