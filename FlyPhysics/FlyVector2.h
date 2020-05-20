


#ifndef FLYVECTOR2
#define FLYVECTOR2


#ifndef BOOL
#define BOOL short
#define TRUE 1
#define FALSE 0
#endif


typedef struct __fly_vector_2__ FlyVector2;
typedef struct __fly_vector_2__ Fly_Vector2;
typedef struct __fly_vector_2__ Vector2;


typedef struct __fly_vector_2__
{
    float x;
    float y;
};

FlyVector2 *FlyVector2Init(float x,float y);
#define FlyVector2Init_() FlyVector2Init(0,0)

FlyVector2 *FlyVector2Plus(FlyVector2 *dest,const FlyVector2 *src);
FlyVector2 *FlyVector2Minus(FlyVector2 *dest,const FlyVector2 *src);
FlyVector2 *FlyVector2Multiply(FlyVector2 *dest,const float a);

float FlyVector2Length(FlyVector2 *v);


#endif


