set (QT_MIN_VERSION 4.4.0)

add_definitions (${QT_DEFINITIONS})

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDES}
)

set (
    twitterplugin_SRCS
    TwitterPlugin.cpp
)

qt4_automoc(${twitterplugin_SRCS})

add_library(twitterplugin SHARED ${twitterplugin_SRCS}) 

target_link_libraries (
    twitterplugin
    microblog
    ${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
)

install(TARGETS twitterplugin DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
