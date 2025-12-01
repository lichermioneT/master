cmake_minimum_required( VERSION 2.8 )
project( useEigen )

set( CMAKE_BUILD_TYPE "Release" )  # 定义变量
set( CMAKE_CXX_FLAGS "-O3" )       # CMAKE_CXX_FLAGS 里面有很多变量的

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" ) # 头文件的包含 eigen， eigen没有库文件的，只有头文件的

# in osx and brew install
# include_directories( /usr/local/Cellar/eigen/3.3.3/include/eigen3 )

add_executable( eigenMatrix eigenMatrix.cpp ) # 生成头文件的
