


#include "FlyScene.h"


FlyScene::FlyScene()
{
}

FlyScene::FlyScene(SDL_Texture *texture,SDL_Rect *src_rect,double angle,SDL_RendererFlip flip)
{
    this->background = texture;
    this->background_src_rect = src_rect;
    this->background_angle = angle;
    this->background_flip = flip;
}

FlyScene::FlyScene(std::vector<SDL_Texture*> texture)
{
    for (int i = 0; i < texture.size(); i++)
    {
        this->sprite.push_back(new FlySprite(texture[i]));
        this->sprite_dest_rect.push_back(NULL);
    }
}

FlyScene::FlyScene(std::vector<SDL_Texture*> texture,std::vector<SDL_FRect*> dest_rect)
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

FlyScene::FlyScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect)
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


FlyScene::FlyScene(std::vector<SDL_Texture*> texture,std::vector<SDL_Rect*> src_rect,std::vector<SDL_FRect*> dest_rect,
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

FlyScene::~FlyScene()
{
    SDL_DestroyTexture(this->background);
    SDL_free(this->background_src_rect);
    for (int i = 0; i < this->sprite.size(); i++)
    {
        delete this->sprite[i];
        SDL_free(this->sprite_dest_rect[i]);
    }
}


void FlyScene::SetBackground(SDL_Texture *texture,SDL_Rect *src_rect,double angle,SDL_RendererFlip flip)
{
    this->background = texture;
    this->background_src_rect = src_rect;
    this->background_angle = angle;
    this->background_flip = flip;
}

void FlyScene::SetBackground(FlySprite *sprite)
{
    this->background = sprite->GetTexture();
    this->background_src_rect = sprite->GetSrcRect();
    this->background_angle = sprite->GetAngle();
    this->background_flip = sprite->GetFlip();
}

void FlyScene::SetTexture(std::vector<SDL_Texture*> texture)
{
    for (int i = 0; i < texture.size(); i++)
    {
        this->SetTexture(i,texture[i]);
    }
}

void FlyScene::SetTexture(short index,SDL_Texture *texture)
{
    this->sprite[index]->SetTexture(texture);
}


void FlyScene::SetSrcRect(std::vector<SDL_Rect*> rect)
{
    for (int i = 0; i < rect.size(); i++)
    {
        this->SetSrcRect(i,rect[i]);
    }
}

void FlyScene::SetSrcRect(short index,SDL_Rect *rect)
{
    this->sprite[index]->SetSrcRect(rect);
}


void FlyScene::SetDestRect(std::vector<SDL_FRect*> rect)
{
    for (int i = 0; i < rect.size(); i++)
    {
        this->SetDestRect(i,rect[i]);
    }
}

void FlyScene::SetDestRect(short index,SDL_FRect *rect)
{
    this->sprite_dest_rect[index] = rect;
}


void FlyScene::SetAngle(std::vector<double> angle)
{
    for (int i = 0; i < angle.size(); i++)
    {
        this->SetAngle(i,angle[i]);
    }
}

void FlyScene::SetAngle(short index,double angle)
{
    this->sprite[index]->SetAngle(angle);
}


void FlyScene::SetFlip(std::vector<SDL_RendererFlip> flip)
{
    for (int i = 0; i < flip.size(); i++)
    {
        this->SetFlip(i,flip[i]);
    }
}

void FlyScene::SetFlip(short index,SDL_RendererFlip flip)
{
    this->sprite[index]->SetFlip(flip);
}


void FlyScene::Render(SDL_Renderer *renderer)
{
    SDL_RenderCopyEx(renderer,this->background,this->background_src_rect,NULL,this->background_angle,NULL,this->background_flip);
    for (int i = 0; i < this->sprite.size(); i++)
    {
        int error = this->sprite[i]->Render(renderer,this->sprite_dest_rect[i]);
        if (error == -1)
        {
            //printf("%s\n",SDL_GetError());
        }
    }
}


void FlyScene::Add(SDL_Texture *texture,SDL_FRect *dest_rect)
{
    this->Add(texture,NULL,dest_rect,0,SDL_FLIP_NONE);
}

/*
void FlyScene::Add(SDL_Texture *texture,SDL_Rect *src_rect,SDL_FRect *dest_rect,double angle)
{
    this->Add(texture,src_rect,dest_rect,angle,SDL_FLIP_NONE);
}
*/

void FlyScene::Add(SDL_Texture *texture,SDL_Rect *src_rect,SDL_FRect *dest_rect,double angle,SDL_RendererFlip flip)
{
    this->sprite.push_back(new FlySprite(texture,src_rect,angle,flip));
    this->sprite_dest_rect.push_back(dest_rect);
}



