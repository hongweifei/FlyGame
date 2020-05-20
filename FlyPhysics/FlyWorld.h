



#include <math.h>

#include "FlyVector2.h"


#ifndef FLYWORLD
#define FLYWORLD


#ifndef BOOL
#define BOOL short
#define TRUE 1
#define FALSE 0
#endif


typedef struct __fly_world__ FlyWorld;
typedef struct __fly_world__ Fly_World;
typedef struct __fly_world__ World;


typedef struct __fly_world__
{
    Vector2 gravity;//ÖØÁ¦

    BOOL position_correction;
};


FlyWorld *FlyWorldInit();
#define WorldInit FlyWorldInit

void FlyWorldAdd();



#endif


