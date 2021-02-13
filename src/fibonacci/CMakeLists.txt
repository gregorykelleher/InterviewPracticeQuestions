
add_library(fibonacci main.cpp)

target_link_libraries(fibonacci
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_fibonacci main.cpp)
target_link_libraries(test_fibonacci PRIVATE fibonacci)