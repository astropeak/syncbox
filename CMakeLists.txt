cmake_minimum_required(VERSION 2.8)
# set(Boost_INCLUDE_DIR /usr/local/src/boost_1_46_1)
# set(Boost_LIBRARY_DIR /usr/local/src/boost_1_46_1/stage/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

file(GLOB sources *.h *.c *.cxx *.cpp *.hpp *.hxx)
add_executable(aaa ${sources})

target_link_libraries(aaa ${Boost_LIBRARIES} )

