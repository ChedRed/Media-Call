# Basic project requirements
cmake_minimum_required(VERSION 3.30)
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
elseif(CMAKE_SYSTEM_NAME STREQUAL "MacOS")
    set(CMAKE_OSX_SYSROOT macosx)
endif()
project(MediaCall)


# Set CMake variables
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Main executable
add_executable(mediacall main.cpp)
target_compile_features(mediacall PRIVATE cxx_std_23)


# Set macos executable rpath and result path
set_target_properties(mediacall PROPERTIES INSTALL_RPATH "@executable_path/../Resources" BUILD_WITH_INSTALL_RPATH TRUE)
set_target_properties(mediacall PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/Contents/MacOS")


# Link libraries and include directories
target_link_libraries(mediacall PRIVATE ${CMAKE_SOURCE_DIR}/../Cached/libSDL3.0.dylib)
target_link_libraries(mediacall PRIVATE ${CMAKE_SOURCE_DIR}/../Cached/libSDL3_ttf.0.0.0.dylib)
target_include_directories(mediacall PRIVATE /usr/local/include)


# Make directories for macos app
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/Contents/MacOS")
file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/Contents/Resources")


# Add basic files to macos app
file(COPY ${CMAKE_SOURCE_DIR}/buildfiles/info.plist DESTINATION "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/Contents")
file(COPY ${CMAKE_SOURCE_DIR}/buildfiles/icon.icns DESTINATION "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/Contents/Resources")
file(COPY ${CMAKE_SOURCE_DIR}/buildfiles/FreeSans.ttf DESTINATION "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/Contents/Resources")


# Add resources to macos app
file(COPY ${CMAKE_SOURCE_DIR}/../Cached/libSDL3.0.dylib DESTINATION "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/contents/Resources")
configure_file(${CMAKE_SOURCE_DIR}/../Cached/libSDL3_ttf.0.0.0.dylib "${CMAKE_SOURCE_DIR}/nogit/Media Call.app/contents/Resources/libSDL3_ttf.0.dylib" COPYONLY)
