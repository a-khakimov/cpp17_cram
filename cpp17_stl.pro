TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    001_containers_erase-remove_idiom.cpp \
    002_containers_insert_sorted.cpp \
    003_containers_map_try_emplace.cpp \
    004_containers_map_insert_with_hints.cpp \
    005_containers_modify_map_key.cpp \
    006_containers_use_unordered_map_for_custom_types.cpp \
    007_containers_stack_rpm.cpp \
    008_containers_map_word_frequency.cpp \
    009_containers_multimap_search_long_texts.cpp \
    main.cpp
