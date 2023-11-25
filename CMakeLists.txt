cmake_minimum_required(VERSION 3.22) 
set(CMAKE_SYSTEM_NAME Generic)
set(CURRENT_ATMEGA 16)
set(FRQ 1000000)

set(SRCS main.cpp)


# FORCE means to override the default value.
# Set the compiler to avr-g++ for c++ development.
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
# Set the compiler to avr-gcc++ for c development.
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C compiler" FORCE)
set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "avr-objcopy" FORCE)
# Set variables to carry the flags needed.
set(CMAKE_CXX_FLAGS "-mmcu=atmega${CURRENT_ATMEGA} -O1 -DF_CPU=${1000000}UL")
##################################################################
message(${SRCS})
# Set project name
project(LEDBLink CXX)
set(EXEC ${PROJECT_NAME})
# file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)
# string(REGEX REPLACE "build/[^;]+;?" "" SRCS "${SRCS}")
##################################################################

# This is the name given to the most recently called ``project()``
add_executable(${EXEC}.elf ${SRCS})
target_include_directories(${EXEC}.elf PUBLIC ${CMAKE_SOURCE_DIR}/include)
# target_include_directories(${EXEC} PUBLIC ${CMAKE_SOURCE_DIR})
# Convert .elf to .hex
# ALL here mean to put the flash target in the dependencies of the all tagerget
add_custom_target(gethex ALL
    DEPENDS ${PROJECT_NAME}.elf
    COMMAND ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    ) 
##################################################################
# Here we add a target to burn the hex file. This target will not be auto generated.
add_custom_target(burn 
DEPENDS gethex
COMMAND avrdude -c usbasp -p m${CURRENT_ATMEGA} -B 0.5 -U flash:w:${EXEC}.hex:a
) 









































# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED True)
# cmake_minimum_required(VERSION 3.22)
# project(APP VERSION 7.6)
# set(SRC_FILES main.cpp src/led.cpp)
# message("Src files: ${SRC_FILES}")
# if(EXISTS ${CMAKE_SOURCE_DIR}/main.c)
#     message("File is here!!")
# else()
#     message("File is not here!!")
# endif()

# Used to build the other CMake file!
# add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

# add_executable(app ${SRC_FILES})
# target_include_directories(app PUBLIC include/ lib/ ${PROJECT_BINARY_DIR})
# target_link_libraries(app PUBLIC math_lib)
# # message("This is external variable ${ext}")
# set(PRODUCT_YEAR 2019)
# configure_file(src/defaultconfig.h.in defaultconfig.h)

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
#message((${out1}))

# file(STRINGS main.cpp out2)
# message((${out2}))

# file(STRINGS main.cpp out3 REGEX "^int.")
# message((${out3}))
# (int main(int argc, char const *argv[]))

# file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
#  message((${SRCS}))
#  message((${CMAKE_CURRENT_SOURCE_DIR}))


# file(READ main.cpp out1)
# STRING(REGEX REPLACE  "int" "void" result ${out1})
# message((${result}))

# set(globalm 5)
# macro(myfun )
#     set(globalm 9)
# endmacro()
# message(${globalm}) # 5
# myfun()
# message(${globalm}) # 9

# set(globalf 5)
# function(myfun )
#     set(globalf 9 PARENT_SCOPE)
# endfunction()
# message(${globalf}) # 5
# myfun()
# message(${globalf}) # 5

# set(var 9)
# function(fun x)
#     message(${var})    
#     #message(${${x}})
# endfunction()

# set(var 9)
# macro(func x)
#     message(${var})    
#     #message(${${x}})
# endmacro()
# fun(${var})
# func(${var})

# execute_process(COMMAND "ls")

# set(CMAKE_PREFIX_PATH "/home/shady/vcpkg/vcpkg/installed/x64-linux/share")
# find_package(fmt CONFIG REQUIRED)
# target_link_libraries(app PRIVATE fmt::fmt)
