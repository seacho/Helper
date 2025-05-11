cmake_minimum_required(VERSION 3.5)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    add_subdirectory(mac)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_subdirectory(linux)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    add_subdirectory(windows)
else()
    message(FATAL_ERROR "UnSupported OS: ${CMAKE_SYSTEM_NAME}")
endif()

target_include_directories(platform
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
