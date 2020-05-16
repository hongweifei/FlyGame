


#include <SDL2/SDL.h>

#ifndef FLYRENDERER
#define FLYRENDERER


#define FLY_RENDERER_SOFTWARE       SDL_RENDERER_SOFTWARE       //the renderer is a software fallback
#define FLY_RENDERER_ACCELERATED    SDL_RENDERER_ACCELERATED    //the renderer uses hardware acceleration
#define FLY_RENDERER_PRESENTVSYNC   SDL_RENDERER_PRESENTVSYNC   //present is synchronized with the refresh rate
#define FLY_RENDERER_TARGETTEXTURE  SDL_RENDERER_TARGETTEXTURE  //the renderer supports rendering to texture




typedef enum __fly_render_flip__
{
    FLY_FLIP_NONE = 0x00000000,         /**< Do not flip */
    FLY_FLIP_HORIZONTAL = 0x00000001,   /**< flip horizontally */
    FLY_FLIP_VERTICAL = 0x00000002      /**< flip vertically */
}FlyRenderFlip,Fly_RenderFlip;


/**Renderer*/
typedef struct SDL_Renderer __fly_renderer__;
typedef struct SDL_Renderer FlyRenderer;
typedef struct SDL_Renderer Fly_Renderer;


/**Point*/
typedef struct SDL_Point __fly_point__;
typedef struct SDL_Point FlyPoint;
typedef struct SDL_Point Fly_Point;

/**FloatPoint*/
typedef struct SDL_FPoint __fly_f_point__;
typedef struct SDL_FPoint FlyFPoint;
typedef struct SDL_FPoint Fly_FPoint;


/**Rect*/
typedef struct SDL_Rect __fly_rect__;
typedef struct SDL_Rect FlyRect;
typedef struct SDL_Rect Fly_Rect;

/**FloatRect*/
typedef struct SDL_FRect __fly_f_rect__;
typedef struct SDL_FRect FlyFRect;
typedef struct SDL_FRect Fly_FRect;


/**Surface*/
typedef struct SDL_Surface __fly_surface__;
typedef struct SDL_Surface FlySurface;
typedef struct SDL_Surface Fly_Surface;

/**Texture*/
typedef struct SDL_Texture __fly_texture__;
typedef struct SDL_Texture FlyTexture;
typedef struct SDL_Texture Fly_Texture;



FlyRenderer *FlyRendererCreate(SDL_Window *window,Uint32 flags);
#define FlyRendererCreate_(window) FlyRendererCreate(window,FLY_RENDERER_ACCELERATED)

int FlyRendererSetDrawColor(FlyRenderer*,Uint8, Uint8, Uint8, Uint8);

int FlyRendererClear(FlyRenderer*);//清空
int FlyRendererFlush(FlyRenderer*);
void FlyRendererPresent(FlyRenderer*);//交换

int FlyRendererDrawLine(FlyRenderer*,int,int,int,int);
int FlyRendererDrawLines(FlyRenderer*,const FlyPoint*,int);

int FlyRendererDrawLineF(FlyRenderer*,float, float, float, float);
int FlyRendererDrawLinesF(FlyRenderer*,const FlyFPoint*, int);

int FlyRendererDrawPoint(FlyRenderer*,int,int);
int FlyRendererDrawPoints(FlyRenderer*,const FlyPoint*, int);

int FlyRendererDrawPointF(FlyRenderer*,float, float);
int FlyRendererDrawPointsF(FlyRenderer*,const FlyFPoint*, int);

int FlyRendererDrawRect(FlyRenderer*,const FlyRect*);
int FlyRendererDrawRects(FlyRenderer*,const FlyRect*,int);

int FlyRendererDrawRectF(FlyRenderer*,const FlyFRect*);
int FlyRendererDrawRectsF(FlyRenderer*,const FlyFRect*,int);

int FlyRendererDrawFillRect(FlyRenderer*,const FlyRect*);
int FlyRendererDrawFillRects(FlyRenderer*,const FlyRect*, int);

int FlyRendererDrawFillRectF(FlyRenderer*,const FlyFRect*);
int FlyRendererDrawFillRectsF(FlyRenderer*,const FlyFRect*, int);


/*绘制image，坐标使用整数*/
int FlyRendererDrawImage_RectA(FlyRenderer*,const char*, const FlyRect *src, const FlyRect *dest, FlyRenderFlip flip);
int FlyRendererDrawImage_RectB(FlyRenderer*,const char*, const FlyRect *src, const FlyRect *dest);
int FlyRendererDrawImage_RectC(FlyRenderer*,const char*, const FlyRect *dest, FlyRenderFlip flip);
int FlyRendererDrawImage_RectD(FlyRenderer*,const char*, int, int, int, int);


/*绘制image，坐标使用浮点数*/
int FlyRendererDrawImage_FloatRectA(FlyRenderer*,const char*, const FlyRect*,const FlyFRect*,FlyRenderFlip);
int FlyRendererDrawImage_FloatRectB(FlyRenderer*,const char*, const FlyRect *src, const FlyFRect *dest);
int FlyRendererDrawImage_FloatRectC(FlyRenderer*,const char*, const FlyFRect *dest, FlyRenderFlip flip);
int FlyRendererDrawImage_FloatRectD(FlyRenderer*,const char*, float, float, float, float);


/*绘制纹理，不可翻转*/
int FlyRendererDrawTexture_A(FlyRenderer*,FlyTexture*);

/*绘制纹理，可翻转*/
int FlyRendererDrawTexture_B(FlyRenderer*,FlyTexture*, const FlyRenderFlip);

/*绘制纹理，不可翻转*/
int FlyRendererDrawTexture_RectA(FlyRenderer*,FlyTexture*, const FlyRect*);
int FlyRendererDrawTexture_FloatRectA(FlyRenderer*,FlyTexture*, const FlyFRect*);

/*绘制纹理，可翻转*/
int FlyRendererDrawTexture_RectB(FlyRenderer*,FlyTexture*, const FlyRect*, const FlyRenderFlip);
int FlyRendererDrawTexture_FloatRectB(FlyRenderer*,FlyTexture*, const FlyFRect*, const FlyRenderFlip);

/*绘制纹理，不可翻转，可裁剪源图片*/
int FlyRendererDrawTexture_RectC(FlyRenderer*,FlyTexture*, const FlyRect*, const FlyRect*);
int FlyRendererDrawTexture_FloatRectC(FlyRenderer*,FlyTexture*, const FlyRect*, const FlyFRect*);

/*绘制纹理，可翻转，可裁剪源图片*/
int FlyRendererDrawTexture_RectD(FlyRenderer*,FlyTexture*, const FlyRect*, const FlyRect*, const FlyRenderFlip);
int FlyRendererDrawTexture_FloatRectD(FlyRenderer*,FlyTexture*, const FlyRect*, const FlyFRect*, const FlyRenderFlip);


/*绘制纹理，可翻转，可旋转图片*/
int FlyRendererDrawTexture_RectE(FlyRenderer*, SDL_Texture*, const SDL_Rect*, double, const FlyRenderFlip);
int FlyRendererDrawTexture_FloatRectE(FlyRenderer*, SDL_Texture*, const SDL_FRect*, double ,const FlyRenderFlip);


/*绘制纹理，可翻转，可旋转图片，可裁剪源图片*/
int FlyRendererDrawTexture_RectF(FlyRenderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*, double, const FlyRenderFlip);
int FlyRendererDrawTexture_FloatRectF(FlyRenderer*, SDL_Texture*, const SDL_Rect*, const SDL_FRect*, double, const FlyRenderFlip);




#endif



