
add_library(rotated_vector main.cpp)

target_link_libraries(rotated_vector
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_rotated_vector main.cpp)
target_link_libraries(test_rotated_vector PRIVATE rotated_vector)