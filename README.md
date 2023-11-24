# CMake
#### CMake is a tool that is used to generate a Makefile.

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