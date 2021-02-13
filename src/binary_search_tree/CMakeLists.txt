
add_library(binary_search_tree main.cpp)

target_link_libraries(binary_search_tree 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_binary_search_tree main.cpp)
target_link_libraries(test_binary_search_tree PRIVATE binary_search_tree)