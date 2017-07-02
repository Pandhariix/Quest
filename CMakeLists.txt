project(Quest)

cmake_minimum_required(VERSION 3.3)
add_definitions(-std=c++11)

set(SRC_DIR src)
set(LIB_DIR libs)
set(LIB_SFML_DIR ${LIB_DIR}/SFML)

include_directories(
    ${SRC_DIR}
    ${LIB_SFML_DIR}/include
    )

link_directories(
    ${LIB_SFML_DIR}/build
    )


set(SOURCES 
    ${SRC_DIR}/character.cpp
    ${SRC_DIR}/character.h
    ${SRC_DIR}/coordinates.h
    ${SRC_DIR}/decoritem.cpp
    ${SRC_DIR}/decoritem.h
    ${SRC_DIR}/drawableobject.cpp
    ${SRC_DIR}/drawableobject.h
    ${SRC_DIR}/imagemanager.cpp
    ${SRC_DIR}/imagemanager.h
    ${SRC_DIR}/loadgamemenu.cpp
    ${SRC_DIR}/loadgamemenu.h
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/map.cpp
    ${SRC_DIR}/map.h
    ${SRC_DIR}/optionsmenu.cpp
    ${SRC_DIR}/optionsmenu.h
    ${SRC_DIR}/player.cpp
    ${SRC_DIR}/player.h  
    ${SRC_DIR}/soundmanager.cpp
    ${SRC_DIR}/soundmanager.h
    ${SRC_DIR}/startmenu.cpp
    ${SRC_DIR}/startmenu.h
    )

add_executable(${PROJECT_NAME} ${SRC_DIR}/main.cpp ${SOURCES})
#[[target_link_libraries(SpheroController PRIVATE
  "${LIB_SDL_DIR}/build/libSDL2main.a"
  "${LIB_SDL_DIR}/build/libSDL2.a"
  )]]