PROJECT(microblog)

FIND_PACKAGE(Qt4 REQUIRED)

cmake_minimum_required(VERSION 2.6)

ADD_DEFINITIONS (${QT_DEFINITIONS})

INCLUDE_DIRECTORIES (
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
	${CMAKE_SOURCE_DIR}/microblog
	${CMAKE_SOURCE_DIR}/tests/configurationto
	${QT_INCLUDE_DIR}
)

add_subdirectory(microblog)
add_subdirectory(microblog/plugins)
add_subdirectory(tests/configurationto)