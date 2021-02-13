
add_library(fizzbuzz main.cpp)

target_link_libraries(fizzbuzz 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_fizzbuzz main.cpp)
target_link_libraries(test_fizzbuzz PRIVATE fizzbuzz)