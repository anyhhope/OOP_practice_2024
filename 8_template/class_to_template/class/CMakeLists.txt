add_library(number number.hpp number.cpp)

add_executable(test test.cpp)
target_link_libraries(test number)
