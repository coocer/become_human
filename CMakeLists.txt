cmake_minimum_required(VERSION 3.15)

# 设置vcpkg 由于cmake是msys2的，所以需要使用msys2的vcpkg x64-mingw-dynamic
set(CMAKE_TOOLCHAIN_FILE "E:/workplace/base/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-mingw-dynamic")

# 设置项目名称和版本
project(become_human VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fmt 相关配置
# find_package(fmt CONFIG REQUIRED)

# 添加 GTest 配置
find_package(GTest CONFIG REQUIRED)

# 设置vcpkg
# set(CMAKE_PREFIX_PATH "${CMAKE_TOOLCHAIN_FILE}/../../../installed/x64-mingw-dynamic")

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 收集源文件
file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE TEST_SOURCES
    "${PROJECT_SOURCE_DIR}/test/*.cpp"
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})
# target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# 添加测试可执行文件
add_executable(test_${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(test_${PROJECT_NAME} 
    PRIVATE GTest::gtest 
    PRIVATE GTest::gtest_main
    PRIVATE GTest::gmock
    PRIVATE GTest::gmock_main
)
# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 添加编译选项
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wno-sign-compare)
endif()

# 安装目标
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)


# cd build 
# cmake ..
# ninja
# ./bin/become_human.exe
# if want to use vcpkg, you need to set CMAKE_TOOLCHAIN_FILE to the path of vcpkg.cmake
# and set CMAKE_PREFIX_PATH to the path of the installed directory
# vcpkg install fmt
