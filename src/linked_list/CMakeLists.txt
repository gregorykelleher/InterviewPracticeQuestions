
add_library(linked_list main.cpp)

target_link_libraries(linked_list 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_linked_list main.cpp)
target_link_libraries(test_linked_list PRIVATE linked_list)