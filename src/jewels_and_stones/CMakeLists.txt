
add_library(jewels_and_stones main.cpp)

target_link_libraries(jewels_and_stones
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_jewels_and_stones main.cpp)
target_link_libraries(test_jewels_and_stones PRIVATE jewels_and_stones)