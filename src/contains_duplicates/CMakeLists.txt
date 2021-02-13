
add_library(contains_duplicates main.cpp)

target_link_libraries(contains_duplicates
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_vector_contain_duplicates main.cpp)
target_link_libraries(test_vector_contain_duplicates PRIVATE contains_duplicates)