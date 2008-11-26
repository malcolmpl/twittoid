project(test_configurationto)

include_directories(
	   ${QT_INCLUDES}
)

set(sourceFiles
	test_configurationto.cpp
)

set(QTMOC_SRCS
	test_configurationto.h
)

qt4_wrap_cpp(QT_MOC_SRCS ${QTMOC_SRCS})

set(sourceFiles
	${sourceFiles}
	${QT_MOC_SRCS}
)

set(libs
    ${QT_QTCORE_LIBRARY}
	${QT_QTTEST_LIBRARY}
)

add_custom_target(test_configurationtomoc ALL DEPENDS ${QT_MOC_SRCS})
add_executable(test_configurationto ${sourceFiles})
add_dependencies(test_configurationto test_configurationtomoc)

target_link_libraries(
		test_configurationto
		microblog
		${libs}
       )

add_test( configurationtotest ${CMAKE_CURRENT_BINARY_DIR}/tests/test_configurationto )
