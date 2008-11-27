project(twitterplugin)

add_definitions (${QT_DEFINITIONS})

set (sourceFiles
    TwitterPlugin.cpp
)

set(headerFiles
	TwitterPlugin.h
)

set(QTMOC_SRCS
	TwitterPlugin.h
	../PluginInterface.h
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

set(sourceFiles
	${sourceFiles}
	${headerFiles}
)

set(libs
    ${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDES}
)

add_library(twitterplugin SHARED ${sourceFiles} ${QT_MOC_SRCS}) 

target_link_libraries(
    twitterplugin
    microblog
    ${libs}
)

install(TARGETS twitterplugin DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
