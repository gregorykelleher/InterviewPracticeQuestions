
add_library(dup_char main.cpp)

target_link_libraries(dup_char
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_dup_char main.cpp)
target_link_libraries(test_dup_char PRIVATE dup_char)