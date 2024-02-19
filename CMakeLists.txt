cmake_minimum_required(VERSION 3.5.0)
project(globalogic_task_Bozhyka LANGUAGES C CXX)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library(FileSearchLib STATIC FileSearchLib/src/FileSearch.cpp)
target_include_directories(FileSearchLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/FileSearchLib/include)

add_executable(globalogic_task_Bozhyk globalogic_task_Bozhyk/main.cpp) 

target_link_libraries(globalogic_task_Bozhyk PUBLIC FileSearchLib)