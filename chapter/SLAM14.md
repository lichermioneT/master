# SLAM14

**SLAM : Simultaneous Localization and Mapping**

**同时定位与地图构建**



## Chapter1

**1引言**

![image-20251126185944433](/home/lic/.config/Typora/typora-user-images/image-20251126185944433.png)



![image-20251126190106813](/home/lic/.config/Typora/typora-user-images/image-20251126190106813.png)



![image-20251126190146892](/home/lic/.config/Typora/typora-user-images/image-20251126190146892.png)





![image-20251126190302148](/home/lic/.config/Typora/typora-user-images/image-20251126190302148.png)



![image-20251126190620778](/home/lic/.config/Typora/typora-user-images/image-20251126190620778.png)

### 第一部分:数学基础

### 第二部分:视觉SLAM

### 第三部分:其他



## Chapter2

**内外兼修**

![image-20251126191003144](/home/lic/.config/Typora/typora-user-images/image-20251126191003144.png)



**传感器的配置**

![image-20251126191105911](/home/lic/.config/Typora/typora-user-images/image-20251126191105911.png)



**环境中配置传感器**

![image-20251126191209607](/home/lic/.config/Typora/typora-user-images/image-20251126191209607.png)



**相机分类**

![image-20251126191355624](/home/lic/.config/Typora/typora-user-images/image-20251126191355624.png)



**相纸之间的差距**

![image-20251126191444190](/home/lic/.config/Typora/typora-user-images/image-20251126191444190.png)



**单目相机的缺点**

![image-20251126191540293](/home/lic/.config/Typora/typora-user-images/image-20251126191540293.png)



**单目相机**

![image-20251126191634058](/home/lic/.config/Typora/typora-user-images/image-20251126191634058.png)



**双面相机**

![image-20251126191727582](/home/lic/.config/Typora/typora-user-images/image-20251126191727582.png)



**深度相机**

![image-20251126191820635](/home/lic/.config/Typora/typora-user-images/image-20251126191820635.png)



**共同点**

![image-20251126191923588](/home/lic/.config/Typora/typora-user-images/image-20251126191923588.png)



**视觉SLAM的做法**

![image-20251126192000302](/home/lic/.config/Typora/typora-user-images/image-20251126192000302.png)





![image-20251126192240978](/home/lic/.config/Typora/typora-user-images/image-20251126192240978.png)



```
新图像进来
    ↓
前端（视觉里程计） → 快速算出当前位姿 + 新3D点
    ↓
如果这帧是关键帧 → 交给后端局部BA优化
    ↓
同时把这帧放进“词袋数据库”
    ↓
回环检测模块不断检索：有没有历史帧和当前帧很像？
    ↓ 是 → 加上回环约束 → 触发全局优化（后端）
    ↓ 否 → 继续往前走
    ↓
最终所有优化好的关键帧位姿 + 地图点 → 输出给建图模块
```





![image-20251126192329188](/home/lic/.config/Typora/typora-user-images/image-20251126192329188.png)

![image-20251126192400203](/home/lic/.config/Typora/typora-user-images/image-20251126192400203.png)

![image-20251126192416878](/home/lic/.config/Typora/typora-user-images/image-20251126192416878.png)





**SLAM数学问题**

![image-20251126192537023](/home/lic/.config/Typora/typora-user-images/image-20251126192537023.png)

![image-20251126192606690](/home/lic/.config/Typora/typora-user-images/image-20251126192606690.png)

![image-20251126192725493](/home/lic/.config/Typora/typora-user-images/image-20251126192725493.png)



**cmake**

````


## ✅ 1. 基本结构模板

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(CMAKE_CXX_STANDARD 17)

