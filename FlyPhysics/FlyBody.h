


#include "FlyVector2.h"

#ifndef FLYBODY
#define FLYBODY


typedef struct __fly_body__ FlyBody;
typedef struct __fly_body__ Fly_Body;
typedef struct __fly_body__ Body;


typedef struct __fly_body__
{
    Vector2 position;//位置
    float rotation;//旋转

    Vector2 velocity;//速度
    float angular_velocity;//角速度

    Vector2 force;//力量
	float torque;//力矩,扭矩

	Vector2 width;//宽

    float friction;//摩擦力
    float mass;//质量
};





#endif



