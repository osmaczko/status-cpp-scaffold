project(wallet-plugin)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick Qml REQUIRED)

set(QML_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/qml;${QML_IMPORT_PATH} CACHE STRING "Extra qml import paths for QtCreator" FORCE)
list(REMOVE_DUPLICATES QML_IMPORT_PATH)

add_library(${PROJECT_NAME} SHARED src/WalletPlugin.cpp qml/wallet.qrc)
target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Quick Qt5::Qml)

# Move qmldir and qml files near to plugin lib,
# so it can be correctly loaded by QmlEngine
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/qml/Wallet
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/
)
