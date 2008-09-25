project(jsoncpp)

include( ${QT_USE_FILE})

INCLUDE_DIRECTORIES(
	   ${QT_INCLUDES}
	   ${QT_CORE_INCLUDE_DIR}
	   ${QT_QTNETWORK_INCLUDE_DIR}
     ${CMAKE_SOURCE_DIR}/jsoncpp
		 )

SET (jsoncpp_SRC
    json_batchallocator.h
    json_internalarray.inl
    json_internalmap.inl
    json_reader.cpp
    json_value.cpp
    json_valueiterator.inl
    json_writer.cpp
    json/autolink.h
    json/config.h
    json/forwards.h
    json/json.h
    json/reader.h
    json/value.h
    json/writer.h
		)

ADD_LIBRARY(jsoncpp SHARED ${jsoncpp_SRC})

TARGET_LINK_LIBRARIES(
        jsoncpp
        ${QT_QTGUI_LIBRARY}
        ${QT_QTCORE_LIBRARY}
        ${QT_QTNETWORK_LIBRARY}
       )

INSTALL(TARGETS jsoncpp DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
