
add_library(pretend_stack main.cpp)

target_link_libraries(pretend_stack 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_pretend_stack main.cpp)
target_link_libraries(test_pretend_stack PRIVATE pretend_stack)