#***************************************************************************
# Copyright (C) 2020 Robbert E. Peters (GizMoCuz)
#***************************************************************************

project("minizip" C)

# Set cmake debug postfix to d
set(CMAKE_DEBUG_POSTFIX "d")

set(PROJECT_NAME minizip)

add_library(${PROJECT_NAME} STATIC ioapi.c unzip.c zip.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)

