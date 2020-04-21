TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++17 -fconcepts # -D_GLIBCXX_DEBUG -pedantic

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
    010_containers_priority_queue.cpp \
    011_iterators_custom_iterator.cpp \
    012_iterators_inserters.cpp \
    013_iterators_algorythm_fibbonachy.cpp \
    014_iterators_other_features.cpp \
    015_iterators_zip.cpp \
    016_lambdas.cpp \
    017_lambdas_functions_concat.cpp \
    main.cpp
