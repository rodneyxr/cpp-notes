cmake_minimum_required(VERSION 3.6)
project(training)

set(CMAKE_CXX_STANDARD 14)

set(SRC src)
add_executable(hello_world ${SRC}/hello_world.cpp)
add_executable(template_example ${SRC}/template_example.cpp)

set(CONTAINERS ${SRC}/containers)
add_executable(associative_containers ${CONTAINERS}/associative_containers.cpp)
add_executable(sequence_containers ${CONTAINERS}/sequence_containers.cpp)
add_executable(unordered_containers ${CONTAINERS}/unordered_containers.cpp)
