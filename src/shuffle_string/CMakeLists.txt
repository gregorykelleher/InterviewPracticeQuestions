
add_library(shuffle_string main.cpp)

target_link_libraries(shuffle_string
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_shuffle_string main.cpp)
target_link_libraries(test_shuffle_string PRIVATE shuffle_string)