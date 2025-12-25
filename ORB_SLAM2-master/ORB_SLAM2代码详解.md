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

![image-20251224201032396](picture/image-20251224201032396.png)

**只有keyframe才会参建图。**

**关键帧的随机性，**

​	**TRACKING传递关键帧才会，执行下面的线程**

​	**loopclosing和locapmaping 死循环。根据关键帧进行运行。**



​	**这里是随机帧，不是定时的帧，传递给后面的两个线程**



**3.每次来一帧都进行跟踪，跟踪完成决定是否产生关键帧。**

**4.线程之间的锁是越小越好的，防止相互打架**

​	**操作同一个数据，出现bug.**

**protected 保护变量。**

​	**{锁的局部变量}**

**锁的力度越小越好，线程之间互相打架等待的时间 越小越好。**



![image-20251224202135438](picture/image-20251224202135438.png)





**ORB_SLAM2的主类System**

![image-20251224202233283](picture/image-20251224202233283.png)

**线程通信，就是往消息队列里面放数据的。**

![image-20251224202525721](picture/image-20251224202525721.png)



## ORBextractor函数

**构造函数ORBextractor()函数。**

![image-20251115205117114](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115205117114.png)

**FAST 特征点和 ORB 描述子本身不具有尺度信息, ORBextractor 通过构建图像金字塔来得到特征点尺度信息.将输入图片逐级缩放得到图像金 字塔,金字塔层级越高,图片分辨率越低,ORB特征点越大.**

**图片近大远小**

![image-20251224202851387](picture/image-20251224202851387.png)



![image-20251224202914904](picture/image-20251224202914904.png)





![image-20251115205342065](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115205342065.png)



**特征描述子**

![image-20251224203009309](picture/image-20251224203009309.png)

**256个点。**



![image-20251115211233191](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115211233191.png)

**特征点的主方向。**



![image-20251115211731009](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251115211731009.png)

**UMAX[0] = 8**

**V---U对应的**

![image-20251224203324511](picture/image-20251224203324511.png)





**金字塔除了缩放，还加上区域。**

![image-20251117084400383](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117084400383.png)

![image-20251224203547508](picture/image-20251224203547508.png)

**为什么需要补充点呢**

**fast特征点 3*3的圆。会浪费一些特征点。**

**描述子需要16*16的圆**

**所以需要 19*19的圆。**



![image-20251117085004304](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085004304.png)

![image-20251224204048281](picture/image-20251224204048281.png)

**镜像对称的点。**

**响应点，角点。 **

**描述子是特征点的一个哈希运算。**

![image-20251117085249470](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085249470.png)



![image-20251117085632988](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085632988.png)

**提取特征点最重要的就是力求特征点均匀地分布在图像的所有部分,为实现这一目标,编程实现上使用了两个技巧:**

**降低分数线**

**\1. 分 CELL 搜索特征点,若某 CELL 内特征点响应值普遍较小的话就降低分数线再搜索一遍.**

**\2. 对得到的所有特征点进行八叉树筛选,若某区域内特征点数目过于密集,则只取其中响应值最大的那个.**

**避免特征点在图像局部区域过度集中，从而提升位姿估计与建图的稳定性。**

![image-20251117085912835](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117085912835.png)

![image-20251224204728065](picture/image-20251224204728065.png)





![image-20251117090037337](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117090037337.png)

![image-20251224204818054](picture/image-20251224204818054.png)



![image-20251224204902936](picture/image-20251224204902936.png)



**非极大值抑制**

![image-20251117091424312](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117091424312.png)





![image-20251117091626739](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117091626739.png)

![image-20251224205925458](picture/image-20251224205925458.png)



**计算特征点描述子**

![image-20251224210024174](picture/image-20251224210024174.png)



![image-20251224210330855](picture/image-20251224210330855.png)

![image-20251224210342982](picture/image-20251224210342982.png)

![image-20251224210731205](picture/image-20251224210731205.png)

**使用范围**

![image-20251224210817383](picture/image-20251224210817383.png)

**由上述代码分析可知,每次完成 ORB 特征点提取之后,图像金字塔信息就作废了,下一帧图像到来时调用 ComputePyramid() 函数会覆盖掉 本帧图像的图像金字塔信息;但从金字塔中提取的图像特征点的信息会被保存在 Frame 对象中.所以ORB-SLAM2是稀疏重建,对每帧图像 只保留最多 nfeatures 个特征点(及其对应的地图点).**



## MapPoint

**RRBslam: 特征点，关键帧。就是地图。**

**MapPoint  KeyFrames**

![image-20251225152736695](picture/image-20251225152736695.png)

**特征点三角化地图点。**

**特征点不一定地图点。**

**地图的特征描述子**

![image-20251118195021798](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118195021798.png)

![image-20251118195001451](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118195001451.png)

![image-20251118103653349](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118103653349.png)





![image-20251117095833908](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251117095833908.png)

![image-20251224212329243](picture/image-20251224212329243.png)



![image-20251225153452674](picture/image-20251225153452674.png)





**观测尺度**

**近大远小。**

![image-20251118105831304](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118105831304.png)

![image-20251225153700234](picture/image-20251225153700234.png)







![image-20251118110024446](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118110024446.png)





![image-20251118202130295](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118202130295.png)

![image-20251225155255021](picture/image-20251225155255021.png)



![image-20251118202418175](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118202418175.png)





**t特征描述点3d -2d的匹配**

**什么时候替换和删除**

![image-20251118204811524](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251118204811524.png)



![image-20251225155652247](picture/image-20251225155652247.png)



**特征点**

**关键帧**



## 帧Frame

![image-20251225160741330](picture/image-20251225160741330.png)

![image-20251225193959324](picture/image-20251225193959324.png)





![image-20251119085420317](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251119085420317.png)



**对象的属性**

**静态属性，全员共享。**

![image-20251119085710730](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251119085710730.png)

![image-20251225194456432](picture/image-20251225194456432.png)



![image-20251119090943872](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251119090943872.png)

![image-20251225194747885](picture/image-20251225194747885.png)



**双目时差公式**

![image-20251119091326279](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251119091326279.png)





![image-20251119094053438](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251119094053438.png)



![image-20251119094729944](C:\Users\LIC\AppData\Roaming\Typora\typora-user-images\image-20251119094729944.png)

















