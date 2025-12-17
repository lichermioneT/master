# SLAM14

**SLAM : Simultaneous Localization and Mapping**

**同时定位与地图构建**



## Chapter1

**1引言**

![image-20251126185944433](./picture/image-20251126185944433.png)



![image-20251126190106813](./picture/image-20251126190106813.png)



![image-20251126190146892](./picture/image-20251126190146892.png)





![image-20251126190302148](./picture/image-20251126190302148.png)



![image-20251126190620778](./picture/image-20251126190620778.png)

### 第一部分:数学基础

### 第二部分:视觉SLAM

### 第三部分:其他



## Chapter2

**内外兼修**

![image-20251126191003144](./picture/image-20251126191003144.png)



**传感器的配置**

![image-20251126191105911](./picture/image-20251126191105911.png)



**环境中配置传感器**

![image-20251126191209607](./picture/image-20251126191209607.png)



**相机分类**

![image-20251126191355624](./picture/image-20251126191355624.png)



**相纸之间的差距**

![image-20251126191444190](./picture/image-20251126191444190.png)



**单目相机的缺点**

![image-20251126191540293](./picture/image-20251126191540293.png)



**单目相机**

![image-20251126191634058](./picture/image-20251126191634058.png)



**双面相机**

![image-20251126191727582](./picture/image-20251126191727582.png)



**深度相机**

![image-20251126191820635](./picture/image-20251126191820635.png)



**共同点**

![image-20251126191923588](./picture/image-20251126191923588.png)



**视觉SLAM的做法**

![image-20251126192000302](./picture/image-20251126192000302.png)





![image-20251126192240978](./picture/image-20251126192240978.png)



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





![image-20251126192329188](./picture/image-20251126192329188.png)

![image-20251126192400203](./picture/image-20251126192400203.png)

![image-20251126192416878](./picture/image-20251126192416878.png)





**SLAM数学问题**

![image-20251126192537023](./picture/image-20251126192537023.png)

![image-20251126192606690](./picture/image-20251126192606690.png)

![image-20251126192725493](./picture/image-20251126192725493.png)



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

### 3.1点，向量和坐标，旋转矩阵。

**点**

![image-20251127193540262](./picture/image-20251127193540262.png)

**坐标系**

![image-20251127193709934](./picture/image-20251127193709934.png)

**向量的运算**

![image-20251127193935020](./picture/image-20251127193935020.png)

**反对称矩阵的**

**外积是面积**



**坐标的变换**

**世界坐标系**

**移动的机器人**

![image-20251127194359447](./picture/image-20251127194359447.png)



**平移+旋转**

**平移是一个向量，旋转是一个矩阵的**

![image-20251127194601260](./picture/image-20251127194601260.png)



**旋转**

![image-20251127194754493](./picture/image-20251127194754493.png)

**标准正交基**

![image-20251127194921318](./picture/image-20251127194921318.png)

**旋转矩阵**

![image-20251127195311623](./picture/image-20251127195311623.png)

![image-20251127195352732](./picture/image-20251127195352732.png)

**旋转矩阵的性质**





![image-20251127195745623](./picture/image-20251127195745623.png)

![image-20251127200146145](./picture/image-20251127200146145.png)

![image-20251127200223882](./picture/image-20251127200223882.png)



**R==3*3**  **T==3*1**



![image-20251127200837276](./picture/image-20251127200837276.png)



**Pr = Rrw * Pw**

### 3.2实践部分

### 3.3旋转向量，欧拉角

**角轴**



![image-20251127210351543](./picture/image-20251127210351543.png)



**角轴的特点**

![image-20251127210635636](./picture/image-20251127210635636.png)

**角轴和旋转矩阵的转换**



**欧拉角**

![image-20251127210911595](./picture/image-20251127210911595.png)

**分解旋转**

**z yaw, y pitch, w roll**

**万向锁的问题：丢失一个自由度的**



![image-20251127211359219](./picture/image-20251127211359219.png)

### 3.4四元数



![image-20251127211444800](./picture/image-20251127211444800.png)



**四元数的运算**

![image-20251127211728843](./picture/image-20251127211728843.png)



