cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo2)

# 查找目录下的所有源文件 并将名称保存到 DIR_SRCS 变量,也可以起其他名称
aux_source_directory(. DIR_SRCS)


# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})
