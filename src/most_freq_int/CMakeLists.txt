
add_library(most_freq_int main.cpp)

target_link_libraries(most_freq_int
    project_options 
    project_warnings 
    CONAN_PKG::ms-gsl)

add_executable(test_most_freq_int main.cpp)
target_link_libraries(test_most_freq_int PRIVATE most_freq_int)