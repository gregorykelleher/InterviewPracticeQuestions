
add_library(nums_smaller_than_current main.cpp)

target_link_libraries(nums_smaller_than_current
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_nums_smaller_than_current main.cpp)
target_link_libraries(test_nums_smaller_than_current PRIVATE nums_smaller_than_current)