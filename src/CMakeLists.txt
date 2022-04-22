cmake_minimum_required(VERSION 3.14)

project(status-cpp-scaffold-app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
      main.cpp
      qml.qrc
)

add_executable(${PROJECT_NAME}
  ${PROJECT_SOURCES}
)

add_subdirectory(core)
add_subdirectory(plugins)

target_link_libraries(${PROJECT_NAME} PRIVATE core)

# add_subdirectory(Modules/Chat)
# target_link_libraries(my-qml-plugins PRIVATE ChatPlugin)

# set(QML_IMPORT_PATH ${CMAKE_BINARY_DIR};${QML_IMPORT_PATH} CACHE STRING "Extra qml import paths for QtCreator" FORCE)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME}
  PRIVATE Qt5::Core Qt5::Quick)
