cmake_minimum_required(VERSION 3.27.0)

# Set global C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create InterviewPracticeQuestions project
project(
    InterviewPracticeQuestions
    VERSION 1.0
    DESCRIPTION "Interview Practice Questions"
    HOMEPAGE_URL "%%github.com/gregorykelleher/interview_practice_questions%%"
    LANGUAGES CXX
)

# Set standard project settings
include(cmake/StandardProjectSettings.cmake)

# set project options
include(cmake/ProjectOptions.cmake)

# set static analysers
include(cmake/StaticAnalysers.cmake)

# Add the src directory to the build
add_subdirectory(src)

# Enable CTest
enable_testing()

# Add the test subdirectory to the build
add_subdirectory(test)
