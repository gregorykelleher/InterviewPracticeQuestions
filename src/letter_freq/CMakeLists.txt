
add_library(letter_freq main.cpp)

target_link_libraries(letter_freq 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_letter_freq main.cpp)
target_link_libraries(test_letter_freq PRIVATE letter_freq)