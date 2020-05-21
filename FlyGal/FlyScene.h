

#include <vector>
#include <SDL2/SDL.h>

#include "FlySprite.h"

#ifndef FLYSCENE
#define FLYSCENE


class FlyScene
{
private:
    SDL_Texture *background = NULL;
    SDL_Rect *background_src_rect = NULL;
    double background_angle = 0;
    SDL_RendererFlip background_flip = SDL_FLIP_NONE;

    std::vector<FlySprite*> sprite;
    std::vector<SDL_FRect*> sprite_dest_rect;
public:
    FlyScene();
    FlyScene(SDL_Texture *texture,SDL_Rect *src_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
    FlyScene(std::vector<SDL_Texture*> texture);
    FlyScene(std::vector<SDL_Texture*> texture,std::vector<SDL_FRect*> dest_rect);
    FlyScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect);
    FlyScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect,
    std::vector<double> angle,std::vector<SDL_RendererFlip> flip);
    
    ~FlyScene();

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

    void Add(SDL_Texture *texture,SDL_FRect *dest_rect = NULL);
    //void Add(SDL_Texture *texture,SDL_Rect *src_rect = NULL,SDL_FRect *dest_rect = NULL,double angle = 0);
    void Add(SDL_Texture *texture,SDL_Rect *src_rect = NULL,SDL_FRect *dest_rect = NULL,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
};



#endif


