cmake_minimum_required(VERSION 3.10.0)
set(PROJECT_NAME challenge)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

set(SRC_PATH src)

list(APPEND SRC_H
    ${SRC_PATH}/event.hpp
    ${SRC_PATH}/tasks.hpp
)

list(APPEND SRC_C
    ${SRC_PATH}/main.cpp
    ${SRC_PATH}/event.cpp
    ${SRC_PATH}/tasks.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC_H}
    ${SRC_C}
)
