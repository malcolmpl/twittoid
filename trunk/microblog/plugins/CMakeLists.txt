project(twitterplugin)

add_definitions (${QT_DEFINITIONS})

set (sourceFiles
    TwitterPlugin.cpp
)

set(QTMOC_SRCS
	TwitterPlugin.h
	../PluginInterface.h
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

set(sourceFiles
	${sourceFiles}
	${QT_MOC_SRCS}
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

add_custom_target(twitterpluginmoc ALL DEPENDS ${QT_MOC_SRCS})
add_library(twitterplugin SHARED ${sourceFiles}) 
add_dependencies(twitterplugin twitterpluginmoc)

target_link_libraries(
    twitterplugin
    microblog
    ${libs}
)

install(TARGETS twitterplugin DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)
