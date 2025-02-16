set(LIB_NAME logger)
file(GLOB_RECURSE HEADER_FILES "${PROJECT_SOURCE_DIR}/include/${LIB_NAME}/*.h")
file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/${LIB_NAME}/*.cpp")
add_library(${LIB_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${LIB_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
list(APPEND LIBRARY_LIST ${LIB_NAME})
set(LIBRARY_LIST ${LIBRARY_LIST} PARENT_SCOPE)

target_link_libraries(${LIB_NAME} PRIVATE fmt::fmt)
