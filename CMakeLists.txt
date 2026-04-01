cmake_minimum_required(VERSION 3.15)
project(CrowDemo CXX)
 
set(CMAKE_CXX_STANDARD 17)
 
# 1. Find the Crow package from vcpkg
find_package(Crow REQUIRED)
 
add_executable(my_app main.cpp)
 
# 2. Link Crow
target_link_libraries(my_app PRIVATE Crow::Crow)
 
# 3. CRITICAL: Link the Windows Socket libraries
if(WIN32)
    target_link_libraries(my_app PRIVATE ws2_32 wsock32)
endif()