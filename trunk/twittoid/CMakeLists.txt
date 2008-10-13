project(twittoid)

add_definitions (${QT_DEFINITIONS})

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
    ${QT_INCLUDE_DIR}
    ${QT_INCLUDES}
)

SET (twittoid_SRC
	main.cpp
	${CMAKE_SOURCE_DIR}/microblog/pluginloader.cpp
		)

QT4_AUTOMOC( ${twittoid_SRC}) 
ADD_EXECUTABLE(twittoid ${twittoid_SRC})

TARGET_LINK_LIBRARIES(
        twittoid
		microblog
        ${QT_QTGUI_LIBRARY}
        ${QT_QTCORE_LIBRARY}
        ${QT_QTNETWORK_LIBRARY}
       )

INSTALL(TARGETS twittoid DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
