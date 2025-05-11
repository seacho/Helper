cmake_minimum_required(VERSION 3.5)

add_library(platform OBJECT requestRootAuthorization.c)
add_library(platform_static STATIC $<TARGET_OBJECTS:platform>)



target_link_libraries(platform
    PRIVATE
    "-framework CoreFoundation"
    "-framework Security"
)
