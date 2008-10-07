set (QT_MIN_VERSION 4.4.0)

include_directories (
    ${QT_INCLUDES}
)

set (
    plugins_SRCS
    TwitterPlugin.cpp
)

target_link_libraries (
    plugins
    ${QT_QTSQL_LIBRARY}
)
