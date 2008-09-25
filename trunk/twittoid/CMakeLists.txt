project(twittoid)

INCLUDE_DIRECTORIES(
	   ${QT_INCLUDES}
	   ${QT_CORE_INCLUDE_DIR}
	   ${QT_QTNETWORK_INCLUDE_DIR}
		 )

SET (twittoid_MOC
    connector.cpp
    )
    
SET (twittoid_SRC
    main.cpp
		)

QT4_AUTOMOC( ${twittoid_MOC}) 
ADD_EXECUTABLE(twittoid ${twittoid_SRC} ${twittoid_MOC})

TARGET_LINK_LIBRARIES(
        twittoid
        jsoncpp
        ${QT_QTGUI_LIBRARY}
        ${QT_QTCORE_LIBRARY}
        ${QT_QTNETWORK_LIBRARY}
       )

INSTALL(TARGETS twittoid DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