set(SRC main.cpp src/a.cpp src/b.cpp)
add_executable(my_app ${SRC})
target_link_libraries(my_app PRIVATE pthread)
```

---

## ✅ 2. 添加头文件路径

```cmake
include_directories(include)
# 或现代写法
target_include_directories(my_app PUBLIC include)
```

---

## ✅ 3. 添加源文件

```cmake
aux_source_directory(src SRC_LIST)
add_executable(my_app ${SRC_LIST})
```

---

## ✅ 4. 链接库

### 🔹 系统库

```cmake
target_link_libraries(my_app PRIVATE pthread dl m)
```

### 🔹 自己的 .a / .so

```cmake
link_directories(${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(my_app PRIVATE mylib)
```

---

## ✅ 5. find_package 查找外部库

### OpenCV

```cmake
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(my_app PRIVATE ${OpenCV_LIBS})
```

### Eigen

```cmake
find_package(Eigen3 REQUIRED)
target_link_libraries(my_app PRIVATE Eigen3::Eigen)
```

### Pangolin

```cmake
find_package(Pangolin REQUIRED)
target_link_libraries(my_app PRIVATE ${Pangolin_LIBRARIES})
```

---

## ✅ 6. 编译选项

```cmake
add_compile_options(-Wall -Wextra -O2)
# 或
target_compile_options(my_app PRIVATE -O3 -march=native)
```

---

## ✅ 7. Debug / Release

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

---

## ✅ 8. 控制输出路径

```cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
```

---

## ✅ 9. 定义宏

```cmake
add_definitions(-DDEBUG)
# 或
target_compile_definitions(my_app PRIVATE DEBUG)
```

---

## ✅ 10. 添加子目录（多模块工程常用）

```cmake
add_subdirectory(src/moduleA)
add_subdirectory(src/moduleB)
```

---

## ✅ 11. 构建静态库/动态库

```cmake
add_library(my_lib STATIC src/a.cpp src/b.cpp)
# or
# add_library(my_lib SHARED src/a.cpp src/b.cpp)

target_include_directories(my_lib PUBLIC include)
```

---

## ✅ 12. configure_file（变量生成配置文件）

```cmake
configure_file(config.h.in config.h)
```

config.h.in 内容示例：

```c
#define VERSION_MAJOR @PROJECT_VERSION_MAJOR@
```

---

## ✅ 13. install 部署命令

```cmake
install(TARGETS my_app RUNTIME DESTINATION bin)
install(FILES config.yaml DESTINATION share)
install(DIRECTORY include/ DESTINATION include)
```

---

## ✅ 14. 最常用工作流

```bash
mkdir build
cd build
cmake ..
make -j8
```

带库路径：

```bash
cmake .. -DOpenCV_DIR=/usr/local/lib/cmake/opencv4
```


# ⭐ **CMake 速查表（1 分钟记住）**

| 功能     | 命令                                        |
| ------ | ----------------------------------------- |
| 设置项目   | `project()`                               |
| 最低版本   | `cmake_minimum_required()`                |
| C++ 标准 | `set(CMAKE_CXX_STANDARD 17)`              |
| 可执行文件  | `add_executable()`                        |
| 库文件    | `add_library()`                           |
| 链接库    | `target_link_libraries()`                 |
| 头文件目录  | `target_include_directories()`            |
| 查找库    | `find_package()`                          |
| 子目录    | `add_subdirectory()`                      |
| 编译选项   | `target_compile_options()`                |
| 宏定义    | `target_compile_definitions()`            |
| 输出路径   | `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ...)` |
| 安装部署   | `install()`                               |


````



## Chapter3

## 3.1点，向量和坐标，旋转矩阵。

**点**

![image-20251127193540262](/home/lic/.config/Typora/typora-user-images/image-20251127193540262.png)

**坐标系**

![image-20251127193709934](/home/lic/.config/Typora/typora-user-images/image-20251127193709934.png)

**向量的运算**

![image-20251127193935020](/home/lic/.config/Typora/typora-user-images/image-20251127193935020.png)

**反对称矩阵的**

**外积是面积**



**坐标的变换**

**世界坐标系**

**移动的机器人**

![image-20251127194359447](/home/lic/.config/Typora/typora-user-images/image-20251127194359447.png)



**平移+旋转**

**平移是一个向量，旋转是一个矩阵的**

![image-20251127194601260](/home/lic/.config/Typora/typora-user-images/image-20251127194601260.png)



**旋转**

![image-20251127194754493](/home/lic/.config/Typora/typora-user-images/image-20251127194754493.png)

**标准正交基**

![image-20251127194921318](/home/lic/.config/Typora/typora-user-images/image-20251127194921318.png)

**旋转矩阵**

![image-20251127195311623](/home/lic/.config/Typora/typora-user-images/image-20251127195311623.png)

![image-20251127195352732](/home/lic/.config/Typora/typora-user-images/image-20251127195352732.png)

**旋转矩阵的性质**





![image-20251127195745623](/home/lic/.config/Typora/typora-user-images/image-20251127195745623.png)

![image-20251127200146145](/home/lic/.config/Typora/typora-user-images/image-20251127200146145.png)

![image-20251127200223882](/home/lic/.config/Typora/typora-user-images/image-20251127200223882.png)



**R==3*3**  **T==3*1**



![image-20251127200837276](/home/lic/.config/Typora/typora-user-images/image-20251127200837276.png)



**Pr = Rrw * Pw**

## 3.2实践部分



## 3.3旋转向量，欧拉角

**角轴**



![image-20251127210351543](/home/lic/.config/Typora/typora-user-images/image-20251127210351543.png)



**角轴的特点**

![image-20251127210635636](/home/lic/.config/Typora/typora-user-images/image-20251127210635636.png)

**角轴和旋转矩阵的转换**



**欧拉角**

![image-20251127210911595](/home/lic/.config/Typora/typora-user-images/image-20251127210911595.png)

**分解旋转**

**z yaw, y pitch, w roll**

**万向锁的问题：丢失一个自由度的**



![image-20251127211359219](/home/lic/.config/Typora/typora-user-images/image-20251127211359219.png)



## 3.4四元数



![image-20251127211444800](/home/lic/.config/Typora/typora-user-images/image-20251127211444800.png)



**四元数的运算**

![image-20251127211728843](/home/lic/.config/Typora/typora-user-images/image-20251127211728843.png)



**四元素的旋转**

![image-20251127211911957](/home/lic/.config/Typora/typora-user-images/image-20251127211911957.png)



**四元数的优点：**

![image-20251127212014956](/home/lic/.config/Typora/typora-user-images/image-20251127212014956.png)























































































