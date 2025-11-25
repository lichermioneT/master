# ORB-SLAM

下面我一步一步教你 **如何从 opencv-3.4.16.zip 安装 OpenCV 3.4.16**，你完全按照步骤操作即可。

你已经有：

```
~/orb/zip/opencv-3.4.16.zip
```

现在开始安装 👇

------

# ✅ **第一步：解压 zip**

进入 zip 所在目录：

```bash
cd ~/orb/zip
```

解压：

```bash
unzip opencv-3.4.16.zip
```

解压后会生成一个文件夹：

```
opencv-3.4.16/
```

如果你的系统没有 unzip，可以安装：

```bash
sudo apt install unzip
```

------

# ✅ **第二步：进入 OpenCV 源码目录**

```bash
cd opencv-3.4.16
```

创建 build 目录：

```bash
mkdir build
cd build
```

------

# ✅ **第三步：使用 cmake 配置（最标准）**

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

如果你想启用更多模块，也可以使用：

```bash
cmake .. \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX=/usr/local
```

------

# ✅ **第四步：开始编译**

**如果你 CPU 核心数是 8 核：**

```bash
make -j8
```

如果你不清楚机器核数，用：

```bash
nproc
```

------

# ✅ **第五步：安装 OpenCV（关键）**

编译完后安装：

```bash
sudo make install
```

安装之后，OpenCV 默认会安装到：

```
/usr/local/
```

包含：

```
/usr/local/include/opencv4/
/usr/local/lib/libopencv_*.so
/usr/local/lib/cmake/opencv4/
```

------

# ✅ **第六步：让系统识别 OpenCV 库**

创建 ld.so 配置文件（如果不存在）：

```bash
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
```

刷新动态库缓存：

```bash
sudo ldconfig
```

------

# ⛳ **第七步：测试 OpenCV 是否安装成功**

```bash
pkg-config --modversion opencv4
```

如果成功会输出：

```
3.4.16
```

------

# 🧩 **第八步：让 ORB-SLAM2 找到 OpenCV**

你的 ORB-SLAM2 报的是：

```
OpenCV > 2.4.3 not found
```

你可以这样指定 OpenCV 目录：

```bash
cmake .. \
  -DCMAKE_BUILD_TYPE=Release \
  -DOpenCV_DIR=/usr/local/lib/cmake/opencv4
```

或者修改 ORB-SLAM2 的 CMakeLists：

把：

```cmake
find_package(OpenCV 3.0 QUIET)
```

改成：

```cmake
find_package(OpenCV REQUIRED)
```

------

# 📌 **总结：安装流程一张图说明**

```
unzip opencv-3.4.16.zip
   ↓
cd opencv-3.4.16
   ↓
mkdir build && cd build
   ↓
cmake .. -DCMAKE_BUILD_TYPE=Release
   ↓
make -j8
   ↓
sudo make install
   ↓
sudo ldconfig
```

然后 ORB-SLAM2 就能找到 OpenCV 了。

------

如果你愿意，我可以给你一个 **自动安装 OpenCV 3.4.16 的脚本**，你只需复制粘贴就可以。你需要吗？



你现在系统里已经装了 **OpenCV 4.2.0**，而不是你解压的 **OpenCV 3.4.16**。
 所以 `pkg-config` 显示的是：

```
4.2.0
```

**这会导致 ORB-SLAM2 报错，因为 ORB-SLAM2 原版不能自动识别 OpenCV4 的路径。**

------

# ✅ 你现在有两个解决方案（任选其一）：

------

# ⭐ **方案 A（推荐）：让 ORB-SLAM2 支持 OpenCV4（不用卸载任何东西）**

你的 OpenCV4 版本是 4.2.0，非常标准。
 只需要修改 ORB-SLAM2 的 CMakeLists.txt，即可编译成功。

修改步骤如下 👇

------

## 🔧 **步骤 1：进入 ORB-SLAM2 的主目录**

```bash
cd ~/orb/ORB_SLAM2-master
```

------

## 🔧 **步骤 2：编辑主 CMakeLists**

```bash
sudo vim CMakeLists.txt
```

找到：

```cmake
find_package(OpenCV 3.0 QUIET)
if(NOT OpenCV_FOUND)
    find_package(OpenCV 2.4.3 QUIET)
    if(NOT OpenCV_FOUND)
        message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
    endif()
endif()
```

把它改成：

```cmake
find_package(OpenCV REQUIRED)
```

就这一句，删掉所有版本检查！

保存退出。

------

## 🔧 **步骤 3：清理旧的 build**

```bash
rm -rf build
mkdir build
cd build
```

------

