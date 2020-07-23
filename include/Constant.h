#ifndef CONSTANTS
#define CONSTANTS
#include<opencv2/opencv.hpp>
namespace Robomaster{

//射击模式
enum class Mode{
    Armor, //射击装甲板
    Rune //射击大符
};

//照片处理标识
enum class  ProcState{
    ISPROC, //处理中
    FINISHED //处理完成
};

//装甲板种类
enum class ArmorCatglory{
    SMALL, //小装甲
    LARGE, //大装甲
    RUNE, //大符
};

//敌方颜色
enum class EnemyColor{
    BLUE, //蓝色
    RED, // 红色
};

//预测状态
enum class PredictStatus{
    NEW, //新目标
    FIND, //找到上一个目标
    UNCLEAR, //不确定
    NONE //无目标
};

/*
* @brief:常量空间 
* 
*/
namespace Constants{

//敌方装甲颜色
static const EnemyColor enemyColor = EnemyColor::RED; 
//曝光时
static const unsigned short ExposureTime = 2000;
//曝光增益
static const unsigned short ExposureGain = 300;

//二值化阈值
static const unsigned short BinaryRange = 80;
 //丢帧限制
static const unsigned int LostRange = 3;

//灯条确定
//灯条最小像素值
static const unsigned int MinLedArea = 15; 
// 灯条最大像素值
static const unsigned int MaxLedArea = 3e3; 
//灯条斜率范围 0~x   灯条斜率^-1
static const float LedAngleRange = 1.0; 
//长宽比范围
static const float LedMinRatioRange = 1.0; 
static const float LedMaxRatioRange = 12.0; 

//装甲板确定
//长度之比最大 0~x
static const float LengthRatio = 1.4; 
//角度差误差范围 0~x
static const float AngleRatioDelta = 0.1; 
//灯条中心Y方向距离相对灯条长度 0~x
static const float DeltaYRatio = 0.5;
//灯条中心X方向距离相对灯条长度 0~x
static const float DeltaXRatio = 5.0;

//最小长宽比
static const float ArmorMinRatio = 0.55; 
//最大长宽比
static const float ArmorMaxRatio = 6.0; 



//目标确定为同一个的距离最大值
static const unsigned int RangeOfCorrect = 300;

static const unsigned int RangeOfShoot = 5;
//----------------------------固定参数---------------------------------

static const float shootVelocityLevel_0 = 8;
static const float shootVelocityLevel_1 = 10;
static const float shootVelocityLevel_2 = 13;
static const float shootVelocityLevel_3 = 28;

//摄像头相对于轴心的位置
//炮口补偿系数X轴
static const float CompensationFactor_X = 0.0;
//炮口补偿系数Y轴
static const float CompensationFactor_Y = 4.5;
//炮口补偿系数Z轴
static const float CompensationFactor_Z = 14.5;

//弧度
static const float Radian = 3.1415926/180;

//大装甲实际大小
static const float rLargeArmorWidth = 22.5;
static const float rLargeArmorHeight = 5.5;

//小装甲实际大小
static const float rSmallArmorWidth = 13.5;
static const float rSmallArmorHeight = 5.5;

//大幅装甲实际大小
static const float rRuneWidth = 24;
static const float rRuneHeight = 18;    

//相机内参
static const cv::Mat caremaMatrix_shoot = (
        cv::Mat_<float>(3, 3) << 648.4910,                  0,                         328.2316,
                                                        0,                                     652.0198,         254.6992,
                                                        0,                                     0,                                          1
                                  );
    //畸变参数
static const cv::Mat distCoeffs_shoot = (
        cv::Mat_<float>(1, 5) <<-0.2515, 
                                                        0.2977,
                                                        0,
                                                        0,
                                                        0);  
} 

/* //相机内参2
static const cv::Mat caremaMatrix_shoot = (
        cv::Mat_<float>(3, 3) << 640.50006,                  0,                         305.09497,
                                                        0,                                     652.0198,         255.88171,
                                                        0,                                     0,                                          1
);
//畸变参数
static const cv::Mat distCoeffs_shoot = (
        cv::Mat_<float>(1, 5) <<-0.22324, 
                                                        0.19562,
                                                        -0.00020,
                                                        0.00282,
                                                        0);  
} */


/*
*   @brief:结构体
*/
namespace Struct{

/**
 * @brief 云台角度记录
 * @param yaw 
 * @param pitch 
 */
struct Angle{
    float yaw;
    float pitch;
    Angle():yaw(0),pitch(0){};
};


}

namespace Class{

    //目标信息
class Target{
public:  
    float x;
    float y;
    float z;
    ArmorCatglory armorCatglory;
    Target():x(0),y(0),z(0){}
};
}


}



#endif // CONSTANTS
