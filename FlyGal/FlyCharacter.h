

#include <string>
#include "FlySprite.h"

#ifndef FLYCHARACTER
#define FLYCHARACTER


class FlyGalCharacter
{
private:
    std::string name;
    FlySprite *sprite;

    bool show = true;
public:
    FlyGalCharacter(std::string name);
    FlyGalCharacter(std::string name,SDL_Texture* texture);
    ~FlyGalCharacter();

    void SetImage(SDL_Texture* texture);
    std::string GetName();

    void Render(SDL_Renderer *renderer);

    void Show();
    void Hide();
    void Say(std::string text);
};




#endif

