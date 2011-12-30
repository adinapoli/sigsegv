SOURCES += \
    main.cpp \
    GridCell.cpp

OTHER_FILES += \
    resources/sigsegv.rcc

RESOURCES += \
    resources/sigsegv.qrc

HEADERS += \
    GridCell.hpp

macx: LIBS += -L$$PWD/libs/ -lgocs

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

macx: PRE_TARGETDEPS += $$PWD/libs/libgocs.a
