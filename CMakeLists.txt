
cmake_minimum_required(VERSION 3.22)

# C / C++ 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 默认 Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# 工程名称
set(CMAKE_PROJECT_NAME Motor)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# 启用 C、C++ 和 ARM 汇编
project(${CMAKE_PROJECT_NAME} LANGUAGES C CXX ASM)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# STM32 可执行文件
add_executable(${CMAKE_PROJECT_NAME}
        app/Src/app_task.cpp
        app/Inc/app_task.h
        Motor_lib/Src/motor.cpp
        Motor_lib/Inc/motor.h)

# CubeMX 生成的 HAL、FreeRTOS、启动文件
add_subdirectory(cmake/stm32cubemx)

# 用户自己的源文件
target_sources(${CMAKE_PROJECT_NAME} PRIVATE

        # App 应用层
        app/Src/app_task.cpp


        # Motor_lib 电机库
        Motor_lib/Src/motor.cpp
        #Motor_lib/Src/pid.cpp
)

# 用户头文件路径
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE

        ${CMAKE_CURRENT_SOURCE_DIR}/app/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/Motor_lib/Inc
)

# 用户宏定义
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
)

# 保留原工程处理
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# 链接 CubeMX 库
target_link_libraries(${CMAKE_PROJECT_NAME}
        stm32cubemx
)
