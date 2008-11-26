project(twittoid)

add_definitions (${QT_DEFINITIONS})

set(sourceFiles
	main.cpp
)

set(QTMOC_SRCS
	../microblog/MicroBlog.h
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

set(sourceFiles
	${sourceFiles}
	${QT_MOC_SRCS}
)

set(libs
	${QT_QTGUI_LIBRARY}
    ${QT_QTCORE_LIBRARY}
    ${QT_QTNETWORK_LIBRARY}
)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDES}
)

add_custom_target(twittoidmoc ALL DEPENDS ${QT_MOC_SRCS})
add_executable(twittoid ${sourceFiles})
add_dependencies(twittoid twittoidmoc)

target_link_libraries(
	twittoid
	microblog
	${libs}
)

install(TARGETS twittoid DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
