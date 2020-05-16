



#include "FlyGame.h"

#include <stdio.h>

int main(int argc,char *argv[])
{
    GameInit();
    FlyWindow *window = FlyWindowCreate_("Game",800,600);
    FlyWindowMainLoop(1,window);
    
    return 0;
}





