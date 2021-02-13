
# Set Release as the default build type
set(default_build_type "Release")

# Set the build type to Release if not already set
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
        STRING "Choose the type of build (Debug, Release, RelWithDebInfo, MinSizeRel)" FORCE)
endif()

# Specify the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Specify the output directory for libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include CCache for compilation caching if available
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    message("using ccache")
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
else()
    message("ccache not available")
endif()

# Include Interprocedural Optimisation
include(CheckIPOSupported)

# Enable Interprocedural Optimisation if available
check_ipo_supported(RESULT result OUTPUT output)
if(result)
    message("using interprocedural optimisation")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(SEND_ERROR "IPO not available: ${output}")
endif()

# Generate and install project config
include(cmake/GenerateAndInstallConfig.cmake)

# Configure CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_SOURCE_IGNORE_FILES
    /.git
    /.vscode
    /.*build.*
    /\\\\.gitignore
    /\\\\.DS_Store
)
include(CPack)