## 🔧 **步骤 4：重新 cmake，指定 OpenCV4 路径**

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DOpenCV_DIR=/usr/local/lib/cmake/opencv4
```

------

## 🔧 **步骤 5：开始编译**

```bash
make -j
```

✔ 这样 ORB-SLAM2 就能成功链接 OpenCV4
 ✔ 不需要降级
 ✔ 也不需要卸载系统里的 OpenCV4.2.0

------

# ⭐ **方案 B：真正安装 OpenCV 3.4.16（如果你坚持用 3.4）**

你当前没有真正安装 3.4.16，因为你只解压了 zip，没有运行：

```
make
sudo make install
```

正确安装方式如下 👇

------

## 1. 进入 OpenCV3 build 目录

```bash
cd ~/orb/opencv-3.4.16/build
```

## 2. 编译

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j8
```

## 3. 安装

```bash
sudo make install
sudo ldconfig
```

安装后版本会显示：

```bash
pkg-config --modversion opencv4
3.4.16
```

如果你还想要我可以教你怎么卸载 OpenCV 4.2.0（不推荐）。

------

# 📌 建议你使用方案 A：

**让 ORB-SLAM2 兼容 OpenCV4，更简单，更现代。**

你想让我直接给你修改好 ORB-SLAM2 的所有 OpenCV4 兼容部分吗？
 包括所有 CMakeLists 和代码 patch？



lic@lic:~/orb/ORB_SLAM2-master/Thirdparty/DBoW2/build$ cmake .. -DCMAKE_BUILD_TYPE=Release -DOpenCV_DIR=/usr/local/lib/cmake/opencv4
-- The C compiler identification is GNU 9.4.0
-- The CXX compiler identification is GNU 9.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenCV: /usr/local (found version "4.5.4") 
-- Configuring done
-- Generating done
-- Build files have been written to: /home/lic/orb/ORB_SLAM2-master/Thirdparty/DBoW2/build
lic@lic:~/orb/ORB_SLAM2-master/Thirdparty/DBoW2/build$ make -j
Scanning dependencies of target DBoW2
[ 14%] Building CXX object CMakeFiles/DBoW2.dir/DBoW2/BowVector.cpp.o
[ 28%] Building CXX object CMakeFiles/DBoW2.dir/DBoW2/ScoringObject.cpp.o
[ 42%] Building CXX object CMakeFiles/DBoW2.dir/DBoW2/FORB.cpp.o
[ 57%] Building CXX object CMakeFiles/DBoW2.dir/DUtils/Random.cpp.o
[ 71%] Building CXX object CMakeFiles/DBoW2.dir/DBoW2/FeatureVector.cpp.o
[ 85%] Building CXX object CMakeFiles/DBoW2.dir/DUtils/Timestamp.cpp.o
[100%] Linking CXX shared library ../lib/libDBoW2.so
[100%] Built target DBoW2
lic@lic:~/orb/ORB_SLAM2-master/Thirdparty/DBoW2/build$ 



好的，我们继续一步一步来，现在你需要编译 **g2o**（ORB-SLAM2 的后端优化库）。

下面是标准流程，按步骤执行即可。

------

# ✅ **1. 进入 g2o 目录**

你应该在 ORB_SLAM2 的 Thirdparty 下找到 g2o：

```bash
cd ~/orb/ORB_SLAM2-master/Thirdparty/g2o
```

# ✅ **2. 创建 build 目录**

```bash
mkdir build
cd build
```

# ✅ **3. 配置 CMake（Release 模式）**

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

若 CMake 成功，你会看到：

```
Configuring done
Generating done
```

------

# ✅ **4. 编译 g2o**

```bash
make -j
```

如果一切顺利，会看到：

```
[100%] Built target g2o
```

------

# 🔧 **可能遇到的问题：OpenGL / QGLViewer / Eigen**

g2o 编译经常会遇到以下问题：

### ❌ **找不到 Eigen**

如果报类似：

```
Eigen not found
```

安装：

```bash
sudo apt install libeigen3-dev
```

------

### ❌ **找不到 OpenGL**

如果报：

```
cannot find -lGL
```

安装：

```bash
sudo apt install libgl1-mesa-dev
sudo apt install libglu1-mesa-dev
```

------

### ❌ **找不到 QGLViewer**

有些版本需要 QGLViewer，但 ORB-SLAM2 自带 g2o，默认 **关闭 GUI**，不会要求 QGLViewer。

如果提示缺少 QGLViewer：

```bash
sudo apt install libqglviewer-dev
```

------

# 🎉 编译成功后会生成库：

```
~/orb/ORB_SLAM2-master/Thirdparty/g2o/lib/libg2o.so
```

------

# 🟢 **g2o 编译完成后下一步是什么？**

继续编译 ORB_SLAM2 主工程：

```bash
cd ~/orb/ORB_SLAM2-master
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j
```

------

如果你现在想，我也可以：

🟡 **帮你完整检查你的环境是否适配 ORB-SLAM2（OpenCV、Pangolin、Eigen、Boost、g2o）**
 🟡 **帮你跟踪每一步编译输出并解决错误**

你现在执行到哪一步了？我可以继续协助。

















