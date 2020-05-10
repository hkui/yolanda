cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo3)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
add_subdirectory(math)


# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 添加链接库
target_link_libraries(${PROJECT_NAME} MathFunctions)

SET(CMAKE_INSTALL_PREFIX ./dst/)

#make install时执行的
install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #CMAKE_INSTALL_PREFIX/bin

install(FILES main.c math/mathfun.c math/mathfun.h DESTINATION src) #CMAKE_INSTALL_PREFIX/src






