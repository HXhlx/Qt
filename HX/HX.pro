QT += core gui widgets sql charts

TARGET = HX
TEMPLATE = app

SOURCES += \
    main.cpp \
    HX.cpp \
    Administrator.cpp \
    Worker.cpp \
    Consumer.cpp \
    Config.cpp \
    DatabaseManager.cpp

HEADERS += \
    HX.h \
    Administrator.h \
    Worker.h \
    Consumer.h \
    Config.h \
    DatabaseManager.h \
    CryptoHelper.h \
    Validator.h

FORMS += \
    HX.ui \
    Administrator.ui \
    Worker.ui \
    Consumer.ui

RESOURCES += \
    HX.qrc
