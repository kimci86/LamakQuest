cmake_minimum_required(VERSION 3.1)

# project name
project(lamak)

# enable C++11
set(CMAKE_CXX_STANDARD 11)

# header path
include_directories(include)

# setup SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED audio graphics window system)
include_directories(${SFML_INCLUDE_DIR})

# files
file(GLOB_RECURSE header_files "${PROJECT_SOURCE_DIR}/include/*")
file(GLOB_RECURSE source_files "${PROJECT_SOURCE_DIR}/src/*")

# executable
add_executable(${CMAKE_PROJECT_NAME} ${header_files} ${source_files})

# link
target_link_libraries(${CMAKE_PROJECT_NAME} ${SFML_LIBRARIES})

# install rules
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION .)
install(DIRECTORY "${PROJECT_SOURCE_DIR}/assets" DESTINATION .)
install(DIRECTORY "${PROJECT_SOURCE_DIR}/levels" DESTINATION .)
