


#include "FlyGalScene.h"


FlyGalScene::FlyGalScene()
{
}

FlyGalScene::FlyGalScene(SDL_Texture *texture,SDL_Rect *src_rect,double angle,SDL_RendererFlip flip)
{
    this->SetBackground(texture,src_rect,angle,flip);
}

FlyGalScene::FlyGalScene(std::vector<SDL_Texture*> texture)
{
    for (int i = 0; i < texture.size(); i++)
    {
        this->sprite.push_back(new FlySprite(texture[i]));
        this->sprite_dest_rect.push_back(NULL);
    }
}

FlyGalScene::FlyGalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_FRect*> dest_rect)
{
    int count = 0;
    if (texture.size() < dest_rect.size())
        count = texture.size();
    else if(texture.size() > dest_rect.size())
        count = dest_rect.size();
    else
        count = texture.size();

    for (int i = 0; i < count; i++)
    {
        this->sprite.push_back(new FlySprite(texture[i]));
        this->sprite_dest_rect.push_back(dest_rect[i]);
    }
}

FlyGalScene::FlyGalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect)
{
    int count = 0;
    if (texture.size() < dest_rect.size())
        count = texture.size();
    else if(texture.size() > dest_rect.size())
        count = dest_rect.size();
    else
        count = texture.size();
    
    for (int i = 0; i < count; i++)
    {
        this->sprite.push_back(new FlySprite(texture[i],src_rect[i]));
        this->sprite_dest_rect.push_back(dest_rect[i]);
    }
}


FlyGalScene::FlyGalScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect,
    std::vector<double> angle,std::vector<SDL_RendererFlip> flip)
{
    int count = 0;
    if (texture.size() < dest_rect.size() && texture.size() < src_rect.size())
        count = texture.size();
    else if(src_rect.size() < dest_rect.size() && src_rect.size() < texture.size())
        count = src_rect.size();
    else if(dest_rect.size() < src_rect.size() && dest_rect.size() < texture.size())
        count = dest_rect.size();
    else
        count = texture.size();

    for (int i = 0; i < count; i++)
    {
        this->sprite.push_back(new FlySprite(texture[i],src_rect[i],angle[i],flip[i]));
        this->sprite_dest_rect.push_back(dest_rect[i]);
    }
}

FlyGalScene::~FlyGalScene()
{
    delete this->background;
    for (int i = 0; i < this->sprite.size(); i++)
    {
        delete this->sprite[i];
        SDL_free(this->sprite_dest_rect[i]);
    }
}


void FlyGalScene::SetBackground(SDL_Texture *texture,SDL_Rect *src_rect,double angle,SDL_RendererFlip flip)
{
    this->background->SetTexture(texture);
    this->background->SetSrcRect(src_rect);
    this->background->SetAngle(angle);
    this->background->SetFlip(flip);
}

void FlyGalScene::SetBackground(FlySprite *sprite)
{
    this->background = sprite;
}

void FlyGalScene::SetTexture(std::vector<SDL_Texture*> texture)
{
    for (int i = 0; i < texture.size(); i++)
    {
        this->SetTexture(i,texture[i]);
    }
}

void FlyGalScene::SetTexture(short index,SDL_Texture *texture)
{
    this->sprite[index]->SetTexture(texture);
}


void FlyGalScene::SetSrcRect(std::vector<SDL_Rect*> rect)
{
    for (int i = 0; i < rect.size(); i++)
    {
        this->SetSrcRect(i,rect[i]);
    }
}

void FlyGalScene::SetSrcRect(short index,SDL_Rect *rect)
{
    this->sprite[index]->SetSrcRect(rect);
}


void FlyGalScene::SetDestRect(std::vector<SDL_FRect*> rect)
{
    for (int i = 0; i < rect.size(); i++)
    {
        this->SetDestRect(i,rect[i]);
    }
}

void FlyGalScene::SetDestRect(short index,SDL_FRect *rect)
{
    this->sprite_dest_rect[index] = rect;
}


void FlyGalScene::SetAngle(std::vector<double> angle)
{
    for (int i = 0; i < angle.size(); i++)
    {
        this->SetAngle(i,angle[i]);
    }
}

void FlyGalScene::SetAngle(short index,double angle)
{
    this->sprite[index]->SetAngle(angle);
}


void FlyGalScene::SetFlip(std::vector<SDL_RendererFlip> flip)
{
    for (int i = 0; i < flip.size(); i++)
    {
        this->SetFlip(i,flip[i]);
    }
}

void FlyGalScene::SetFlip(short index,SDL_RendererFlip flip)
{
    this->sprite[index]->SetFlip(flip);
}


void FlyGalScene::Render(SDL_Renderer *renderer)
{
    this->background->Render(renderer);
    for (int i = 0; i < this->sprite.size(); i++)
    {
        int error = this->sprite[i]->Render(renderer,this->sprite_dest_rect[i]);
    }
}

void FlyGalScene::AddSprite(FlySprite *sprite,SDL_FRect *dest_rect)
{
    this->sprite.push_back(sprite);
    this->sprite_dest_rect.push_back(dest_rect);
}

void FlyGalScene::AddSprite(FlySprite *sprite,float x,float y,float w,float h)
{
    SDL_FRect *rect = new SDL_FRect();
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    this->sprite.push_back(sprite);
    this->sprite_dest_rect.push_back(rect);
}

void FlyGalScene::AddSprite(SDL_Texture *texture,SDL_FRect *dest_rect)
{
    this->AddSprite(texture,NULL,dest_rect,0,SDL_FLIP_NONE);
}

/*
void FlyGalScene::Add(SDL_Texture *texture,SDL_Rect *src_rect,SDL_FRect *dest_rect,double angle)
{
    this->Add(texture,src_rect,dest_rect,angle,SDL_FLIP_NONE);
}
*/

void FlyGalScene::AddSprite(SDL_Texture *texture,SDL_Rect *src_rect,SDL_FRect *dest_rect,double angle,SDL_RendererFlip flip)
{
    this->sprite.push_back(new FlySprite(texture,src_rect,angle,flip));
    this->sprite_dest_rect.push_back(dest_rect);
}



