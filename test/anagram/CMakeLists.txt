
# Create test executable
add_executable(anagram_test anagram_test.cpp)

# Link test executable to dependent libraries
target_link_libraries(anagram_test
    PRIVATE
        GTest::gtest_main
        ProjectOptions
        Anagram
)

# Enable test discovery
gtest_discover_tests(anagram_test)