# Project needs a name of course
project(microblog)

cmake_minimum_required(VERSION 2.6)

add_definitions (${QT_DEFINITIONS})

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDES}
    )
 
# We add our source code here
set(microblog_SRCS
    ConfigurationTO.cpp
    ConfigurationStorage.cpp
    MicroblogItem.cpp
)

add_library(microblog SHARED ${microblog_SRCS}) 

target_link_libraries(
    microblog
    ${QT_QTCORE_LIBRARY}
    )

install(TARGETS microblog DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
