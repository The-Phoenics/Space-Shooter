cmake_minimum_required(VERSION 3.0)

project(Space_Shooter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

#set(SOURCE_FILES src/main.cpp src/Collision.cpp src/include/Collision.h src/Ship.cpp src/include/Ship.h src/Util.cpp src/include/Util.h src/Bullet.cpp src/include/Bullet.h src/include/TextureManager.h src/TextureManager.cpp src/BulletManager.cpp src/include/BulletManager.h)
file(GLOB SOURCE_FILES 
    src/*.cpp
    src/GameStates/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#add_executable(Space_Shooter src/main.cpp src/Collision.cpp src/include/Collision.h src/Ship.cpp src/include/Ship.h src/Util.cpp src/include/Util.h src/Bullet.cpp src/include/Bullet.h src/include/TextureManager.h src/TextureManager.cpp src/BulletManager.cpp src/include/BulletManager.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src/include ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src/GameStates/include)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
