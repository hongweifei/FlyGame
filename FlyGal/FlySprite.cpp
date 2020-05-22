


#include "FlySprite.h"
#include <SDL2/SDL_image.h>



FlySprite::FlySprite()
{
}

FlySprite::FlySprite(SDL_Renderer *renderer,const char *path)
{
    this->texture = IMG_LoadTexture(renderer,path);
}

FlySprite::FlySprite(SDL_Texture *texture)
{
    this->texture = texture;
}

FlySprite::FlySprite(SDL_Texture *texture,SDL_Rect *src_rect,double angle,SDL_RendererFlip flip)
{
    this->texture = texture;
    this->src_rect = src_rect;
    this->angle = angle;
    this->flip = flip;
}

FlySprite::~FlySprite()
{
    SDL_DestroyTexture(this->texture);
    SDL_free(this->src_rect);
}


void FlySprite::SetTexture(SDL_Texture *texture)
{
    this->texture = texture;
}

void FlySprite::SetSrcRect(SDL_Rect *rect)
{
    this->src_rect = rect;
}

void FlySprite::SetSrcRect(int x,int y,int w,int h)
{
    this->src_rect = new SDL_Rect();
    this->src_rect->x = x;
    this->src_rect->y = y;
    this->src_rect->w = w;
    this->src_rect->h = h;
}

void FlySprite::SetAngle(double angle)
{
    this->angle = angle;
}

void FlySprite::SetFlip(SDL_RendererFlip flip)
{
    this->flip = flip;
}


int FlySprite::Render(SDL_Renderer *renderer,SDL_Rect *rect)
{
    return SDL_RenderCopyEx(renderer,this->texture,this->src_rect,rect,this->angle,NULL,this->flip);
}

int FlySprite::Render(SDL_Renderer *renderer,SDL_FRect *rect)
{
    return SDL_RenderCopyExF(renderer,this->texture,this->src_rect,rect,this->angle,NULL,this->flip);
}

