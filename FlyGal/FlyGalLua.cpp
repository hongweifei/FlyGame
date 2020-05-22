

#include "FlyGalLua.h"
#include "FlyGalScene.h"
#include "FlyGalCharacter.h"

#include "FlyQueue.h"

#include <SDL2/SDL_image.h>

namespace LuaRect
{
    /**
     * fly.矩形.创建(x,y,w,h)
     * fly.矩形.创建A(x,y,w,h)
    */
    int CreateRect(lua_State *l)
    {
        SDL_Rect *rect = new SDL_Rect();
        rect->x = lua_tointeger(l,1);
        rect->y = lua_tointeger(l,2);
        rect->w = lua_tointeger(l,3);
        rect->h = lua_tointeger(l,4);
        lua_pushlightuserdata(l,rect);
        return 1;
    }

    /**
     * fly.矩形.创建B(x,y,w,h)
    */
    int CreateFRect(lua_State *l)
    {
        SDL_FRect *rect = new SDL_FRect();
        rect->x = lua_tonumber(l,1);
        rect->y = lua_tonumber(l,2);
        rect->w = lua_tonumber(l,3);
        rect->h = lua_tonumber(l,4);
        lua_pushlightuserdata(l,rect);
        return 1;
    }
} // namespace LuaRect

namespace LuaTexture
{
    /**
     * fly.图像.加载(renderer,图像路径)
    */
    int LoadTexture(lua_State *l)
    {
        lua_pushlightuserdata(l,IMG_LoadTexture((SDL_Renderer*)lua_touserdata(l,1),lua_tostring(l,2)));
    }

    /**
     * fly.图像.加载XPM图像数组(renderer,图像数组)
    */
    int LoadXPM(lua_State *l)
    {
        SDL_Surface *surface = IMG_ReadXPMFromArray((char**)lua_touserdata(l,2));
        SDL_Texture *texture = SDL_CreateTextureFromSurface((SDL_Renderer*)lua_touserdata(l,1),surface);
        SDL_FreeSurface(surface);
        lua_pushlightuserdata(l,texture);
    }
} // namespace LuaTexture


namespace LuaFlySprite
{
    /**
     * fly.精灵.创建()
    */
    int Create(lua_State *l)
    {
        lua_pushlightuserdata(l,new FlySprite());
        return 1;
    }

    /**
     * fly.精灵.获取图像(精灵)
    */
    int GetTexture(lua_State *l)
    {
        lua_pushlightuserdata(l,((FlySprite*)lua_touserdata(l,1))->GetTexture());
        return 1;
    }

    /**
     * fly.精灵.获取裁剪(精灵)
     * fly.精灵.获取剪裁(精灵)
    */
    int GetSrcRect(lua_State *l)
    {
        lua_pushlightuserdata(l,((FlySprite*)lua_touserdata(l,1))->GetSrcRect());
        return 1;
    }

    /**
     * fly.精灵.获取旋转(精灵)
    */
    int GetAngle(lua_State *l)
    {
        lua_pushnumber(l,((FlySprite*)lua_touserdata(l,1))->GetAngle());
        return 1;
    }

    /**
     * fly.精灵.获取翻转(精灵)
    */
    int GetFlip(lua_State *l)
    {
        lua_pushinteger(l,((FlySprite*)lua_touserdata(l,1))->GetFlip());
        return 1;
    }

    
    /**
     * fly.精灵.设置图像(精灵，欲设置图像)
    */
    int SetTexture(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,1);
        sprite->SetTexture((SDL_Texture*)lua_touserdata(l,2));
        return 1;
    }

    /**
     * fly.精灵.设置裁剪(精灵,src_rect)
     * fly.精灵.设置剪裁(精灵,src_rect)
     * fly.精灵.设置裁剪A(精灵,src_rect)
     * fly.精灵.设置剪裁A(精灵,src_rect)
    */
    int SetSrcRectA(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,1);
        sprite->SetSrcRect((SDL_Rect*)lua_touserdata(l,2));
        return 1;
    }
    
    /**
     * fly.精灵.设置裁剪B(精灵,x,y,w,h)
     * fly.精灵.设置剪裁B(精灵,x,y,w,h)
    */
    int SetSrcRectB(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,1);
        sprite->SetSrcRect(lua_tointeger(l,2),lua_tointeger(l,3),lua_tointeger(l,4),lua_tointeger(l,5));
        return 1;
    }
    
    /**
     * fly.精灵.设置旋转(精灵,旋转角度)
    */
    int SetAngle(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,1);
        sprite->SetAngle(lua_tonumber(l,2));
        return 1;
    }
    
    /**
     * fly.精灵.设置翻转(精灵,翻转)
    */
    int SetFlip(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,1);
        sprite->SetFlip((SDL_RendererFlip)lua_tointeger(l,2));
        return 1;
    }

    /**
     * fly.精灵.绘制(renderer,精灵,dest)
     * fly.精灵.绘制A(renderer,精灵,dest)
    */
    int RenderA(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,2);
        sprite->Render((SDL_Renderer*)lua_touserdata(l,1),(SDL_Rect*)lua_touserdata(l,3));
        return 1;
    }

    /**
     * fly.精灵.绘制B(renderer,精灵,dest)
    */
    int RenderB(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,2);
        sprite->Render((SDL_Renderer*)lua_touserdata(l,1),(SDL_FRect*)lua_touserdata(l,3));
        return 1;
    }
}

