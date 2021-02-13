
add_library(longest_substring_non_repeating main.cpp)

target_link_libraries(longest_substring_non_repeating 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_longest_substring_non_repeating main.cpp)
target_link_libraries(test_longest_substring_non_repeating PRIVATE longest_substring_non_repeating)