#include <Prediction.h>
#include"Debug.h"


#ifdef SHOW_IMAGE
extern cv::Mat Rune; 
#endif
Prediction::Prediction():
        X(),
        Y(),
        Z(),
        tx(0),
        ty(0),
        tz(0)
{}

void Prediction::init3D(Target &vec){
        X.init(vec.x);
        Y.init(vec.y);
        Z.init(vec.z);
}

Eigen::Vector3f Prediction::predict3D(Target &vec,float & velocity, float & t){
        Xstate = X.predict(vec.x);
        Ystate = Y.predict(vec.y);
        Zstate = Z.predict(vec.z);
        float a = Xstate[1]*Xstate[1] + Ystate[1]*Ystate[1] + Zstate[1]*Zstate[1] - velocity*velocity;
        float b = Xstate[0]*Xstate[1] + Ystate[0]*Ystate[1] + Zstate[0]*Zstate[1];
        float c = Xstate[0]*Xstate[0] + Ystate[0]*Ystate[0] + Zstate[0]*Zstate[0];
        t = abs((-b+sqrt(b*b-4*a*c))/(2*a))+Constants::CompensationFactor_Proc;

#ifdef SHOW_IMAGE
        char text[255];
        sprintf(text,"t: %.2f   x: %.2f   y: %.2f   z: %.2f",t, tx, ty, tz);
        cv::putText(Rune,text,cv::Point(10,70),CV_FONT_HERSHEY_PLAIN,1,cv::Scalar(0,0,255),1,1);        
        sprintf(text,"vx: %.2f   vy: %.2f   vz: %.2f",Xstate[1],Ystate[1],Zstate[1]);
        cv::putText(Rune,text,cv::Point(10,90),CV_FONT_HERSHEY_PLAIN,1,cv::Scalar(0,0,255),1,1);
#endif

        tx = Xstate[0]+t*Xstate[1]+0.5*Xstate[2]*Xstate[2];
        ty = Ystate[0]+t*Ystate[1]+0.5*Ystate[2]*Ystate[2];
        tz = Zstate[0]+t*Zstate[1]+0.5*Zstate[2]*Zstate[2];
        return Eigen::Vector3f(tx ,ty, tz);
}

Eigen::Vector3f Prediction::predict3D(float & velocity, float & t){
        Xstate = X.predict_notarget();
        Ystate = Y.predict_notarget();
        Zstate = Z.predict_notarget();
        float a = Xstate[1]*Xstate[1] + Ystate[1]*Ystate[1] + Zstate[1]*Zstate[1] - velocity*velocity;
        float b = Xstate[0]*Xstate[1] + Ystate[0]*Ystate[1] + Zstate[0]*Zstate[1];
        float c = Xstate[0]*Xstate[0] + Ystate[0]*Ystate[0] + Zstate[0]*Zstate[0];
        t = abs((-b+sqrt(b*b-4*a*c))/(2*a))+Constants::CompensationFactor_Proc;

#ifdef SHOW_IMAGE
        char text[255]; 
        sprintf(text,"t: %.2f vx: %.2f   vy: %.2f   vz: %.2f", t, Xstate[1],Ystate[1],Zstate[1]);
        cv::putText(Rune,text,cv::Point(10,90),CV_FONT_HERSHEY_PLAIN,1,cv::Scalar(0,0,255),1,1);
#endif
        
        tx = Xstate[0]+t*Xstate[1]+0.5*Xstate[2]*Xstate[2];
        ty = Ystate[0]+t*Ystate[1]+0.5*Ystate[2]*Ystate[2];
        tz = Zstate[0]+t*Zstate[1]+0.5*Zstate[2]*Zstate[2];
        return Eigen::Vector3f(tx ,ty, tz);

}