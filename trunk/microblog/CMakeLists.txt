# Project needs a name of course
project(microblog)

add_definitions (${QT_DEFINITIONS})

set(sourceFiles
    ConfigurationTO.cpp
    ConfigurationStorage.cpp
    MicroblogItem.cpp
	PluginLoader.cpp
	MicroBlog.cpp
)

set(headerFiles
    ConnectionManager.h
	ConfigurationTO.h
    ConfigurationStorage.h
    MicroblogItem.h
	PluginLoader.h
	MicroBlog.h
)

set(QTMOC_SRCS
	PluginLoader.h
	MicroBlog.h
	PluginInterface.h
)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDES}
)

set(libs
    ${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

set(sourceFiles
	${sourceFiles}
	${headerFiles}
)

add_library(microblog SHARED ${sourceFiles} ${QT_MOC_SRCS})

target_link_libraries(
    microblog
	${libs}
    )

install(TARGETS microblog DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)
