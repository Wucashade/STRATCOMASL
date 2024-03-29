﻿# CMakeList.txt : CMake project for Othello-Game, include source and define
# project specific logic here.
#

# Add source to this project's executable.
cmake_minimum_required(VERSION 3.20)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_library(SDL2_LIBRARY NAME SDL2)

find_package(Osmium REQUIRED)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(ZLIB REQUIRED)
find_package(BZip2 REQUIRED)
find_package(EXPAT REQUIRED)


message ([STATUS] "SDL2_INCLUDE_DIRS" ${SDL2_INCLUDE_DIR})
message ([STATUS] "SDL2_LIBRARIES" ${SDL2_LIBRARY})
message ([STATUS] "SDL2_IMAGE_INCLUDE_DIR" ${SDL2_IMAGE_INCLUDE_DIR})
message ([STATUS] "SDL2_TTF_INCLUDE_DIR" ${SDL2_TTF_INCLUDE_DIR})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TFF_INCLUDE_DIRS} ${OSMIUM_INCLUDE_DIRS} "${CMAKE_SOURCE_DIR}/include")           
include_directories(${CMAKE_SOURCE_DIR}/include/protozero)

add_executable (STRATCOMALS "src/main.cpp" "src/Window.cpp" "src/Map.cpp" "src/Menu.cpp" "src/CustomSDLFunctions.cpp"
                              "src/MapEntity.cpp" "src/Weapon.cpp" "src/Missile.cpp" "src/OsmDataHandler.cpp")



target_link_libraries(STRATCOMALS ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SDL2_ttf::SDL2_ttf ${OSMIUM_LIBRARIES} 
                      ZLIB::ZLIB BZip2::BZip2 EXPAT)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET STRATCOMALS PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
