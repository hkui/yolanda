cmake_minimum_required(VERSION 2.8)

PROJECT(Demo1)

MESSAGE(WARNING   "${PROJECT_NAME}")    #带警告的输出
MESSAGE(STATUS   "${PROJECT_NAME}")     #正常输出

add_executable("${PROJECT_NAME}" main.c)

