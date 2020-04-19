TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    001_containers_erase-remove_idiom.cpp \
    002_containers_insert_sorted.cpp \
    003_containers_map_try_emplace.cpp \
    main.cpp
