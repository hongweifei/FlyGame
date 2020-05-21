


#include <Lua/lua.hpp>


#ifndef FLY_GAL_LUA
#define FLY_GAL_LUA

class FlyGalLua
{
private:
    lua_State *l;
public:
    FlyGalLua();
    FlyGalLua(lua_State *l);
    ~FlyGalLua();

    void AddInteger(const char *name,int data);
    void AddBoolean(const char *name,bool data);
    void AddString(const char *name,const char *data);
    void RegisterFunction(const char *function_name,lua_CFunction function);

    void AddUserData(void *data);

    lua_State *GetL();
};




#endif


