# ORB_SLAM2

./Examples/RGB-D/rgbd_tum Vocabulary/ORBvoc.txt Examples/RGB-D/TUM1.yaml PATH_TO_SEQUENCE_FOLDER ASSOCIATIONS_FILE



根据您提供的文件内容，以下是提取的文字信息：

---

ORB-SLAM2中的变量遵循一套命名规则：

- 变量名的第一个字母为 \( m \) 表示该变量为某类的成员变量。
- 变量名的第一、二个字母表示数据类型：
  - p 表示指针类型
  - n 表示 int 类型
  - b 表示 bool 类型
  - s 表示 std::set 类型
  - v 表示 std::vector 类型
  - l 表示 std::list 类型
  - kF 表示 KeyFrame 类型

这种将变量类型写进变量名的命名方法叫做匈牙利命名法。

---



## 理解为什么 使用多线程

**1.同时开两个线程同时计算两个矩阵，在多核处理器上会加快运算速度。**

**2. 因为系统的随机性，各个步骤的运行顺序是不确定的。**

​	**三大线程  TRACKING, LOCAL MAPPING, LOOP CLOSING.**

​	**每一帧都经过TRACKING线程，只有关键帧才会LOCAL,LOOP**

​	**TRACKING传递关键帧才会，执行下面的线程**

​	**这里是随机帧，不是定时的帧，传递给后面的两个线程**



**3.每次来一帧都进行跟踪，跟踪完成决定是否产生关键帧。**

**4.线程之间的锁是越小越好的，防止相互打架**



**ORB_SLAM2的主类System**



## ORBextractor函数

**构造函数ORBextractor()函数。**



![image-20251115205117114](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115205117114.png)





![image-20251115205342065](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115205342065.png)





![image-20251115211233191](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115211233191.png)



![image-20251115211731009](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115211731009.png)



**UMAX[0] = 8**



![image-20251117084400383](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117084400383.png)





![image-20251117085004304](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085004304.png)



![image-20251117085249470](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085249470.png)



![image-20251117085632988](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085632988.png)



![image-20251117085912835](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085912835.png)



![image-20251117090037337](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117090037337.png)



**非极大值抑制**

![image-20251117091424312](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117091424312.png)





![image-20251117091626739](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117091626739.png)





## MapPoint

**RRBslam: 特征点，关键帧。**

**MapPoint  KeyFrames**



![image-20251118195021798](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118195021798.png)

![image-20251118195001451](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118195001451.png)

![image-20251118103653349](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118103653349.png)

![image-20251117095833908](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117095833908.png)



**观测尺度**



![image-20251118105831304](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118105831304.png)



![image-20251118110024446](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118110024446.png)





![image-20251118202130295](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118202130295.png)



![image-20251118202418175](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118202418175.png)



**t特征描述点3d -2d的匹配**

**什么时候替换和删除**

![image-20251118204811524](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118204811524.png)















































