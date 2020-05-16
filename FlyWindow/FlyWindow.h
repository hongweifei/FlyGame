


#include <SDL2/SDL.h>
#include "FlyRenderer.h"

#ifndef FLYWINDOW
#define FLYWINDOW

#ifndef BOOL
#define BOOL short
#define TRUE 1
#define FALSE 0
#endif

#define FLY_WINDOW_POS_CENTERED  SDL_WINDOWPOS_CENTERED
#define FLY_WINDOW_POS_UNDEFINED SDL_WINDOWPOS_UNDEFINED

typedef enum __fly_window_flags__
{
    FLY_WINDOW_FULLSCREEN = 0x00000001,         /**< fullscreen window */
    FLY_WINDOW_OPENGL = 0x00000002,             /**< window usable with OpenGL context */
    FLY_WINDOW_SHOWN = 0x00000004,              /**< window is visible */
    FLY_WINDOW_HIDDEN = 0x00000008,             /**< window is not visible */
    FLY_WINDOW_BORDERLESS = 0x00000010,         /**< no window decoration */
    FLY_WINDOW_RESIZABLE = 0x00000020,          /**< window can be resized */
    FLY_WINDOW_MINIMIZED = 0x00000040,          /**< window is minimized */
    FLY_WINDOW_MAXIMIZED = 0x00000080,          /**< window is maximized */
    FLY_WINDOW_INPUT_GRABBED = 0x00000100,      /**< window has grabbed input focus */
    FLY_WINDOW_INPUT_FOCUS  = 0x00000200,       /**< window has input focus */
    FLY_WINDOW_MOUSE_FOCUS = 0x00000400,        /**< window has mouse focus */
    FLY_WINDOW_FULLSCREEN_DESKTOP = ( SDL_WINDOW_FULLSCREEN | 0x00001000 ),
    FLY_WINDOW_FOREIGN  = 0x00000800,           /**< window not created by SDL */

    FLY_WINDOW_ALLOW_HIGHDPI = 0x00002000,      /**< window should be created in high-DPI mode if supported. */
                                                /**  On macOS NSHighResolutionCapable must be set true in the */
                                                /**  application's Info.plist for this to have any effect. */

    FLY_WINDOW_MOUSE_CAPTURE = 0x00004000,      /**< window has mouse captured (unrelated to INPUT_GRABBED) */
    FLY_WINDOW_ALWAYS_ON_TOP = 0x00008000,      /**< window should always be above others */
    FLY_WINDOW_SKIP_TASKBAR = 0x00010000,       /**< window should not be added to the taskbar */
    FLY_WINDOW_UTILITY = 0x00020000,            /**< window should be treated as a utility window */
    FLY_WINDOW_TOOLTIP = 0x00040000,            /**< window should be treated as a tooltip */
    FLY_WINDOW_POPUP_MENU = 0x00080000,         /**< window should be treated as a popup menu */
    FLY_WINDOW_VULKAN = 0x10000000,             /**< window usable for Vulkan surface */
}FlyWindowFlags,Fly_WindowFlags;



typedef struct __fly_window__  FlyWindow;
typedef struct __fly_window__  Fly_Window;
typedef void(*WindowEvent)(FlyWindow*);
typedef void(*WindowRenderEvent)(FlyRenderer*,FlyWindow*);

static unsigned long thread_delay_time = 1000/60;

typedef struct __fly_window__
{
    SDL_Window *win;
    FlyRenderer *renderer;

    char *title;
    int x,y;
    int width,height;
    Uint32 id;

    FlySurface *icon;

    WindowRenderEvent render_event;
}FlyWindow,Fly_Window;



FlyWindow *FlyWindowCreate(const char*,int,int,Uint32);
#define FlyWindowCreate_(title,width,height) FlyWindowCreate(title,width,height,FLY_WINDOW_SHOWN|FLY_WINDOW_OPENGL|FLY_WINDOW_RESIZABLE)//创建窗口


void FlyWindowMainLoop(int window_count,...);

void FlyWindowDestroy(FlyWindow*);

const char *FlyWindowGetTitle(FlyWindow*);
void FlyWindowSetTitle(FlyWindow*,const char*);

int FlyWindowGetX(FlyWindow*);
int FlyWindowGetY(FlyWindow*);
int FlyWindowGetWidth(FlyWindow*);
int FlyWindowGetHeight(FlyWindow*);

void FlyWindowSetX(FlyWindow*,int);
void FlyWindowSetY(FlyWindow*,int);
void FlyWindowSetWidth(FlyWindow*,int);
void FlyWindowSetHeight(FlyWindow*,int);

void FlyWindowGetPosition(FlyWindow*,int*,int*);
void FlyWindowGetSize(FlyWindow*,int*,int*);

void FlyWindowSetPosition(FlyWindow*,int,int);
void FlyWindowSetSize(FlyWindow*,int,int);


#endif


