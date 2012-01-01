SOURCES += \
    main.cpp \
    GridCell.cpp \
    Grid.cpp

OTHER_FILES += \
    resources/sigsegv.rcc

RESOURCES += \
    resources/sigsegv.qrc

HEADERS += \
    GridCell.hpp \
    Grid.hpp

macx: LIBS += -L$$PWD/libs/ -lgocs

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

macx: PRE_TARGETDEPS += $$PWD/libs/libgocs.a
