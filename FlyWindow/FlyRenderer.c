


#include "FlyRenderer.h"
#include "FlyWindow.h"
#include <stdio.h>
#include <SDL2/SDL_image.h>


FlyRenderer *FlyRendererCreate(SDL_Window *window,Uint32 flags)
{
    return SDL_CreateRenderer(window,-1,flags);
}


/**设置绘制颜色*/
int FlyRendererSetDrawColor(FlyRenderer *renderer,Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return SDL_SetRenderDrawColor(renderer,r,g,b,a);
}



/**清空*/
int FlyRendererClear(FlyRenderer *renderer)
{
    return SDL_RenderClear(renderer);
}

int FlyRendererFlush(FlyRenderer *renderer)
{
    return SDL_RenderFlush(renderer);
}

/**交换*/
void FlyRendererPresent(FlyRenderer *renderer)
{
    SDL_RenderPresent(renderer);
}



/**画线*/
int FlyRendererDrawLine(FlyRenderer *renderer,int x1,int y1,int x2,int y2)
{
    return SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
}

/**通过点来画线，可绘制多条*/
int FlyRendererDrawLines(FlyRenderer *renderer,const FlyPoint *points,int count)
{
    return SDL_RenderDrawLines(renderer,points,count);
}

/**画线，坐标使用浮点数*/
int FlyRendererDrawLineF(FlyRenderer *renderer,float x1, float y1, float x2, float y2)
{
    return SDL_RenderDrawLineF(renderer,x1,y1,x2,y2);
}

/**通过点来画线，可绘制多条，坐标使用浮点数*/
int FlyRendererDrawLinesF(FlyRenderer *renderer,const FlyFPoint *points, int count)
{
    return SDL_RenderDrawLinesF(renderer,points,count);
}


/**绘制点*/
int FlyRendererDrawPoint(FlyRenderer *renderer,int x,int y)
{
    return SDL_RenderDrawPoint(renderer,x,y);
}

/**绘制多个点*/
int FlyRendererDrawPoints(FlyRenderer *renderer,const FlyPoint *points, int count)
{
    return SDL_RenderDrawPoints(renderer,points,count);
}

/**绘制点，坐标使用浮点数*/
int FlyRendererDrawPointF(FlyRenderer *renderer,float x, float y)
{
    return SDL_RenderDrawPointF(renderer,x,y);
}

/**绘制多个点，坐标使用浮点数*/
int FlyRendererDrawPointsF(FlyRenderer *renderer,const FlyFPoint *points, int count)
{
    return SDL_RenderDrawPointsF(renderer,points,count);
}



/**绘制矩形*/
int FlyRendererDrawRect(FlyRenderer *renderer,const FlyRect *rect)
{
    return SDL_RenderDrawRect(renderer,rect);
}

/**绘制多个矩形*/
int FlyRendererDrawRects(FlyRenderer *renderer,const FlyRect *rects,int count)
{
    return SDL_RenderDrawRects(renderer,rects,count);
}


/**绘制矩形，坐标使用浮点数*/
int FlyRendererDrawRectF(FlyRenderer *renderer,const FlyFRect *rect)
{
    return SDL_RenderDrawRectF(renderer,rect);
}

/**绘制多个矩形，坐标使用浮点数*/
int FlyRendererDrawRectsF(FlyRenderer *renderer,const FlyFRect *rects,int count)
{
    return SDL_RenderDrawRectsF(renderer,rects,count);
}

/**绘制实心矩形*/
int FlyRendererDrawFillRect(FlyRenderer *renderer,const FlyRect *rect)
{
    return SDL_RenderFillRect(renderer,rect);
}

/**绘制多个实心矩形*/
int FlyRendererDrawFillRects(FlyRenderer *renderer,const FlyRect *rects, int count)
{
    return SDL_RenderFillRects(renderer,rects,count);
}

/**绘制实心矩形，坐标使用浮点数*/
int FlyRendererDrawFillRectF(FlyRenderer *renderer,const FlyFRect *rect)
{
    return SDL_RenderFillRectF(renderer,rect);
}

/**绘制多个实心矩形，坐标使用浮点数*/
int FlyRendererDrawFillRectsF(FlyRenderer *renderer,const FlyFRect *rects, int count)
{
    return SDL_RenderFillRectsF(renderer,rects,count);
}


