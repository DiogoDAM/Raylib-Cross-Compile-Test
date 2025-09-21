cmake_minimum_required(VERSION 3.10)
project(meu_jogo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game main.cpp)


if(WIN32)
    message(STATUS "Compile to Windows")

	set(RAYLIB_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/raylib/include")
	set(RAYLIB_LIBRARY "${CMAKE_SOURCE_DIR}/libs/raylib/libraylib.dll.a")

	target_include_directories(Game PRIVATE ${RAYLIB_INCLUDE_DIR})
	target_link_libraries(Game ${RAYLIB_LIBRARY})

    target_link_libraries(Game opengl32 gdi32 winmm dsound)
elseif(UNIX AND NOT APPLE)
    message(STATUS "Compile to Linux")

	target_link_libraries(Game raylib)

    target_link_libraries(Game GL m pthread dl rt X11)

endif()

