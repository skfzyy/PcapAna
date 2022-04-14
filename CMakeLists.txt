cmake_minimum_required(VERSION 3.20)
project(PCapAna)

set(CMAKE_CXX_STANDARD 14)

add_executable(PCapAna main.cpp PcapAnalysis.hpp "Dataframe.hpp" "IPData.hpp")
