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