cmake_minimum_required(VERSION 3.16)

project(tank_game_2d VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(apptank_game_2d
    src/main.cpp
)

qt_add_qml_module(apptank_game_2d
    URI tank_game_2d
    QML_FILES
        resources/Main.qml
    SOURCES
        include/core/eventbus.hpp
        include/systems/gamecontroller.hpp
        src/systems/gamecontroller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptank_game_2d PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptank_game_2d
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptank_game_2d
    PRIVATE Qt6::Quick
)

install(TARGETS apptank_game_2d
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
