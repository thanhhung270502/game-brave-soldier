cmake_minimum_required(VERSION 3.0.0)
project(sdl2_demo VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()


add_executable(sdl2_demo src/main.cpp src/BaseObject.cpp src/game_map.cpp src/MainObject.cpp)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
target_link_libraries(sdl2_demo SDL2main SDL2 GL SDL2_image SDL2_mixer SDL2_ttf)
# target_link_libraries(sdl2_demo SDL2main SDL2 GL)
# target_link_libraries(sdl2_demo PRIVATE SDL2main SDL2 GL ${SDL_IMAGE_LIBRARIES})
