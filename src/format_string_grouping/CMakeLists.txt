
add_library(format_string_grouping main.cpp)

target_link_libraries(format_string_grouping
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_format_string_grouping main.cpp)
target_link_libraries(test_format_string_grouping PRIVATE format_string_grouping)