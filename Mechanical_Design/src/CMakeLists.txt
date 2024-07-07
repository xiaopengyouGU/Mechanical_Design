cmake_minimum_required(VERSION 3.10)
project(a_test VERSION 1.0)

aux_source_directory(src SOURCE)

include_directories(include)

add_executable(a_test ${SOURCE})