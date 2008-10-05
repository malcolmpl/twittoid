project(test_configurationto)

INCLUDE_DIRECTORIES(
	   ${QT_INCLUDES}
		 )

SET (test_configurationto_SRC
	test_configurationto.cpp
	${CMAKE_SOURCE_DIR}/microblog/ConfigurationTO.cpp
		)

QT4_AUTOMOC( ${test_configurationto_SRC}) 
ADD_EXECUTABLE(test_configurationto ${test_configurationto_SRC})

TARGET_LINK_LIBRARIES(
		test_configurationto
		microblog
        ${QT_QTCORE_LIBRARY}
        ${QT_QTTEST_LIBRARY}
       )

ADD_TEST( configurationtotest ${CMAKE_CURRENT_BINARY_DIR}/tests/test_configurationto )
