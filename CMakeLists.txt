cmake_minimum_required(VERSION 3.0)
project(Space_Shooter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Collision.cpp src/include/Collision.h src/Ship.cpp src/include/Ship.h src/Util.cpp src/include/Util.h src/Bullet.cpp src/include/Bullet.h src/include/TextureManager.h src/TextureManager.cpp src/BulletManager.cpp src/include/BulletManager.h)
add_executable(Space_Shooter ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Space_Shooter sfml-system sfml-window sfml-graphics)
