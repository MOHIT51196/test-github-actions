cmake_minimum_required(VERSION 3.15)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

project(filesys VERSION 1.1)

#[[ Adding configuration file xxx.h.in ]]
configure_file(config.h.in config.h)
list(APPEND EXTRA_DIRS ${PROJECT_BINARY_DIR})


#[[ Creating a target ]]
add_executable(${PROJECT_NAME} main.cpp)

option(USE_FILER "Simple file IO Utility" ON)

if(USE_FILER)
    #[[ Adding subdirectory with a separate CMakeLists.txt ]]
    add_subdirectory(Filer)
    list(APPEND EXTRA_DIRS Filer)
    list(APPEND EXTRA_LIBS filer)
endif()

#[[ Removed the need of providing path to header file ]]
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_DIRS})

#[[ Linking directories together ]]
target_link_directories(${PROJECT_NAME} PUBLIC ${EXTRA_DIRS})

#[[ Linking libraries together at final stage ]]
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})