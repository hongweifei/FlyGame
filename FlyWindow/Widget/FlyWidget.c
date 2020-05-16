


#include "FlyWidget.h"





FlyWidget *FlyWidgetCreate_A(float x,float y,float w,float h)
{
    FlyWidget *widget = (FlyWidget*)malloc(sizeof(FlyWidget));
    
    widget->rect.x = x;
    widget->rect.y = y;
    widget->rect.w = w;
    widget->rect.h = h;

    return widget;
}


FlyWidget *FlyWidgetCreate_B()
{
    return FlyWidgetCreate_A(0,0,0,0);
}