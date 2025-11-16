/**
* This file is part of ORB-SLAM2.
*
* Copyright (C) 2014-2016 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
* For more information see <https://github.com/raulmur/ORB_SLAM2>
*
* ORB-SLAM2 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM2 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with ORB-SLAM2. If not, see <http://www.gnu.org/licenses/>.
*/

// 四元数
// q = w + xi + yj + zk
// [w, x, y, z]

// g2o::SE3Quat
// _r：旋转四元数（类型：Quaterniond），存储旋转信息。
// _t：平移向量（类型：Vector3d），存储位置偏移。


#include "Converter.h"

namespace ORB_SLAM2
{

// Description to vector
// 把每个单独特征提取出来

// cv::Mat--->std::vector<cv::Mat>
// 
std::vector<cv::Mat> Converter::toDescriptorVector(const cv::Mat &Descriptors)
{
    std::vector<cv::Mat> vDesc;                     // put Mat in Vector 
    vDesc.reserve(Descriptors.rows);                // rows(height)  行数
    for (int j=0; j<Descriptors.rows; j++)          // 
        vDesc.push_back(Descriptors.row(j));        // push_back() 放进每一行的数据

    return vDesc;
}


//  general graph optimization
//  Special  Euclidean 
//  quaternion


// cv::Mat--->g2o::SE3Quat
// 4*4 ---->  r t
//            0 1
g2o::SE3Quat Converter::toSE3Quat(const cv::Mat &cvT)
{
    Eigen::Matrix<double,3,3> R;  // Matrix 3 * 3 

    // 用cv::Mat去初始化Eigen::Matrix
    // 旋转矩阵
    R << cvT.at<float>(0,0), cvT.at<float>(0,1), cvT.at<float>(0,2),
         cvT.at<float>(1,0), cvT.at<float>(1,1), cvT.at<float>(1,2),
         cvT.at<float>(2,0), cvT.at<float>(2,1), cvT.at<float>(2,2);

    // 平移矩阵
    Eigen::Matrix<double,3,1> t(cvT.at<float>(0,3), cvT.at<float>(1,3), cvT.at<float>(2,3)); // 提取平移向量

    // R 3*3
    // t 3*1
    // 
    /*
    T=     r t
           0 1
    */

    // 
    // Eigen::Matrix<double, 3, 3> R
    // Eigen::Matrix<double, 3, 1> t
    return g2o::SE3Quat(R,t); 
}

// SE3Quat--->cv::Mat
// 
cv::Mat Converter::toCvMat(const g2o::SE3Quat &SE3)
{
    // r t
    // 0 1
    // 
    Eigen::Matrix<double,4,4> eigMat = SE3.to_homogeneous_matrix(); // SE3 = R + t ---> 4*4

    return toCvMat(eigMat); // Eigen::Matrix<double,4,4>--->cv::Mat
}


//go2::Sim3
//  s*R t
//  0   1
// 
cv::Mat Converter::toCvMat(const g2o::Sim3 &Sim3)
{
    Eigen::Matrix3d eigR = Sim3.rotation().toRotationMatrix(); // 四元数的旋转向量，转换成正交矩阵，保证他的旋转性质
    Eigen::Vector3d eigt = Sim3.translation();                 // 平移向量，转换成向量
    double s = Sim3.scale();                                   // 缩放因子
    return toCvSE3(s*eigR,eigt);
}

cv::Mat Converter::toCvMat(const Eigen::Matrix<double,4,4> &m)
{
    cv::Mat cvMat(4,4,CV_32F);  // 4*4 CV_32F, openCV的数据类型，32位 float。
    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            cvMat.at<float>(i,j)=m(i,j);

    return cvMat.clone();  // 深拷贝，防止数据的共享
}

cv::Mat Converter::toCvMat(const Eigen::Matrix3d &m)
{
    cv::Mat cvMat(3,3,CV_32F);
    for(int i=0;i<3;i++)
        for(int j=0; j<3; j++)
            cvMat.at<float>(i,j)=m(i,j);

    return cvMat.clone();
}

cv::Mat Converter::toCvMat(const Eigen::Matrix<double,3,1> &m)
{
    cv::Mat cvMat(3,1,CV_32F);
    for(int i=0;i<3;i++)
            cvMat.at<float>(i)=m(i);

    return cvMat.clone();
}

cv::Mat Converter::toCvSE3(const Eigen::Matrix<double,3,3> &R, const Eigen::Matrix<double,3,1> &t)
{
    cv::Mat cvMat = cv::Mat::eye(4,4,CV_32F);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cvMat.at<float>(i,j)=R(i,j);
        }
    }
    for(int i=0;i<3;i++)
    {
        cvMat.at<float>(i,3)=t(i);
    }

    return cvMat.clone();
}

Eigen::Matrix<double,3,1> Converter::toVector3d(const cv::Mat &cvVector)
{
    Eigen::Matrix<double,3,1> v;
    v << cvVector.at<float>(0), cvVector.at<float>(1), cvVector.at<float>(2);

    return v;
}

Eigen::Matrix<double,3,1> Converter::toVector3d(const cv::Point3f &cvPoint)
{
    Eigen::Matrix<double,3,1> v;
    v << cvPoint.x, cvPoint.y, cvPoint.z;

    return v;
}

Eigen::Matrix<double,3,3> Converter::toMatrix3d(const cv::Mat &cvMat3)
{
    Eigen::Matrix<double,3,3> M;

    M << cvMat3.at<float>(0,0), cvMat3.at<float>(0,1), cvMat3.at<float>(0,2),
         cvMat3.at<float>(1,0), cvMat3.at<float>(1,1), cvMat3.at<float>(1,2),
         cvMat3.at<float>(2,0), cvMat3.at<float>(2,1), cvMat3.at<float>(2,2);

    return M;
}

std::vector<float> Converter::toQuaternion(const cv::Mat &M)
{
    Eigen::Matrix<double,3,3> eigMat = toMatrix3d(M);
    Eigen::Quaterniond q(eigMat);

    std::vector<float> v(4);
    v[0] = q.x();
    v[1] = q.y();
    v[2] = q.z();
    v[3] = q.w();

    return v;
}

} //namespace ORB_SLAM
