#ifndef SERIAL_H
#define SERIAL_H
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <string.h>
#include <iostream>

/*
*   @brief:创建能够发送小数的共用体, 共用内存，直接拆分成Bit发送
*/
union float2uchar{
    float f;
    unsigned char uc[4];
};

/*
*   @brief:发送云台数据的结构体
*   @param:pitch_bit_pitch轴数据
*   @param:yaw_bit_yaw轴数据
* 
* 
*/
struct VisionData{
    float2uchar pitchData;
    float2uchar yawData;
    char distance;
    char IsHaveArmor;
    char shoot;
    VisionData():distance(0),IsHaveArmor(0),shoot(0){
        pitchData.f = 0.0f;
        yawData.f = 0.0f;
    };
};

/*
* @brief:接收机器人数据的结构体
* @param: level    机器人所处的模式
*  @param:status   机器人等级
*  @param:yawl
* @param:pitch
*/ 
struct ReceivedData{
    char level;
    float2uchar yaw;
    float2uchar pitch;
};

//
class RemoteController
{
public:
    int paraReceiver();
};

/**
 * @brief: 通信相关对象 
 * 
 * 
 */
class Serial{

public:
    void paraReceiver();
};


class Port{

public:
    int fd;
    Port();
    void OpenPort(); //打开串口
    int ConfigurePort();
    void SendData(VisionData & data);
    void ReciveData(ReceivedData & data);

private:

    const char *const PortName = "/dev/ttyUSB0"; //端口名
    int portNum;
    unsigned char rec_bytes[255];
    unsigned char send_bytes[14];
    unsigned char pitch_bit_;
    unsigned char yaw_bit_;

};


#endif