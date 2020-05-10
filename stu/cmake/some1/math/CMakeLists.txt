cmake_minimum_required (VERSION 2.8)

aux_source_directory(. DIR_LIB_SRCS) #只会找原文件，不会.h文件

foreach(i ${DIR_LIB_SRCS})
    message(STATUS ${i})
endforeach(i)

# 指定生成 MathFunctions 链接库
add_library (MathFunctions ${DIR_LIB_SRCS})