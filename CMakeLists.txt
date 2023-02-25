cmake_minimum_required(VERSION 3.23)
project(Efficient_personalized_pageRank_algorithm_Cpp)

set (CMAKE_CXX_STANDARD 17)
add_subdirectory(Google_tests/lib)
include_directories(Google_tests/lib/googletest)
include_directories(Google_tests/lib/googlemock)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_executable(cppDis
        personalised_pagerank_module/personalised_pagerank.cpp
        personalised_pagerank_module/personalised_pagerank.hpp
        personalised_pagerank_module/personalised_pagerank_test.cpp

)
target_link_libraries(cppDis gtest gtest_main)


