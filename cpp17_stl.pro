TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++1z -fconcepts # -D_GLIBCXX_DEBUG -pedantic

LIBS += -ltbb

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
    018_lambdas_predicats.cpp \
    019_lambdas_multicall.cpp \
    020_lambdas_transform_if.cpp \
    021_lambdas_cartesian_product.cpp \
    022_algo_basic.cpp \
    023_algo_find.cpp \
    024_algo_clamp.cpp \
    025_algo_string_search.cpp \
    026_algo_std_sample.cpp \
    027_algo_next_permutation.cpp \
    028_algo_merge.cpp \
    029_complex_algos_prefix_tree.cpp \
    030_complex_algos_fourier_transform.cpp \
    031_complex_algos_inner_product.cpp \
    032_complex_algos_malderbrot.cpp \
    033_complex_algos_split.cpp \
    034_complex_algos_gather.cpp \
    035_complex_algos_remove_whitespaces.cpp \
    036_complex_algos_string_compression_decompression.cpp \
    037_custom_string_class.cpp \
    038_regex.cpp \
    039_opt_std_ratio.cpp \
    040_opt_std_chrono.cpp \
    041_opt_std_optional.cpp \
    042_opt_std_apply.cpp \
    043_opt_std_tuple.cpp \
    044_opt_std_any.cpp \
    045_opt_std_variant.cpp \
    046_opt_std_memory.cpp \
    047_opt_legacy_shared_ptr.cpp \
    048_opt_shared_members.cpp \
    049_opt_random_generator.cpp \
    050_opt_rand_dist.cpp \
    051_mt_execution.cpp \
    052_mt_sleep.cpp \
    main.cpp

DISTFILES += \
    db.txt
