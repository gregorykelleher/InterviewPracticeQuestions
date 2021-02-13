
add_library(count_words main.cpp)

target_link_libraries(count_words
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_count_words main.cpp)
target_link_libraries(test_count_words PRIVATE count_words)