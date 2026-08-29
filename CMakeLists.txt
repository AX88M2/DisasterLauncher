cmake_minimum_required (VERSION 3.30)
project(DisasterLauncher)

set(BUILD_SHARED_LIBS OFF)
set(JANSSON_BUILD_DOCS OFF)
set(ENABLE_CURL_MANUAL OFF)
set(SDL_STATIC ON)
set(SDL_DISABLE_INSTALL ON)

find_package(ZLIB REQUIRED)
find_package(CURL REQUIRED)

add_subdirectory(thirdparty/SDL EXCLUDE_FROM_ALL)
add_subdirectory(thirdparty/jansson)
add_subdirectory(thirdparty/minizip)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.c)

add_executable(DisasterLauncher ${SOURCES})

if (WIN32)
	target_sources(DisasterLauncher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/resources/appicon.rc)
endif ()

target_include_directories(DisasterLauncher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources)

target_link_libraries(DisasterLauncher PRIVATE
		jansson
		SDL3::SDL3-static
		ZLIB::ZLIB
		minizip
		CURL::libcurl
		$<$<CXX_COMPILER_ID:MSVC>: wsock32 ws2_32>
)

target_link_libraries(DisasterLauncher PRIVATE minizip)

install(
  TARGETS DisasterLauncher
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})