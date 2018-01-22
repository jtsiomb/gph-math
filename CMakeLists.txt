cmake_minimum_required(VERSION 2.8.8)
project(gph-math)

include(GNUInstallDirs)
include(GenerateExportHeader)

set(SO_MAJOR 0)
set(SO_MINOR 1)

file(GLOB hdr "src/*.h")
file(GLOB inl "src/*.inl")
list(APPEND hdr ${inl})
file(GLOB src "src/*.cc")

add_definitions(-DGPH_NAMESPACE)

add_library(gmath SHARED ${src} ${hdr})
add_library(gmath-static STATIC ${src} ${hdr})

set_target_properties(gmath PROPERTIES VERSION ${SO_MAJOR}.${SO_MINOR})
set_target_properties(gmath PROPERTIES SOVERSION ${SO_MAJOR})

if(MSVC)
	set_target_properties(gmath PROPERTIES PREFIX "lib")
	set_target_properties(gmath PROPERTIES IMPORT_PREFIX "lib")
	set_target_properties(gmath-static PROPERTIES PREFIX "lib")

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244 /wd4996")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall")
endif()

if(WIN32)
	generate_export_header(gmath
		BASE_NAME GPH_MATH
		EXPORT_MACRO_NAME GPH_MATH_API
		EXPORT_FILE_NAME dllexport.h
		STATIC_DEFINE GPH_MATH_STATIC)
	include_directories(${PROJECT_BINARY_DIR})
	set_target_properties(gmath-static PROPERTIES COMPILE_FLAGS -DGPH_MATH_STATIC)
else()
	set_target_properties(gmath-static PROPERTIES OUTPUT_NAME gmath)
endif()

install(TARGETS gmath
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(TARGETS gmath-static
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${hdr} DESTINATION include/gmath)
if(WIN32)
	install(FILES ${PROJECT_BINARY_DIR}/dllexport.h DESTINATION include/gmath)
endif()