/**绘制image，可翻转，可裁剪，坐标使用整数*/
int FlyRendererDrawImage_RectA(FlyRenderer *renderer,const char *path, const FlyRect *src,const FlyRect *dest,FlyRenderFlip flip)
{
    static BOOL first = TRUE;
    
    static int count = 0;
    static const char** cache_path = NULL;
    static FlySurface* surface = NULL;
    static FlyTexture** texture = NULL;

    static int draw_index = 0;

    if (first)
    {
        cache_path = (const char**)calloc(0, sizeof(char*));
        texture = (FlyTexture**)calloc(count, sizeof(FlyTexture*));
    }
    


    for (int i = 0; i < count; i++)
    {
        if (strcmp(cache_path[i], path) == 0)
        {
            draw_index = i;
            goto draw;
        }
    }

    cache_path = (const char**)realloc(cache_path, sizeof(char*) * (count + 1));
    cache_path[count] = path;

    surface = IMG_Load(cache_path[count]);
    if (surface == NULL)
    {
        fprintf(stderr, "CreateSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    texture = (FlyTexture**)calloc(count + 1, sizeof(FlyTexture*));
    texture[count] = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture[count] == NULL)
    {
        fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_FreeSurface(surface);
    surface = NULL;

    count++;
    draw_index = count - 1;

draw:
    return FlyRendererDrawTexture_RectD(renderer, texture[draw_index], src, dest,flip);
}

/**绘制image，不可翻转，可裁剪，坐标使用整数*/
int FlyRendererDrawImage_RectB(FlyRenderer *renderer,const char *path, const FlyRect *src, const FlyRect *dest)
{
    return FlyRendererDrawImage_RectA(renderer, path, src, dest,FLY_FLIP_NONE);
}

/**绘制image，可翻转，不可裁剪，坐标使用整数*/
int FlyRendererDrawImage_RectC(FlyRenderer *renderer,const char *path, const FlyRect *dest, FlyRenderFlip flip)
{
    return FlyRendererDrawImage_RectA(renderer, path, NULL, dest,flip);
}

/**绘制image，不可翻转，不可裁剪，坐标使用整数*/
int FlyRendererDrawImage_RectD(FlyRenderer *renderer,const char *path, int x, int y, int width, int height)
{
    FlyRect rect = { x,y,width,height };
    return FlyRendererDrawImage_RectA(renderer, path, NULL, &rect,FLY_FLIP_NONE);
}



/*绘制image，可翻转，可裁剪，坐标使用浮点数*/
int FlyRendererDrawImage_FloatRectA(FlyRenderer *renderer,const char *path, const FlyRect *src,const FlyFRect *dest,FlyRenderFlip flip)
{
    static BOOL first = TRUE;
    
    static int count = 0;
    static const char** cache_path = NULL;
    static FlySurface* surface = NULL;
    static FlyTexture** texture = NULL;

    static int draw_index = 0;

    if (first)
    {
        cache_path = (const char**)calloc(0, sizeof(char*));
        texture = (FlyTexture**)calloc(count, sizeof(FlyTexture*));
    }
    


    for (int i = 0; i < count; i++)
    {
        if (strcmp(cache_path[i], path) == 0)
        {
            draw_index = i;
            goto draw;
        }
    }

    cache_path = (const char**)realloc(cache_path, sizeof(char*) * (count + 1));
    cache_path[count] = path;

    surface = IMG_Load(cache_path[count]);
    if (surface == NULL)
    {
        fprintf(stderr, "CreateSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    texture = (FlyTexture**)calloc(count + 1, sizeof(FlyTexture*));
    texture[count] = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture[count] == NULL)
    {
        fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_FreeSurface(surface);
    surface = NULL;

    count++;
    draw_index = count - 1;

draw:
    return FlyRendererDrawTexture_FloatRectD(renderer, texture[draw_index], src, dest,flip);
}

/**绘制image，不可翻转，可裁剪，坐标使用浮点数*/
int FlyRendererDrawImage_FloatRectB(FlyRenderer *renderer,const char *path, const FlyRect *src, const FlyFRect *dest)
{
    return FlyRendererDrawImage_FloatRectA(renderer, path, src, dest,FLY_FLIP_NONE);
}

/**绘制image，可翻转，不可裁剪，坐标使用浮点数*/
int FlyRendererDrawImage_FloatRectC(FlyRenderer *renderer,const char *path, const FlyFRect *dest, FlyRenderFlip flip)
{
    return FlyRendererDrawImage_FloatRectA(renderer, path, NULL, dest,flip);
}

/*绘制image，不可翻转，不可裁剪，坐标使用浮点数*/
int FlyRendererDrawImage_FloatRectD(FlyRenderer *renderer,const char *path, float x, float y, float width, float height)
{
    Fly_FRect rect = { x,y,width,height };
    return FlyRendererDrawImage_FloatRectA(renderer, path, NULL, &rect,FLY_FLIP_NONE);
}



/*绘制纹理，不可翻转*/
int FlyRendererDrawTexture_A(FlyRenderer *renderer,FlyTexture *texture)
{
    return SDL_RenderCopy(renderer, texture, NULL, NULL);
}

/*绘制纹理，可翻转*/
int FlyRendererDrawTexture_B(FlyRenderer *renderer,FlyTexture *texture, const FlyRenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, NULL, NULL,0,NULL,(SDL_RendererFlip)flip);
}


/*绘制纹理，不可翻转*/
int FlyRendererDrawTexture_RectA(FlyRenderer *renderer,FlyTexture *texture, const FlyRect *dest)
{
    return SDL_RenderCopy(renderer, texture, NULL, dest);
}

/**绘制纹理，不可翻转，坐标使用浮点数*/
int FlyRendererDrawTexture_FloatRectA(FlyRenderer *renderer,FlyTexture *texture, const FlyFRect *dest)
{
    return SDL_RenderCopyF(renderer, texture, NULL, dest);
}


/*绘制纹理，可翻转*/
int FlyRendererDrawTexture_RectB(FlyRenderer *renderer,FlyTexture *texture, const FlyRect *dest, const FlyRenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, NULL, dest, 0, NULL, (SDL_RendererFlip)flip);
}

/**绘制纹理，可翻转，坐标使用浮点数*/
int FlyRendererDrawTexture_FloatRectB(FlyRenderer *renderer,FlyTexture *texture, const FlyFRect *dest, const FlyRenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, NULL, dest, 0, NULL, (SDL_RendererFlip)flip);
}


/*绘制纹理，不可翻转，可裁剪源图片*/
int FlyRendererDrawTexture_RectC(FlyRenderer *renderer,FlyTexture *texture, const FlyRect *src, const FlyRect *dest)
{
    return SDL_RenderCopy(renderer, texture, src, dest);
}

/**绘制纹理，不可翻转，可裁剪源图片，坐标使用浮点数*/
int FlyRendererDrawTexture_FloatRectC(FlyRenderer *renderer,FlyTexture *texture, const FlyRect *src, const FlyFRect *dest)
{
    return SDL_RenderCopyF(renderer, texture, src, dest);
}


/*绘制纹理，可翻转，可裁剪源图片*/
int FlyRendererDrawTexture_RectD(FlyRenderer *renderer,FlyTexture *texture, const FlyRect *src, const FlyRect *dest, const FlyRenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, src, dest, 0, NULL,(SDL_RendererFlip)flip);
}

