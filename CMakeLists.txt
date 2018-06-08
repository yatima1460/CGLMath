cmake_minimum_required(VERSION 3.0.0)
project(CGLMath VERSION 0.2.0)

include(CTest)
enable_testing()

file(GLOB SRC_FILES src/*.c include/cglmath/*.h)
add_library(CGLMath ${SRC_FILES})

include_directories(include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
