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

#ifndef MAPPOINT_H
#define MAPPOINT_H

#include"KeyFrame.h"
#include"Frame.h"
#include"Map.h"

#include<opencv2/core/core.hpp>
#include<mutex>

namespace ORB_SLAM2
{

class KeyFrame;
class Map;
class Frame;


class MapPoint
{
public:
    MapPoint(const cv::Mat &Pos, KeyFrame* pRefKF, Map* pMap);
    MapPoint(const cv::Mat &Pos,  Map* pMap, Frame* pFrame, const int &idxF);

    void SetWorldPos(const cv::Mat &Pos);         // mworldpos的set方法
    cv::Mat GetWorldPos();                        // mworldPos的get方法

    cv::Mat GetNormal();                          // mNormalVector的get方法
    KeyFrame* GetReferenceKeyFrame();

    std::map<KeyFrame*,size_t> GetObservations();
    int Observations();                                 // nobs的get方法 单目，双目相机的操作
                                                        
                                                       // observation的操作
    void AddObservation(KeyFrame* pKF,size_t idx);     // 添加当前地图点对某帧KeyFrame的观测
    void EraseObservation(KeyFrame* pKF);              // 删除当前地图点对某帧KeyFrame的观测

    int GetIndexInKeyFrame(KeyFrame* pKF);             // 查询当前地图在某KeyFrame中的索引
    bool IsInKeyFrame(KeyFrame* pKF);                  // 查询当前地图点是否在某keyFrame中

    void SetBadFlag();                                // 删除当前地图点
    bool isBad();                                     // 查询当前地图是否被删除(本质就是查询mbBad)

    void Replace(MapPoint* pMP);                      // 使用地图点Pmp替换当前地图点
    MapPoint* GetReplaced();                         // 用来替换当前地图点的新地图点

    void IncreaseVisible(int n=1);
    void IncreaseFound(int n=1);
    float GetFoundRatio();
    inline int GetFound()
    {
        return mnFound;
    }

    void ComputeDistinctiveDescriptors();              // 计算Descriptor

    cv::Mat GetDescriptor();                           // mDescriptor的get方法

    void UpdateNormalAndDepth();                       // 更新平均观测 -- 距离和方向

    float GetMinDistanceInvariance();                  // mfMinDistance 的get方法
    float GetMaxDistanceInvariance();                  // mNormalVector 的get方法
    int PredictScale(const float &currentDist, KeyFrame*pKF);
    int PredictScale(const float &currentDist, Frame* pF);

public:
    long unsigned int mnId;
    static long unsigned int nNextId;
    long int mnFirstKFid;
    long int mnFirstFrame;
    int nObs;                                        // 多少个相机

    // Variables used by the tracking
    float mTrackProjX;
    float mTrackProjY;
    float mTrackProjXR;
    bool mbTrackInView;
    int mnTrackScaleLevel;
    float mTrackViewCos;
    long unsigned int mnTrackReferenceForFrame;
    long unsigned int mnLastFrameSeen;

    // Variables used by local mapping
    long unsigned int mnBALocalForKF;
    long unsigned int mnFuseCandidateForKF;

    // Variables used by loop closing
    long unsigned int mnLoopPointForKF;
    long unsigned int mnCorrectedByKF;
    long unsigned int mnCorrectedReference;    
    cv::Mat mPosGBA;
    long unsigned int mnBAGlobalForKF;


    static std::mutex mGlobalMutex;

protected:    

     // Position in absolute coordinates
     cv::Mat mWorldPos;                                        // 地图点的世界坐标  set/get函数操作属性  为了两个之间加锁方法

     // Keyframes observing the point and associated index in keyframe
     std::map<KeyFrame*,size_t> mObservations;                 // 当前地图点在某KeyFrame中的索引   KeyFrame是关键帧，

     // Mean viewing direction
     cv::Mat mNormalVector;                                   // 平均观测方向

     // Best descriptor to fast matching
     cv::Mat mDescriptor;                                    // 当前关键 点的特征描述子(所有描述子的中位数)

     // Reference KeyFrame
     KeyFrame* mpRefKF;

     // Tracking counters
     int mnVisible;
     int mnFound;

     // Bad flag (we do not currently erase MapPoint from memory)
     bool mbBad;                                           // 坏点标记
     MapPoint* mpReplaced;

     // Scale invariance distances
     float mfMinDistance;                                    // 平均观测距离的下限
     float mfMaxDistance;                                    // 平均观测距离的上限

     Map* mpMap;

     std::mutex mMutexPos;                     // mWorldPos的锁
     std::mutex mMutexFeatures;
};

} //namespace ORB_SLAM

#endif // MAPPOINT_H
