cmake_minimum_required(VERSION 3.16)

project(MechanicalDesign VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)
#添加数据库模块
aux_source_directory(src SOURCE1)
aux_source_directory(ui SOURCE2)
#一定要单独拿出res.qrc，才可进行auto RCC 操作，把图片编译成二进制文件
set(SRC ${SOURCE1} ${SOURCE2} res.qrc)

add_executable(MechanicalDesign ${SRC})
target_link_libraries(MechanicalDesign PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MechanicalDesign PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include(GNUInstallDirs)
install(TARGETS MechanicalDesign
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
