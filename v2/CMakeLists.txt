cmake_minimum_required(VERSION 2.8)
# project(aaa CXX)
# set(Boost_INCLUDE_DIR /usr/local/src/boost_1_46_1)
# set(Boost_LIBRARY_DIR /usr/local/src/boost_1_46_1/stage/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

# add_library(scp)
# add_subdirectory(scp)
# file(GLOB_RECURSE sources *.h *.c *.cxx *.cpp *.hpp *.hxx scp/*.c scp/*.h)
file(GLOB_RECURSE sources *.c *.cxx *.cpp)
message(STATUS "sources" ${sources})
# file(GLOB_RECURSE sources ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.c)
add_executable(aaa ${sources})

target_link_libraries(aaa ${Boost_LIBRARIES} ssh)

