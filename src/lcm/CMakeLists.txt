
add_library(lcm main.cpp)

target_link_libraries(lcm
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_lcm main.cpp)
target_link_libraries(test_lcm PRIVATE lcm)