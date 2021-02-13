
add_library(valid_parentheses main.cpp)

target_link_libraries(valid_parentheses
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_valid_parentheses main.cpp)
target_link_libraries(test_valid_parentheses PRIVATE valid_parentheses)