/*绘制纹理，可翻转，可裁剪源图片，坐标使用浮点数*/
int FlyRendererDrawTexture_FloatRectD(FlyRenderer *renderer,FlyTexture *texture, const FlyRect *src, const FlyFRect *dest, const FlyRenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, src, dest, 0, NULL, (SDL_RendererFlip)flip);
}



/*绘制纹理，可翻转，可旋转图片*/
int FlyRendererDrawTexture_RectE(FlyRenderer *renderer, SDL_Texture *texture, const SDL_Rect *dest, double angle, const FlyRenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, NULL, dest, angle, NULL, (SDL_RendererFlip)flip);
}

/*绘制纹理，可翻转，可旋转图片，坐标使用浮点数*/
int FlyRendererDrawTexture_FloatRectE(FlyRenderer *renderer, SDL_Texture *texture, const SDL_FRect *dest, double angle,const FlyRenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, NULL, dest, angle, NULL, (SDL_RendererFlip)flip);
}


/*绘制纹理，可翻转，可旋转图片，可裁剪源图片*/
int FlyRendererDrawTexture_RectF(FlyRenderer *renderer, SDL_Texture *texture, const SDL_Rect *src, const SDL_Rect *dest, double angle, const FlyRenderFlip flip)
{
    return SDL_RenderCopyEx(renderer, texture, src, dest, angle, NULL, (SDL_RendererFlip)flip);
}

/*绘制纹理，可翻转，可旋转图片，可裁剪源图片，坐标使用浮点数*/
int FlyRendererDrawTexture_FloatRectF(FlyRenderer *renderer, SDL_Texture *texture, const SDL_Rect *src, const SDL_FRect *dest, double angle, const FlyRenderFlip flip)
{
    return SDL_RenderCopyExF(renderer, texture, src, dest, angle, NULL, (SDL_RendererFlip)flip);
}



