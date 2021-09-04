option(USE_VCPKG "USE_VCPG" ON)

if(USE_VCPKG)
	include(vcpkg.cmake)
endif()

set(VCPKG_TARGET_TRIPLET "x64-windows")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(UtilityAI)
configure_file(UtilityAIConfig.h.in UtilityAIConfig.hpp)
cmake_minimum_required(VERSION 3.7)

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

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(imgui REQUIRED)
find_package(imgui-sfml REQUIRED)

add_executable("${PROJECT_NAME}" "${PrivateFiles}")

target_include_directories("${PROJECT_NAME}" PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/Inc"
)
target_include_directories("${PROJECT_NAME}" PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/Src"
)

target_link_libraries("${PROJECT_NAME}" PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_sources("${PROJECT_NAME}" PUBLIC ${PublicFiles})
target_sources("${PROJECT_NAME}" PRIVATE ${PrivateFiles})

install(TARGETS "${PROJECT_NAME}" DESTINATION Bin)
