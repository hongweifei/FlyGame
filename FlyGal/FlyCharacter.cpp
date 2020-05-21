

#include "FlyCharacter.h"


FlyGalCharacter::FlyGalCharacter(std::string name)
{
    this->name = name;
    this->sprite = new FlySprite(NULL);
}

FlyGalCharacter::FlyGalCharacter(std::string name,SDL_Texture* texture)
{
    this->name = name;
    this->sprite = new FlySprite(texture);
}

FlyGalCharacter::~FlyGalCharacter()
{
    delete this->sprite;
}

void FlyGalCharacter::SetImage(SDL_Texture* texture)
{
    this->sprite->SetTexture(texture);
}

std::string FlyGalCharacter::GetName()
{
    return this->name;
}

void FlyGalCharacter::Render(SDL_Renderer *renderer)
{
    if(this->show)
        this->sprite->Render(renderer);
}

void FlyGalCharacter::Show()
{
    this->show = true;
}

void FlyGalCharacter::Hide()
{
    this->show = false;
}

void FlyGalCharacter::Say(std::string text)
{

}


