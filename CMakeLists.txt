set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
cmake_minimum_required(VERSION 3.22)
project(APP VERSION 7.6)
set(SRC_FILES main.cpp src/led.cpp)
message("Src files: ${SRC_FILES}")
if(EXISTS ${CMAKE_SOURCE_DIR}/main.c)
    message("File is here!!")
else()
    message("File is not here!!")
endif()

# Used to build the other CMake file!
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

add_executable(app ${SRC_FILES})
target_include_directories(app PUBLIC include/ lib/ ${PROJECT_BINARY_DIR})
target_link_libraries(app PUBLIC math_lib)
# message("This is external variable ${ext}")
set(PRODUCT_YEAR 2019)
configure_file(src/defaultconfig.h.in defaultconfig.h)

# if(TARGET math_lib)
# # Targets
# # Probably the most important item is targets.
# # Targets represent executables, libraries, and utilities built by CMake.
# # Every add_library, add_executable, and add_custom_target command creates a target.
# # For example, the following command will create a target named “foo” that is a static library, with foo1.c and foo2.c as source files.
#     message("math lib is here!")
# else()
#     message(FATAL_ERROR "math lib not found")
# endif()


# foreach(I IN ITEMS S H A D Y)
#     message(STATUS ${I})
# endforeach()

# set(mylst N A B I L)
# foreach(I IN LISTS mylst)
#     message(STATUS ${I})
# endforeach()
    

# set(var 10)
# while(var)
#     message(STATUS "var: ${var}")
#     math(EXPR var "${var} - 1")
# endwhile()

# set(list 0 1 2 3 )
# function(simple arg1 arg2 arg3)
#     message("This is ${arg1} function!")
#     message("${${arg2}}") #0;1;2;3
#     message(${${arg2}}) #0123
#     if(${arg3} LESS 5)
#         message("arg3 is less than 5")
#     elseif(${arg3} EQUAL 5)
#     message("arg3 is equal 5")
#     else()
#         message("arg3 is bigger than 5")
#     endif()
# endfunction()
# simple("simple" list 5)

# option(varcache1 "bool cache var" OFF)
# set(varcache2 TRUE CACHE BOOL "int cache var")

# target_compile_definitions(app PUBLIC FOO=1)

# target_compile_options(app PUBLIC -march=native)

# install(FILES "${PROJECT_BINARY_DIR/app}" DESTINATION "${PROJECT_BINARY_DIR}/release")
# install(FILES "${CMAKE_SOURCE_DIR/include/led.h}" DESTINATION "${PROJECT_BINARY_DIR}/indlude")

# file(READ main.cpp out1)
#message((${out}))

# file(STRINGS main.cpp out2)
# message((${out2}))

# file(STRINGS main.cpp out3 REGEX "^int.")
# message((${out3}))
# (int main(int argc, char const *argv[]))

# file(GLOB_RECURSE  SRCS "*.cpp")
#  message((${SRCS}))
