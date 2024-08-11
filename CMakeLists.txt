cmake_minimum_required(VERSION 3.10)

project(Mechanical_Design VERSION 1.1)

include_directories(include include/DriveDesign include/Frame include/Part include/PartDesign)

aux_source_directory(src/DriveDesign SOURCE1)
aux_source_directory(src/Part SOURCE2)
aux_source_directory(src/Frame SOURCE3)
aux_source_directory(src/PartDesign SOURCE4)

set(SOURCE ${SOURCE1} ${SOURCE2} ${SOURCE3} ${SOURCE4})

add_executable(a_design ${SOURCE})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
