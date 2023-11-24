cmake_minimum_required(VERSION 3.16)
project(Space_Shooter LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

file(GLOB SOURCE_FILES
    src/*.cpp
    src/Animation/*.cpp
    src/Audio/*.cpp
    src/GameStates/*cpp
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-audio)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Animation/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Audio/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameStates/include
)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})





# cmake_minimum_required(VERSION 3.0)

# project(Space_Shooter)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# # Set the path to SFML
# if(WIN32)
#     set(SFML_DIR "<path to sfml>\\lib\\cmake\\SFML")
# endif()

# # Add the source files to your project
# file(GLOB SOURCE_FILES 
#     src/*.cpp
#     src/GameStates/*.cpp
#     src/Animation/*.cpp
#     src/Audio/*.cpp
# )

# # Add the executable target
# add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# # Set the include directories
# target_include_directories(${PROJECT_NAME} PUBLIC 
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/include
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/Animation/include
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/GameStates/include
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/Audio/include
# )

# # Find SFML package
# find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# # Link SFML libraries
# target_link_libraries(${PROJECT_NAME} 
#     sfml-system 
#     sfml-window 
#     sfml-graphics
#     sfml-audio
# )
