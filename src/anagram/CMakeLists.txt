# Create anagram library
add_library(Anagram anagram.cpp)

# Add include directories for building and installing anagram
target_include_directories(Anagram PUBLIC  
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# add project options
target_link_libraries(Anagram PRIVATE ProjectOptions)

# Include module for GNU standard installation directories
include(GNUInstallDirs)

# Install library and executable and export as a set
install(TARGETS
    Anagram
    EXPORT AnagramExportSet
)

# Install the export set
install(EXPORT AnagramExportSet
    FILE AnagramTargets.cmake
    NAMESPACE Anagram::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Anagram
)