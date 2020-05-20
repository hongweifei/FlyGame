

#include "FlyVector2.h"
#include <math.h>

FlyVector2 *FlyVector2Init(float x,float y)
{
    FlyVector2 *v = (FlyVector2*)malloc(sizeof(FlyVector2));
    v->x = x;
    v->y = y;

    return v;
}


FlyVector2 *FlyVector2Plus(FlyVector2 *dest,const FlyVector2 *src)
{
    dest->x += src->x;
    dest->y += src->y;

    return dest;
}


FlyVector2 *FlyVector2Minus(FlyVector2 *dest,const FlyVector2 *src)
{
    dest->x -= src->x;
    dest->y -= src->y;

    return dest;
}

FlyVector2 *FlyVector2Multiply(FlyVector2 *dest,const float a)
{
    dest->x *= a;
    dest->y *= a;

    return dest;
}


float FlyVector2Length(FlyVector2 *v)
{
    /**             A
     *              +
     *            + +
     *           +  +
     *         +    +
     *       +      +
     *     +        +
     * C +----------+ B
     * 
     * AB = y
     * BC = x
     * AC * AC = x * x  +  y * y
    */
    return sqrtf(v->x * v->x + v->y * v->y);//求平方根,得到 AC
}