namespace LuaFlyGalScene
{
    /**
     * fly.gal.场景.创建()
    */
    int Create(lua_State *l)
    {
        lua_pushlightuserdata(l,new FlyGalScene());
        return 1;
    }

    /**
     * fly.gal.场景.设置背景(场景,精灵)
    */
    int SetBackground(lua_State *l)
    {
        FlyGalScene *scene = (FlyGalScene*)lua_touserdata(l,1);
        scene->SetBackground((FlySprite*)lua_touserdata(l,2));
        return 1;
    }

    /**
     * fly.gal.场景.添加精灵(场景,精灵,dest_rect)
     * fly.gal.场景.添加精灵A(场景,精灵,dest_rect)
    */
    int AddSpriteA(lua_State *l)
    {
        FlyGalScene *scene = (FlyGalScene*)lua_touserdata(l,1);
        scene->AddSprite((FlySprite*)lua_touserdata(l,2),(SDL_FRect*)lua_touserdata(l,3));
        return 1;
    }

    /**
     * fly.gal.场景.添加精灵B(场景,精灵,x,y,w,h)
    */
    int AddSpriteB(lua_State *l)
    {
        FlyGalScene *scene = (FlyGalScene*)lua_touserdata(l,1);
        scene->AddSprite((FlySprite*)lua_touserdata(l,2),lua_tonumber(l,3),lua_tonumber(l,4),lua_tonumber(l,5),lua_tonumber(l,6));
        return 1;
    }

    /**
     * fly.gal.场景.绘制(renderer,场景)
    */
    int RenderA(lua_State *l)
    {
        FlyGalScene *scene = (FlyGalScene*)lua_touserdata(l,2);
        scene->Render((SDL_Renderer*)lua_touserdata(l,1));
        return 1;
    }
}

namespace LuaFlyGalCharacter
{
    /**
     * fly.gal.人物.创建(name)
    */
    int Create(lua_State *l)
    {
        lua_pushlightuserdata(l,new FlyGalCharacter(lua_tostring(l,1)));
        return 1;
    }

    /**
     * fly.gal.人物.设置图像(人物,图像)
    */
    int SetTexture(lua_State *l)
    {
        FlyGalCharacter *character = (FlyGalCharacter*)lua_touserdata(l,1);
        character->SetTexture((SDL_Texture*)lua_touserdata(l,2));
        return 1;
    }

    /**
     * fly.gal.人物.获取名字(人物)
    */
    int GetName(lua_State *l)
    {
        lua_pushstring(l,((FlyGalCharacter*)lua_touserdata(l,1))->GetName().c_str());
        return 1;
    }

    /**
     * fly.gal.人物.绘制(renderer,人物)
     * fly.gal.人物.绘制A(renderer,人物)
    */
    int RenderA(lua_State *l)
    {
        return 1;
    }
}


namespace LuaFlyGalGame
{
    enum FlyGalGameEventType
    {
        FlyGalGameEventType_NONE,
        FlyGalGameEventType_SetScene,
        FlyGalGameEventType_Say,
    };

    struct FlyGalGameEvent
    {
        FlyGalGameEventType type;
        void *data1;
        void *data2;
        void *data3;

        FlyGalGameEvent(FlyGalGameEventType type,void *data1 = NULL,void *data2 = NULL,void *data3 = NULL)
        {
            this->type = type;
            this->data1 = data1;
            this->data2 = data2;
            this->data3 = data3;
        }
    };
    
    static SDL_Renderer *renderer = NULL;

    static FlyQueue<FlyGalGameEvent*> *queue = new FlyQueue<FlyGalGameEvent*>();
    static FlyGalScene *scene = new FlyGalScene();


