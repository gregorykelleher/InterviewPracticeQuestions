
add_library(smallest_positive main.cpp)

target_link_libraries(smallest_positive 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_smallest_positive main.cpp)
target_link_libraries(test_smallest_positive PRIVATE smallest_positive)