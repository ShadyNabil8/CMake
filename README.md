# CMake
#### CMake is a tool that is used to generate a Makefile.

In this example we will make a cmake file to compiler and burn code for atmega avr MCU.

In this README.md file I will write some notes about cmake in general.

## First lines with CMake
```CMake
cmake_minimum_required(VERSION 3.22)
project(HelloWorldCMake)
add_executable(app main.cpp)
target_include_directories(app PUBLIC include/)
```

## Set Variables
```CMake
set(SRC_FILES main.cpp)
add_executable(app ${SRC_FILES})
```

## Print
```CMake
message("Src files: ${SRC_FILES}")
```

## If condition
```CMake
if(EXISTS ${PROJECT_SOURCE_DIR}/main.c)
    message("File is here!!")
else()
    message("File is not here!!")
endif()
```

## Call another CMake file
```CMake
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
```

## Create library
```CMake
add_library(
    math_lib
    math.cpp
    math.h
)
```
#### Link
```CMake
target_link_libraries(app PUBLIC math_lib)
```

## Important vriables

#### Directory of the parent CMake file
```CMake
CMAKE_SOURCE_DIR
```

#### Directory of the current CMake file
```CMake
CMAKE_CURRENT_SOURCE_DIR
```

## Check for C++ version
```CMake
# Set version to 14
set(CMAKE_CXX_STANDARD 14)

# Ensure that the used version is C++ 14
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

## Inintialize external variable form commant line
```CMake
# ext: variable name
cmake -G "Unix Makefiles" -D ext=shady ..
```
## configure_file
```CMake
set(PRODUCT_YEAR 2019)
configure_file(src/defaultconfig.h.in defaultconfig.h)
```
#### defaultconfig.h.in
```c
#define msgtoCMake "Defaultconfig"
#define msgfromCMake "${PRODUCT_YEAR}"
// #define APP_VERSION_MAJOR @APP_VERSION_MAJOR@
// #define APP_VERSION_MINOR @APP_VERSION_MINOR@
#define APP_VERSION_MAJOR ${APP_VERSION_MAJOR}
#define APP_VERSION_MINOR ${APP_VERSION_MINOR}
```
## Targets
Probably the most important item is targets. Targets represent ```executables```, ```libraries```, and ```utilities built by CMake```. Every ```add_library```, ```add_executable```, and ```add_custom_target``` command creates a target. For example, the following command will create a target named “foo” that is a static library, with foo1.c and foo2.c as source files.
```cmake
add_library(foo STATIC foo1.c foo2.c)
```
## Foreach loop
```cmake
# First way
foreach(I IN ITEMS S H A D Y)
    message(STATUS ${I})
endforeach()
# Second way
set(mylst N A B I L)
foreach(I IN LISTS mylst)
    message(STATUS ${I})
endforeach()
```

## While loop
```cmake
set(var 10)
while(var)
    message(STATUS "var: ${var}")
    math(EXPR var "${var} - 1")
endwhile()
```

## Functions
```cmake
set(list 0 1 2 3 )
function(simple arg1 arg2 arg3)
    message("This is ${arg1} function!")
    message("${${arg2}}") #0;1;2;3
    message(${${arg2}}) #0123
    if(${arg3} LESS 5)
        message("arg3 is less than 5")
    elseif(${arg3} EQUAL 5)
    message("arg3 is equal 5")
    else()
        message("arg3 is bigger than 5")
    endif()
endfunction()
simple("simple" list 5)
```

## Store to cache
```cmake
# way 1
option(varcache1 "bool cache var" OFF)
# way 2
set(varcache2 TRUE CACHE BOOL "int cache var")
```

## target_compile_definitions
Specifies compile definitions to use when compiling a given <target>. The named <target> must have been created by a command such as ```add_executable()``` or ```add_library()``` and must not be an ALIAS target.

It is like ```configure_file``` but withput creating a .h file, just path the output program file and the sympol will be added to the code.
```cmake
target_compile_definitions(foo PUBLIC FOO=1)
```
```cpp
/* cpp file */
/* Note that FOO has no defination in .cpp file, only in CMake file */
std::cout << FOO << std::endl;
```

## Set compiler options
```cmake
target_compile_options(app PUBLIC -march=native)
```

## File manipulation(read)
```cmake
# Get the content of the main.cpp file with its order
file(READ main.cpp out1)
message((${out}))

# Get the content of the main.cpp file in a string
file(STRINGS main.cpp out2)
message((${out2}))

# Output: (int main(int argc, char const *argv[]))
file(STRINGS main.cpp out3 REGEX "^int.")
message((${out3}))

# Get all the source files
# Not need to add paths in target_include_directories
file(GLOB_RECURSE  SRCS "*.cpp")
message((${SRCS}))
```
## File manipulation(replace)
```cmake
file(READ main.cpp out1)
STRING(REGEX REPLACE "int" "void" result ${out1})
message((${result}))
```

## macro VS function
```cmake
set(global 5)
macro(myfun)
    set(global 9)
endmacro()
message(${global}) # 5
myfun()
message(${global}) # 9
```
All varialbes in function treated as local vars, so ```set(globalf 9)``` thst is inside the function is like define a new var.

```cmake
set(globalf 5)
function(myfun)
    set(globalf 9)
    # To make it like macro -> set(globalf 9 PARENT_SCOPE)
endfunction()
message(${globalf}) # 5
myfun()
message(${globalf}) # 5
```

## Passing a variable
When you pass a variable, pass it like this to not be confused.
```cmake
set(var 9)
function(fun x)
    message(${var})    
    #message(${${x}})
endfunction()

set(var 9)
macro(func x)
    message(${var})    
    #message(${${x}})
endmacro()
fun(${var}) # like this not fun(var)
func(${var})
```

## Execute CLI command
```cmake
execute_process(COMMAND "ls")
```

## To install usbaps in ubuntu
1. Go to [link](https://www.fischl.de/usbasp/) and download .gz
2. Extract the file.
3. Inside the extracted folder go to ``usbasp.2011-05-28/bin/linux-nonroot``
4. Run command ```./install_rule + sudo cp 99-USBasp.rules /etc/udev/rules.d/99-USBasp.rules```