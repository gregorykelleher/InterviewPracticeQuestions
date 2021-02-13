
add_library(vowel_count main.cpp)

target_link_libraries(vowel_count
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_vowel_count main.cpp)
target_link_libraries(test_vowel_count PRIVATE vowel_count)