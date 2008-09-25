PROJECT(twittoid)
FIND_PACKAGE(Qt4 REQUIRED)

cmake_minimum_required(VERSION 2.6)

ADD_DEFINITIONS (${QT_DEFINITIONS})
INCLUDE_DIRECTORIES (
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/jsoncpp
	${CMAKE_SOURCE_DIR}/twittoid
        )

SET(APPLICATION_NAME "${PROJECT_NAME}")

INCLUDE_DIRECTORIES(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/twittoid
    ${CMAKE_BINARY_DIR}/jsoncpp/
    ${QT_INCLUDE_DIR}
)

add_subdirectory(twittoid)
add_subdirectory(jsoncpp)
