/**
 * @file rm_videocapture.h
 * @author GCUROBOT-Visual-Group (GCUROBOT_WOLF@163.com)
 * @brief RM 2019 步兵视觉相机配置头文件
 * @version 1.1
 * @date 2019-05-06
 * @copyright Copyright (c) 2019 GCU Robot Lab. All Rights Reserved.
 */
#ifndef RM_VIDEOCAPTURE_H_
#define RM_VIDEOCAPTURE_H_

#include <CameraApi.h>
/*---工业相机中使用到 opencv2.0 的 IplImage 需要包含此头文件 ---*/
#include <opencv2/imgproc/imgproc_c.h>
/*---工业相机中使用到 opencv2.0 的 IplImage 需要包含此头文件 ---*/
#include <opencv2/opencv.hpp>

class RM_VideoCapture
{
public:
  unsigned char           *g_pRgbBuffer; //处理后数据缓存区

  int                     iCameraCounts = 1;
  int                     iStatus=-1;
  tSdkCameraDevInfo       tCameraEnumList;
  int                     hCamera;
  tSdkCameraCapbility     tCapability;      //设备描述信息
  tSdkFrameHead           sFrameInfo;
  BYTE*			        pbyBuffer;
  cv::IplImage            *iplImage = nullptr;
  int                     channel=3;
  BOOL                    AEstate=FALSE;
  tSdkImageResolution     pImageResolution;       //相机分辨率信息

  bool                    iscamera0_open = false;

public:
  RM_VideoCapture(int cameramode);
  ~RM_VideoCapture();
  bool isindustryimgInput();
  void cameraReleasebuff();
  int cameraSet();
};

#endif // !RM_VIDEOCAPTURE_H_