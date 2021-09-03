cmake_minimum_required(VERSION 3.7)

set(ExternalFolder "${CMAKE_CURRENT_SOURCE_DIR}/External")


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(UtilityAIConfig.h.in UtilityAIConfig.hpp)

project(UtilityAI)

add_executable("${PROJECT_NAME}" "Src/Main.cpp")

set(SFML_DIR "${ExternalFolder}/SFML-2.5.1")
add_subdirectory("${SFML_DIR}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

set(SFML_STATIC_LIBRARIES true)

target_include_directories(${PROJECT_NAME}
PUBLIC
${SFML_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
PUBLIC
${SFML_LIBRARIES}
${SFML_DEPENDENCIES}
)


target_include_directories("${PROJECT_NAME}" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Inc>"
	"$<INSTALL_INTERFACE:Inc>"
)

target_include_directories("${PROJECT_NAME}" PRIVATE
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Src>"
	"$<INSTALL_INTERFACE:Src>"
)

file(GLOB_RECURSE PublicFiles 
	CMAKE_CONFIGURE_DEPENDS 
	"Inc/*.h"
	"Inc/*.hpp"
)

file(GLOB_RECURSE PrivateFiles 
	CMAKE_CONFIGURE_DEPENDS 
	"Src/*.h"
	"Src/*.hpp"
	"Src/*.cpp"
)

#target_link_libraries()

target_sources("${PROJECT_NAME}" PUBLIC ${PublicFiles})
target_sources("${PROJECT_NAME}" PRIVATE ${PrivateFiles})

install(TARGETS "${PROJECT_NAME}" DESTINATION Bin)