**四元素的旋转**

![image-20251127211911957](./picture/image-20251127211911957.png)



**四元数的优点：**

![image-20251127212014956](./picture/image-20251127212014956.png)

### 3.5相似，放射,

### 3.6eigen矩阵



## Chapter4

**李群与李代数**

![image-20251128182930040](./picture/image-20251128182930040.png)

![image-20251128182956969](./picture/image-20251128182956969.png)



### 4.1李群李代数基础

![image-20251128183149119](./picture/image-20251128183149119.png)



**什么是群**

![image-20251128183234664](./picture/image-20251128183234664.png)

**一般的群**

![image-20251128183849858](./picture/image-20251128183849858.png)

**群的优点**

![image-20251128183954319](./picture/image-20251128183954319.png)



**李代数**

![image-20251128184657215](./picture/image-20251128184657215.png)

![image-20251128184812378](./picture/image-20251128184812378.png)

**反对称矩阵**

![image-20251128184937627](./picture/image-20251128184937627.png)



**泰勒展开了**

![image-20251128185105791](./picture/image-20251128185105791.png)





![image-20251128185410477](./picture/image-20251128185410477.png)



**李代数的定义：**

![image-20251128185530123](./picture/image-20251128185530123.png)



 

![image-20251128190354127](./picture/image-20251128190354127.png)



![image-20251128190504981](./picture/image-20251128190504981.png)

![image-20251128190731327](./picture/image-20251128190731327.png)



### 4.2指数映射和对数映射

**李群和李代数的映射**

![image-20251128190942758](./picture/image-20251128190942758.png)

**化简得到的**

![image-20251128191204866](./picture/image-20251128191204866.png)





![image-20251128191303098](./picture/image-20251128191303098.png)



![image-20251128191502256](./picture/image-20251128191502256.png)



![image-20251128191656651](./picture/image-20251128191656651.png)



### 4.3李代数求导与扰动模型

![image-20251128191911616](./picture/image-20251128191911616.png)



![image-20251128192041664](./picture/image-20251128192041664.png)



![image-20251128192212983](./picture/image-20251128192212983.png)



![image-20251128192427946](./picture/image-20251128192427946.png)



**旋转**

![image-20251128192826736](./picture/image-20251128192826736.png)





![image-20251128193111096](./picture/image-20251128193111096.png)



![image-20251128193136634](./picture/image-20251128193136634.png)



![image-20251128193227980](./picture/image-20251128193227980.png)



![image-20251128193318836](./picture/image-20251128193318836.png)



**扰动和旋转的意义**



## Chapter5

**复习**

![image-20251201102603884](picture/image-20251201102603884.png)





### 5.1相机模型

![image-20251201102641978](picture/image-20251201102641978.png)



**建模**

![image-20251201102730716](picture/image-20251201102730716.png)

**负号  东西翻转到前面来**

**像素  图像坐标和实际坐标的变化**

![image-20251201103422545](picture/image-20251201103422545.png)





![image-20251201103822573](picture/image-20251201103822573.png)



![image-20251202144206065](picture/image-20251202144206065.png)



![image-20251202144250835](picture/image-20251202144250835.png)





![image-20251202144536065](picture/image-20251202144536065.png)



**畸变行为**

![image-20251202144608314](picture/image-20251202144608314.png)



**畸变行为**

![image-20251202144710382](picture/image-20251202144710382.png)



**畸变数学模型**

![image-20251202144800239](picture/image-20251202144800239.png)



**畸变3-4之间**

![image-20251202144941192](picture/image-20251202144941192.png)



**双目相机**

![image-20251202145027699](picture/image-20251202145027699.png)



**RGB-D相机**

![image-20251202145500743](picture/image-20251202145500743.png)

**缺点吸收光线了**



**OpenCV存放图片**

![image-20251202145824780](picture/image-20251202145824780.png)

**图片二维矩阵存放的**

**注意存放的通道顺序和数量**



### 5.3基本图像处理

### 5.4点云拼接



## Chapter6

**非线性优化**



![image-20251203183333948](picture/image-20251203183333948.png)





