cmake_minimum_required(VERSION 3.27)
project(
    logger
    VERSION 0.1.0
    DESCRIPTION "project description"
    LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(./cpm/CPM.cmake)
set(CPM_SOURCE_CACHE /home/foxrly/.cache/CPM)

CPMAddPackage("gh:fmtlib/fmt#10.2.1")

set(LIBRARY_LIST fmt::fmt)

add_subdirectory(src)

if(PROJECT_IS_TOP_LEVEL)
    message(STATUS "Project is top level")
    enable_testing()
    include(GoogleTest)

    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found - no docs will be generated")
    endif()

    message("${LIBRARY_LIST}")
    add_subdirectory(app)
    add_subdirectory(test)
    file(CREATE_LINK
        "${PROJECT_BINARY_DIR}/compile_commands.json"
        "${PROJECT_SOURCE_DIR}/compile_commands.json"
        SYMBOLIC
    )
endif()
