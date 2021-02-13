
add_library(remove_dup_sorted main.cpp)

target_link_libraries(remove_dup_sorted
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_remove_dup_sorted main.cpp)
target_link_libraries(test_remove_dup_sorted PRIVATE remove_dup_sorted)