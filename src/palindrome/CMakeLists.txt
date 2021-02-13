
add_library(palindrome main.cpp)

target_link_libraries(palindrome
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_palindrome main.cpp)
target_link_libraries(test_palindrome PRIVATE palindrome)