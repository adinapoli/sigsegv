SOURCES += \
    main.cpp \
    GridCell.cpp \
    Grid.cpp \
    GameState.cpp \
    Inventory.cpp \
    HUD.cpp \
    LevelDisplayer.cpp \
    InventoryDisplayer.cpp \
    GameDataManager.cpp \
    Utils.cpp \
    QGraphicsComponent.cpp \
    EnemyCell.cpp \
    ExitCell.cpp

OTHER_FILES += \
    resources/sigsegv.rcc \
    levels/level1.json

RESOURCES += \
    resources/sigsegv.qrc \
    resources/data.qrc

HEADERS += \
    GridCell.hpp \
    Grid.hpp \
    GameState.hpp \
    Inventory.hpp \
    HUD.hpp \
    LevelDisplayer.hpp \
    InventoryDisplayer.hpp \
    GameDataManager.hpp \
    Utils.hpp \
    Exceptions.hpp \
    QGraphicsComponent.hpp \
    EnemyCell.hpp \
    ExitCell.hpp

macx: LIBS += -L$$PWD/libs/ -lgocs -ljson

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

macx: PRE_TARGETDEPS += \
    $$PWD/libs/libgocs.a \
    $$PWD/libs/libjson.a
