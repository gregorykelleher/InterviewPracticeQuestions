
add_library(first_non_repeating_char main.cpp)

target_link_libraries(first_non_repeating_char 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_first_non_repeating_char main.cpp)
target_link_libraries(test_first_non_repeating_char PRIVATE first_non_repeating_char)