

#include "FlyGalLua.h"
#include "FlyScene.h"
#include "FlyCharacter.h"

namespace LuaSprite
{
    int Create(lua_State *l)
    {
        lua_pushlightuserdata(l,new FlySprite());
        return 1;
    }

    int SetTexture(lua_State *l)
    {
        FlySprite *sprite = (FlySprite*)lua_touserdata(l,1);
        sprite->SetTexture((SDL_Texture*)lua_touserdata(l,2));
        return 1;
    }
}

namespace LuaScene
{
    int Create(lua_State *l)
    {
        lua_pushlightuserdata(l,new FlyScene());
        return 1;
    }

    int SetBackground(lua_State *l)
    {
        FlyScene *scene = (FlyScene*)lua_touserdata(l,1);
        scene->SetBackground((FlySprite*)lua_touserdata(l,2));
        return 1;
    }

    int Render(lua_State *l)
    {
        FlyScene *scene = (FlyScene*)lua_touserdata(l,2);
        scene->Render((SDL_Renderer*)lua_touserdata(l,1));
        return 1;
    }
}

namespace LuaCharacter
{
    int Create(lua_State *l)
    {
        lua_pushlightuserdata(l,new FlyGalCharacter(lua_tostring(l,1)));
        return 1;
    }

    int GetName(lua_State *l)
    {
        lua_pushstring(l,((FlyGalCharacter*)lua_touserdata(l,1))->GetName().c_str());
        return 1;
    }

    int Render(lua_State *l)
    {
        return 1;
    }
}


FlyGalLua::FlyGalLua()
{
    this->l = luaL_newstate();
    FlyGalLua(this->l);
}

FlyGalLua::FlyGalLua(lua_State *l)
{
    this->l = l;

    //GAL
    lua_newtable(l);

    //精灵
    lua_pushstring(l,"精灵");

    //精灵下的函数
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaSprite::Create);
    lua_settable(l,-3);
    lua_pushstring(l,"设置图像");
    lua_pushcfunction(l,LuaSprite::SetTexture);
    lua_settable(l,-3);

    //精灵
    lua_settable(l,-3);

    //人物
    lua_pushstring(l,"人物");
    //人物下的函数
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaCharacter::Create);
    lua_settable(l,-3);
    lua_pushstring(l,"获取名字");
    lua_pushcfunction(l,LuaCharacter::GetName);
    lua_settable(l,-3);

    //人物
    lua_settable(l,-3);


    //场景
    lua_pushstring(l,"场景");
    //场景下的function
    lua_newtable(l);
    lua_pushstring(l,"创建");
    lua_pushcfunction(l,LuaScene::Create);
    lua_settable(l,-3);
    lua_pushstring(l,"设置背景");
    lua_pushcfunction(l,LuaScene::SetBackground);
    lua_settable(l,-3);
    lua_pushstring(l,"渲染");
    lua_pushcfunction(l,LuaScene::Render);
    lua_settable(l,-3);

    //场景
    lua_settable(l,-3);


    //GAL
    lua_setglobal(l,"gal");
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