    int Init(lua_State *l)
    {
        renderer = (SDL_Renderer*)lua_touserdata(l,1);
        return 1;
    }

    int MainLoop(lua_State *l)
    {
        static FlyGalGameEvent *game_event = new FlyGalGameEvent(FlyGalGameEventType_NONE);
        static bool game_next = true;

        if (game_next)
        {
            game_next = false;

            if ((game_event = queue->Get()) != NULL)
            {
                switch (game_event->type)
                {
                case FlyGalGameEventType_SetScene:
                    scene = (FlyGalScene*)game_event->data1;
                    game_next = true;
                    break;

                case FlyGalGameEventType_Say:
                    ((FlyGalCharacter*)game_event->data1)->Say((const char*)game_event->data2);
                    break;
                
                default:
                    game_next = true;
                    break;
                }
            }
        }
        

        static SDL_Event e;
        if (SDL_WaitEvent(&e))
        {
            switch (e.type)
            {
            case SDL_MOUSEBUTTONDOWN:
                game_next = true;
                //printf("mouse_button_down\n");
                break;
            }
        }
        
        scene->Render(renderer);
        
        return 1;
    }

    int SetScene(lua_State *l)
    {
        FlyGalGameEvent *event = new FlyGalGameEvent(FlyGalGameEventType_SetScene,lua_touserdata(l,1));
        queue->Add(event);
        return 1;
    }

    int Say(lua_State *l)
    {
        FlyGalGameEvent *event = new FlyGalGameEvent(FlyGalGameEventType_Say,lua_touserdata(l,1),(void*)lua_tostring(l,2));
        queue->Add(event);
        return 1;
    }
} // namespace LuaFlyGalGame



FlyGalLua::FlyGalLua()
{
    this->l = luaL_newstate();
    FlyGalLua(this->l);
}

