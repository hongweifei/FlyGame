


#include "../FlyRenderer.h"


#ifndef FLYWIDGET
#define FLYWIDGET


typedef struct __fly_widget__ FlyWidget;
typedef struct __fly_widget__ Fly_Widget;
typedef void(*WidgetRenderEvent)(FlyRenderer*,FlyWidget*);


typedef struct __fly_widget__
{
    FlyFRect rect;
    WidgetRenderEvent render_event;
}FlyWidget,Fly_Widget;


FlyWidget *FlyWidgetCreate_A(float,float,float,float);
FlyWidget *FlyWidgetCreate_B();



#endif


