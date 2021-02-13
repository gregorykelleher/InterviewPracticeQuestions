
# Locate Google Test
find_package(GTest REQUIRED)

# Include Google Test module
include(GoogleTest)

# Add tests
add_subdirectory(anagram)

