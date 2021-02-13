
# Create an interface library for project options
add_library(ProjectOptions INTERFACE)

# Enable compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(ProjectOptions)

# Include GNU standard installation module
include(GNUInstallDirs)

# Install project options library and export as set
install(TARGETS
    ProjectOptions
    EXPORT ProjectOptionsExportSet
)

# Install the project options export set
install(EXPORT ProjectOptionsExportSet
    FILE ProjectOptionsTargets.cmake
    NAMESPACE ProjectOptions::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/ProjectOptions
)