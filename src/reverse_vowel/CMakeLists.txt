
add_library(reverse_vowel main.cpp)

target_link_libraries(reverse_vowel 
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_reverse_vowel main.cpp)
target_link_libraries(test_reverse_vowel PRIVATE reverse_vowel)