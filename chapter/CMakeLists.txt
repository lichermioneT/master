cmake_minimum_required(VERSION 3.5)
project(EigenDemo)

# 找到 Eigen3 
find_package(Eigen3 REQUIRED)

add_executable(main test.cc)

# /usr/include/eigen3

# 将 Eigen3 链接到你的 target（自动加入 include dirs）
target_link_libraries(main Eigen3::Eigen)

