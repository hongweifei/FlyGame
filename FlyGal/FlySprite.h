

#include <SDL2/SDL.h>


#ifndef FLYSPRITE
#define FLYSPRITE

class FlySprite
{
private:
    SDL_Texture *texture = NULL;
    SDL_Rect *src_rect = NULL;
    double angle = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
public:
    FlySprite();
    FlySprite(SDL_Renderer *renderer,const char *path);
    FlySprite(SDL_Texture *texture);
    FlySprite(SDL_Texture *texture,SDL_Rect *src_rect,double angle = 0,SDL_RendererFlip flip = SDL_FLIP_NONE);
    ~FlySprite();

    SDL_Texture *GetTexture() {return this->texture;};
    SDL_Rect *GetSrcRect() {return this->src_rect;};
    double GetAngle() {return this->angle;};
    SDL_RendererFlip GetFlip() {return this->flip;};

    void SetTexture(SDL_Texture *texture);
    void SetSrcRect(SDL_Rect *rect);
    void SetAngle(double angle);
    void SetFlip(SDL_RendererFlip flip);

    int Render(SDL_Renderer *renderer,SDL_Rect *rect = NULL);
    int Render(SDL_Renderer *renderer,SDL_FRect *rect);
};



#endif


