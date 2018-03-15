project(1DCDSolver)
cmake_minimum_required(VERSION 2.8)
#set(CMAKE_CXX_STANDARD 11) only for cmake VERSION < 3.1
set(CMAKE_CXX_FLAGS "-std=c++11")
#set(SOURCE
#   ${SOURCE}
#   ${CMAKE_CURRENT_SOURCE_DIR}/parameter.cpp
#   ${CMAKE_CURRENT_SOURCE_DIR}/c1ddata.cpp
#)
INCLUDE_DIRECTORIES("/m/bulk/sms/pm_HiWi/Jahnke2016/Armadillo20171102/Armadillo_INSTALL/usr/include")
LINK_DIRECTORIES("/m/bulk/sms/pm_HiWi/Jahnke2016/Armadillo20171102/Armadillo_INSTALL/usr/lib64")
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST} cd1ddata.cpp cd1dparameter.cpp cd1dsolver.cpp cd1dinterface.cpp)
target_link_libraries(${PROJECT_NAME} armadillo)

