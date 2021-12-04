set(TARGET puzzle)

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -g -Wall -Werror")

add_executable(${TARGET} day1.cpp)
