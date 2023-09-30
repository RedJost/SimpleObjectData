cmake_minimum_required(VERSION 3.16)
project(QtdataFilter LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    QtdataFilter.ui
    QtdataFilter.h
    QtdataFilter.cpp
    src/dataObject.cpp
    src/dataContenier.cpp
    include/dataObject.h
    include/dataContanier.h
)

qt_add_executable(QtdataFilter ${PROJECT_SOURCES})

set_target_properties(QtdataFilter
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(QtdataFilter
    PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
