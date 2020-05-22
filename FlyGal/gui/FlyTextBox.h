

#include "FlyLabel.h"

#ifndef FLY_TEXTBOX
#define FLY_TEXTBOX



class FlyTextBox : private FlyLabel
{
private:
    SDL_Texture *box = NULL;
    SDL_FRect *box_dest_rect = NULL;
public:
    FlyTextBox(/* args */);
    ~FlyTextBox();
};

FlyTextBox::FlyTextBox(/* args */)
{
}

FlyTextBox::~FlyTextBox()
{
}



#endif

