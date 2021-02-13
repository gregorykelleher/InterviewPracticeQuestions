
add_library(number_of_steps main.cpp)

target_link_libraries(number_of_steps
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_number_of_steps main.cpp)
target_link_libraries(test_number_of_steps PRIVATE number_of_steps)