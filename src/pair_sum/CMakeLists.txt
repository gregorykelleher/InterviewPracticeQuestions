
add_library(pair_sum main.cpp)

target_link_libraries(pair_sum
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_pair_sum main.cpp)
target_link_libraries(test_pair_sum PRIVATE pair_sum)