
add_library(water_bottles main.cpp)

target_link_libraries(water_bottles
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_water_bottles main.cpp)
target_link_libraries(test_water_bottles PRIVATE water_bottles)