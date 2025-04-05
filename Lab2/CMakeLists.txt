cmake_minimum_required(VERSION 3.27)
project(Lab2New)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab2New App.cpp
        SortedMultiMap.cpp
        SortedMultiMap.h
        SMMIterator.cpp
        SMMIterator.h
        ShortTest.cpp
        ShortTest.h
        ExtendedTest.cpp
        ExtendedTest.h
        ValueIterator.cpp
        ValueIterator.h)