![image-20251203183357838](picture/image-20251203183357838.png)



### 6.1状态估计



![image-20251203183457311](picture/image-20251203183457311.png)





![image-20251203190417959](picture/image-20251203190417959.png)



![image-20251203190457420](picture/image-20251203190457420.png)



![image-20251203191040174](picture/image-20251203191040174.png)





![image-20251203191147607](picture/image-20251203191147607.png)





![image-20251203191229080](picture/image-20251203191229080.png)



![image-20251203191421832](picture/image-20251203191421832.png)



![image-20251203191519181](picture/image-20251203191519181.png)



### 6.2非线性最小二乘法

![image-20251203191641384](picture/image-20251203191641384.png)



![image-20251203191736586](picture/image-20251203191736586.png)





![image-20251203191839267](picture/image-20251203191839267.png)





![image-20251203192023483](picture/image-20251203192023483.png)



![image-20251203192218633](picture/image-20251203192218633.png)



![image-20251203192323927](picture/image-20251203192323927.png)



![image-20251203192438639](picture/image-20251203192438639.png)



![image-20251203192702553](picture/image-20251203192702553.png)



![image-20251203192756719](picture/image-20251203192756719.png)



![image-20251203192845699](picture/image-20251203192845699.png)



![image-20251203192931979](picture/image-20251203192931979.png)



### 6.3CERES库





### 6.4g20



## Chapter7

### 7.1特征点

![image-20251204191422531](picture/image-20251204191422531.png)



![image-20251204191517062](picture/image-20251204191517062.png)



![image-20251204191524758](picture/image-20251204191524758.png)





![image-20251204191638785](picture/image-20251204191638785.png)

![image-20251204191841444](picture/image-20251204191841444.png)

**视觉 SLAM 的特征点，是在图像中选出的、可被稳定重复识别的局部显著区域，用来跨帧匹配、估计相机运动，并作为三维地图点的基础。**

**描述子（Descriptor）是对特征点局部外观的数值化编码，用来在不同图像中判断“是不是同一个物理点”。**

**FAST N :特征点周围的像素进行比较的。**

![image-20251204191954832](picture/image-20251204191954832.png)

**ORB 特征**

**Oriented FAST 是在 FAST 角点检测的基础上，为每个角点估计一个主方向（orientation），从而使该角点具备旋转不变性。**

**给每一个 FAST 角点分配一个稳定的主方向**

![image-20251204192318039](picture/image-20251204192318039.png)

 

![image-20251204192721382](picture/image-20251204192721382.png)

- **O** - **Oriented** （有方向的）
- **R** - Rotated （旋转的）
- **B** - **B**RIEF （这是“Binary Robust Independent Elementary Features”的缩写，意为“二进制鲁棒独立基本特征”）

**Oriented FAST 是在 FAST 角点检测的基础上，通过灰度质心法为每个角点估计主方向，使其具备旋转不变性，是 ORB 特征能够用于实时 SLAM 的关键。**

![image-20251204192746489](picture/image-20251204192746489.png)

**特征匹配**



###  7.2实践：特征提取和匹配

![image-20251204193501959](picture/image-20251204193501959.png)

![image-20251216213424321](picture/image-20251216213424321.png)

![image-20251216213438492](picture/image-20251216213438492.png)

**根据两个点，计算相机的运动。**



### 7.3 2D--3D:对机几何



![image-20251204193829672](picture/image-20251204193829672.png)





![image-20251204193912125](picture/image-20251204193912125.png)





![image-20251204194210195](picture/image-20251204194210195.png)

![image-20251216220247139](picture/image-20251216220247139.png)





![image-20251204194411715](picture/image-20251204194411715.png)



![image-20251204194443040](picture/image-20251204194443040.png)



![image-20251204194459954](picture/image-20251204194459954.png)



![image-20251204194517564](picture/image-20251204194517564.png)





![image-20251204194527254](picture/image-20251204194527254.png)



![image-20251204194558275](picture/image-20251204194558275.png)





![image-20251204194609766](picture/image-20251204194609766.png)



![image-20251204194628750](picture/image-20251204194628750.png)





