cmake_minimum_required (VERSION 3.2)

project (ORDERBOOK)

set(VERSION_TYPE "beta" CACHE STRING "version type" FORCE)
site_name(VERSION_HOST) # read hostname to VERSION_HOST
set(VERSION_HOST "${VERSION_HOST}" CACHE STRING "host of build" FORCE)

message(STATUS "")
message(STATUS "    == ${PROJECT_NAME} Project configuration ==")
message(STATUS "")

# Initialize CXXFLAGS
add_compile_options(-std=c++14 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wunused -pedantic -Wno-missing-braces)

find_package(BOOST 1.64 COMPONENTS REQUIRED)

include_directories(${BOOST_INCLUDE_DIR} )

include_directories(include)

add_subdirectory(src)

#-------------------------------------------------------------------------------
# Wrap up of settings printed on build
message(STATUS "")
message(STATUS "    == Final overview for ${PROJECT_NAME} ==")
message(STATUS "Version:              ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} ${VERSION_TYPE} @ ${VERSION_HOST}")
message(STATUS "Install prefix:       ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Compiler:             ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_BUILD_TYPE:     ${CMAKE_BUILD_TYPE}")
message(STATUS "  possible options: Debug Release RelWithDebInfo MinSizeRel")
message(STATUS "  set with ` cmake -DCMAKE_BUILD_TYPE=Debug .. `")
message(STATUS "")

