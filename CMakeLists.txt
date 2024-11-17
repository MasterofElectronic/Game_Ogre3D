cmake_minimum_required(VERSION 3.15)
project(GunBros_Simplificado)

# Encontrar Ogre 14.3.1
find_package(OGRE 14.3 REQUIRED COMPONENTS Bites Overlay)


#Encontrar SDL2
find_package(SDL2 REQUIRED)

set(SDL2_INCLUDE_DIRS /usr/include/SDL2)
set(SDL2_LIBRARIES /usr/lib/x86_64-linux-gnu/libSDL2.so)

#configure_file(resources.cfg ${CMAKE_BINARY_DIR} COPYONLY)


include_directories(${SDL2_INCLUDE_DIRS})
include_directories(include)

add_executable(GunBros_Simplificado src/main.cpp)

target_link_libraries(GunBros_Simplificado OgreBites OgreOverlay ${SDL2_LIBRARIES})
target_include_directories(GunBros_Simplificado PRIVATE ${OGRE_INCLUDE_DIRS})
