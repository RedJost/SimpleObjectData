cmake_minimum_required (VERSION 3.8)

project ("dataFilter")



set(CMAKE_CXX_STANDARD 14)


add_executable(dataFilter "src/dataFilter.cpp" "src/dataObject.cpp" "include/dataObject.h" "include/dataContanier.h" "src/dataContenier.cpp")

target_include_directories(dataFilter PUBLIC src include)