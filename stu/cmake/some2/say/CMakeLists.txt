cmake_minimum_required(VERSION 2.8)

aux_source_directory(. DIR_LIB_SRCS)
project(say)

# 指定生成  链接库
add_library ("$PROJECT_NAME" ${DIR_LIB_SRCS})