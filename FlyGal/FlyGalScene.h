

#include <vector>
#include <SDL2/SDL.h>

#include "FlySprite.h"

#ifndef FLYGALSCENE
#define FLYGALSCENE


class FlyGalScene
{
private:
    FlySprite *background = new FlySprite();

    std::vector<FlySprite*> sprite;
    std::vector<SDL_FRect*> sprite_dest_rect;
public:
    FlyGalScene();
    FlyGalScene(SDL_Texture *texture,SDL_Rect *src_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
    FlyGalScene(std::vector<SDL_Texture*> texture);
    FlyGalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_FRect*> dest_rect);
    FlyGalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect);
    FlyGalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect,
    std::vector<double> angle,std::vector<SDL_RendererFlip> flip);
    
    ~FlyGalScene();

    void SetBackground(SDL_Texture *texture,SDL_Rect *src_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
    void SetBackground(FlySprite *sprite);

    void SetTexture(std::vector<SDL_Texture*> texture);
    void SetTexture(short index,SDL_Texture *texture);

    void SetSrcRect(std::vector<SDL_Rect*> rect);
    void SetSrcRect(short index,SDL_Rect *rect);

    void SetDestRect(std::vector<SDL_FRect*> rect);
    void SetDestRect(short index,SDL_FRect *rect);

    void SetAngle(std::vector<double> angle);
    void SetAngle(short index,double angle);

    void SetFlip(std::vector<SDL_RendererFlip> flip);
    void SetFlip(short index,SDL_RendererFlip flip);

    void Render(SDL_Renderer *renderer);

    void AddSprite(FlySprite *sprite,SDL_FRect *dest_rect = NULL);
    void AddSprite(FlySprite *sprite,float x,float y,float w,float h);
    void AddSprite(SDL_Texture *texture,SDL_FRect *dest_rect = NULL);
    //void AddSprite(SDL_Texture *texture,SDL_Rect *src_rect = NULL,SDL_FRect *dest_rect = NULL,double angle = 0);
    void AddSprite(SDL_Texture *texture,SDL_Rect *src_rect = NULL,SDL_FRect *dest_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
};



#endif


