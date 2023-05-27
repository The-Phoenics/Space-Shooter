cmake_minimum_required(VERSION 3.25)
project(Space_Shooter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Collision.cpp Collision.h Ship.cpp Ship.h Util.cpp Util.h Bullet.cpp Bullet.h TextureManager.h TextureManager.cpp BulletManager.cpp BulletManager.h)
add_executable(Space_Shooter ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Space_Shooter sfml-system sfml-window sfml-graphics)