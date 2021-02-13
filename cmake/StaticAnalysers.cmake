
# Include clang-tidy if available
find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
    message("using clang-tidy")
    set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY})
else()
    message(SEND_ERROR "clang-tidy not available")
endif()

# Include cppcheck if available
find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    message("using cppcheck")
    set(CMAKE_CXX_CPPCHECK ${CPPCHECK})
else()
    message(SEND_ERROR "cppcheck not available")
endif()