FlyGalLua::FlyGalLua(lua_State *l)
{
    this->l = l;

    //Fly
    lua_newtable(l);

    
    //Rect
    lua_pushstring(l,"矩形");

    //Rect下函数
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaRect::CreateRect);
    lua_settable(l,-3);
    lua_pushstring(l,"创建A");
    lua_pushcfunction(l,LuaRect::CreateRect);
    lua_settable(l,-3);
    lua_pushstring(l,"创建B");
    lua_pushcfunction(l,LuaRect::CreateFRect);
    lua_settable(l,-3);

    //Rect
    lua_settable(l,-3);


    //Rect
    lua_pushstring(l,"图像");

    //Rect下函数
    lua_newtable(l);
    lua_pushstring(l,"加载");
    lua_pushcfunction(l,LuaTexture::LoadTexture);
    lua_settable(l,-3);
    lua_pushstring(l,"加载XPM图像数组");
    lua_pushcfunction(l,LuaTexture::LoadXPM);
    lua_settable(l,-3);

    //Rect
    lua_settable(l,-3);


    //精灵
    lua_pushstring(l,"精灵");

    //精灵下的函数
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaFlySprite::Create);
    lua_settable(l,-3);

    lua_pushstring(l,"设置图像");
    lua_pushcfunction(l,LuaFlySprite::SetTexture);
    lua_settable(l,-3);

    lua_pushstring(l,"设置裁剪");
    lua_pushcfunction(l,LuaFlySprite::SetSrcRectA);
    lua_settable(l,-3);
    lua_pushstring(l,"设置剪裁");
    lua_pushcfunction(l,LuaFlySprite::SetSrcRectA);
    lua_settable(l,-3);
    lua_pushstring(l,"设置裁剪A");
    lua_pushcfunction(l,LuaFlySprite::SetSrcRectA);
    lua_settable(l,-3);
    lua_pushstring(l,"设置剪裁A");
    lua_pushcfunction(l,LuaFlySprite::SetSrcRectA);
    lua_settable(l,-3);
    lua_pushstring(l,"设置裁剪B");
    lua_pushcfunction(l,LuaFlySprite::SetSrcRectB);
    lua_settable(l,-3);
    lua_pushstring(l,"设置剪裁B");
    lua_pushcfunction(l,LuaFlySprite::SetSrcRectB);
    lua_settable(l,-3);

    lua_pushstring(l,"设置旋转");
    lua_pushcfunction(l,LuaFlySprite::SetAngle);
    lua_settable(l,-3);
    lua_pushstring(l,"设置翻转");
    lua_pushcfunction(l,LuaFlySprite::SetFlip);
    lua_settable(l,-3);

    lua_pushstring(l,"获取图像");
    lua_pushcfunction(l,LuaFlySprite::GetTexture);
    lua_settable(l,-3);
    lua_pushstring(l,"获取裁剪");
    lua_pushcfunction(l,LuaFlySprite::GetSrcRect);
    lua_settable(l,-3);
    lua_pushstring(l,"获取剪裁");
    lua_pushcfunction(l,LuaFlySprite::GetSrcRect);
    lua_settable(l,-3);
    lua_pushstring(l,"获取旋转");
    lua_pushcfunction(l,LuaFlySprite::GetAngle);
    lua_settable(l,-3);
    lua_pushstring(l,"获取翻转");
    lua_pushcfunction(l,LuaFlySprite::GetFlip);
    lua_settable(l,-3);

    lua_pushstring(l,"绘制");
    lua_pushcfunction(l,LuaFlySprite::RenderA);
    lua_settable(l,-3);
    lua_pushstring(l,"绘制A");
    lua_pushcfunction(l,LuaFlySprite::RenderA);
    lua_settable(l,-3);
    lua_pushstring(l,"绘制B");
    lua_pushcfunction(l,LuaFlySprite::RenderB);
    lua_settable(l,-3);

    //精灵
    lua_settable(l,-3);


    //GAL
    lua_pushstring(l,"gal");
    lua_newtable(l);

    //人物
    lua_pushstring(l,"人物");
    //人物下的函数
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaFlyGalCharacter::Create);
    lua_settable(l,-3);
    lua_pushstring(l,"获取名字");
    lua_pushcfunction(l,LuaFlyGalCharacter::GetName);
    lua_settable(l,-3);

    //人物
    lua_settable(l,-3);


    //场景
    lua_pushstring(l,"场景");
    //场景下的function
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaFlyGalScene::Create);
    lua_settable(l,-3);
    lua_pushstring(l,"设置背景");
    lua_pushcfunction(l,LuaFlyGalScene::SetBackground);
    lua_settable(l,-3);

    lua_pushstring(l,"添加精灵");
    lua_pushcfunction(l,LuaFlyGalScene::AddSpriteA);
    lua_settable(l,-3);
    lua_pushstring(l,"添加精灵A");
    lua_pushcfunction(l,LuaFlyGalScene::AddSpriteA);
    lua_settable(l,-3);
    lua_pushstring(l,"添加精灵B");
    lua_pushcfunction(l,LuaFlyGalScene::AddSpriteB);
    lua_settable(l,-3);

    lua_pushstring(l,"绘制");
    lua_pushcfunction(l,LuaFlyGalScene::RenderA);
    lua_settable(l,-3);
    lua_pushstring(l,"绘制A");
    lua_pushcfunction(l,LuaFlyGalScene::RenderA);
    lua_settable(l,-3);

    //场景
    lua_settable(l,-3);


    //游戏
    lua_pushstring(l,"游戏");

    //游戏下的函数
    lua_newtable(l);
    lua_pushstring(l,"初始化");
    lua_pushcfunction(l,LuaFlyGalGame::Init);
    lua_settable(l,-3);
    lua_pushstring(l,"主循环");
    lua_pushcfunction(l,LuaFlyGalGame::MainLoop);
    lua_settable(l,-3);

    lua_pushstring(l,"设置场景");
    lua_pushcfunction(l,LuaFlyGalGame::SetScene);
    lua_settable(l,-3);
    lua_pushstring(l,"说");
    lua_pushcfunction(l,LuaFlyGalGame::Say);
    lua_settable(l,-3);

    //游戏
    lua_settable(l,-3);


    //GAL
    lua_settable(l,-3);


    //Fly
    lua_setglobal(l,"fly");
}


FlyGalLua::~FlyGalLua()
{
    lua_close(this->l);
}

void FlyGalLua::AddInteger(const char *name,int data)
{
    lua_newtable(l);
    lua_pushinteger(l,data);
    lua_setglobal(l,name);
}

void FlyGalLua::AddBoolean(const char *name,bool data)
{
    lua_newtable(l);
    lua_pushboolean(l,data);
    lua_setglobal(l,name);
}

void FlyGalLua::AddString(const char *name,const char *data)
{
    lua_newtable(l);
    lua_pushstring(l,data);
    lua_setglobal(l,name);
}

void FlyGalLua::RegisterFunction(const char *function_name,lua_CFunction function)
{
    lua_newtable(l);
    lua_pushcfunction(l,NULL);
    lua_setglobal(l,function_name);
}

void FlyGalLua::AddUserData(void *data)
{
    lua_pushlightuserdata(l,data);
}

lua_State *FlyGalLua::GetL()
{
    return this->l;
}


