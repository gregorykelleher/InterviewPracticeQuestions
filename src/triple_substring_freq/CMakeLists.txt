
add_library(triple_substring_freq main.cpp)

target_link_libraries(triple_substring_freq
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_triple_substring_freq main.cpp)
target_link_libraries(test_triple_substring_freq PRIVATE triple_substring_freq)