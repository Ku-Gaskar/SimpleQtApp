#cmake_minimum_required(VERSION 3.16)
#project(untitled1)
#
#set(CMAKE_CXX_STANDARD 20)
#
#set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.14.2\\5.14.2\\mingw73_64\\lib\\cmake\\Qt5")
#
#find_package(Qt5 COMPONENTS
#  Core
#  REQUIRED)
#
#add_executable(untitled1 main.cpp)
#target_link_libraries(untitled1
#  Qt5::Core
#)
#
#if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#    set(DEBUG_SUFFIX)
#    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif()
#    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
#    if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
#        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
#            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
#        endif()
#    endif()
#    if(EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E make_directory
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
#    endif()
#    foreach(QT_LIB Core )
#        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#                COMMAND ${CMAKE_COMMAND} -E copy
#                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
#                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
#    endforeach(QT_LIB)
#endif()

cmake_minimum_required(VERSION 3.16)

# Название проекта
project(SimpleQtApp LANGUAGES CXX)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Укажите путь к Qt
set(Qt5_DIR "C:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake/Qt5")
list(APPEND CMAKE_PREFIX_PATH "C:/Qt/5.14.2/mingw73_64/lib/cmake")

# Найдите пакеты Qt5
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Укажите исходные файлы
add_executable(SimpleQtApp main.cpp
        mainwindow.cpp
        mainwindow.h)

# Подключите модули Qt
target_link_libraries(SimpleQtApp PRIVATE Qt5::Widgets)