cmake_minimum_required(VERSION 3.5)

project(StaticLibraryTest CXX)

# The relative path from `CMAKE_CURRENT_SOURCE_DIR`.
set(SOURCES_DIR "sources")

#-------------------------------------------------------------------------------
#
#-------------------------------------------------------------------------------
if(WIN32)
	if(MSVC)
		if(MSVC14)
			#[[
			if(CMAKE_CONFIGURATION_TYPES)
				set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Multi config types" FORCE)
			endif()
			]]
		else()
			message(FATAL_ERROR "You are using an unsupported MSVC version!")
		endif()
	elseif()
		message(FATAL_ERROR "You are using an unsupported Windows compiler!")
	endif()
elseif(UNIX)
	if(NOT CMAKE_BUILD_TYPE)
		set(CMAKE_BUILD_TYPE Release CACHE STRING "Force a Release build." FORCE)
	endif()
	option(FORCE_32BIT_BUILD "Force a 32bit compile on 64bit" OFF)
	set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wconversion -Wdisabled-optimization -Wendif-labels -Wfloat-equal -Winit-self -Winline -Wlogical-op -Wmissing-include-dirs -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo -Wswitch-default -Wswitch-enum -Wunsafe-loop-optimizations -Wvariadic-macros -Wwrite-strings ")
	set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
	set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")
	set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -s -DNDEBUG -march=native")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3 -Og -pg")
else()
	message(FATAL_ERROR "You are on an unsupported platform!")
endif()

add_definitions(-D_UNICODE -DUNICODE)

#-------------------------------------------------------------------------------
# Fetch files.
#-------------------------------------------------------------------------------
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" ${SOURCES_DIR}/*.h)
file(GLOB_RECURSE SOURCE_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" ${SOURCES_DIR}/*.cpp)
set(ALL_FILES ${HEADER_FILES} ${SOURCE_FILES})

#-------------------------------------------------------------------------------
# Define a grouping for source files in IDE project generation.
#-------------------------------------------------------------------------------
if(WIN32)
	if(MSVC)
		foreach(FILE IN LISTS ALL_FILES)
			get_filename_component(RESULT ${FILE} EXT)
			if(RESULT STREQUAL ".h")
				get_filename_component(FILTER ${FILE} DIRECTORY)
				string(REGEX REPLACE "^${SOURCES_DIR}" "Header Files" FILTER ${FILTER})
				string(REPLACE "/" "\\" FILTER ${FILTER})
				source_group("${FILTER}" FILES ${FILE})
			elseif(RESULT STREQUAL ".cpp")
				get_filename_component(FILTER ${FILE} DIRECTORY)
				string(REGEX REPLACE "^${SOURCES_DIR}" "Source Files" FILTER ${FILTER})
				string(REPLACE "/" "\\" FILTER ${FILTER})
				source_group("${FILTER}" FILES ${FILE})
			else()
			endif()
		endforeach()
	endif()
endif()

#-------------------------------------------------------------------------------
#
#-------------------------------------------------------------------------------
include_directories(../StaticLibrary/include)
link_directories(../StaticLibrary/lib/${CMAKE_BUILD_TYPE})

add_executable(${PROJECT_NAME} ${ALL_FILES})

target_link_libraries(${PROJECT_NAME} StaticLibrary)

if(FORCE_32BIT_BUILD)
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
endif()

#-------------------------------------------------------------------------------
# Install.
#-------------------------------------------------------------------------------
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin/Debug CONFIGURATIONS Debug)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin/Release CONFIGURATIONS Release)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin/MinSizeRel CONFIGURATIONS MinSizeRel)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin/RelWithDebInfo CONFIGURATIONS RelWithDebInfo)
