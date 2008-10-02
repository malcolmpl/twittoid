set (QT_MIN_VERSION 4.4.0)

cmake_minimum_required (VERSION 2.6)

include_directories (
    ${QT_INCLUDES}
)

set (
    plugins_SRCS
    TwitterPlugin.cpp
)

#add_executable (plugs ${plugins_SRCS})

#install (TARGETS plugs DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)