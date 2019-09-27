
cmake_minimum_required(VERSION 3.1)

project(AlienTD VERSION 1.0
                  DESCRIPTION "AlienTD"
                  LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
  ${SDL2_INCLUDE_DIR}
  ${SDL2_IMAGE_INCLUDE_DIR}
  ${SDL2_TTF_INCLUDE_DIR}
)

file(GLOB SOURCES src/*.cpp)

add_executable(game ${SOURCES})


target_link_libraries(game ${SDL2_LIBRARY})
target_link_libraries(game ${SDL2_TTF_LIBRARY})
target_link_libraries(game ${SDL2_IMAGE_LIBRARY})
