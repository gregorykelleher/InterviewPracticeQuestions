
add_library(reverse_string main.cpp)

target_link_libraries(reverse_string 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_reverse_string main.cpp)
target_link_libraries(test_reverse_string PRIVATE reverse_string)