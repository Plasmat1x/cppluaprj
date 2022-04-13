extern "C" {
#include "Lua/lua.h"
#include "Lua/lauxlib.h"
#include "Lua/lualib.h"
}

#include <LuaBridge/LuaBridge.h>
#include <iostream>
#include <iomanip>

using namespace luabridge;

void printMessage(const std::string& s)
{
    std::cout << s << std::endl;
}

int main()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    getGlobalNamespace(L).addFunction("printMessage", printMessage);
    luaL_dofile(L, "script.lua");
    lua_pcall(L, 0, 0, 0);
    LuaRef sumNumbers = getGlobal(L, "sumNumbers");
    int result = sumNumbers(5, 4);
    std::cout << "Result:" << result << std::endl;
    system("pause");
}

/*
int main()
{
    lua_State* L = luaL_newstate();

    std::string filename;
    filename = "script.lua";

    //check
    if (luaL_loadfile(L, filename.c_str()) || lua_pcall(L, 0, 0, 0))
    {
        std::cout << "ERROR::" << std::uppercase << filename << "::NOT_FOUND" << std::endl;
        return -1;
    }

    //without check
    lua_State* L = luaL_newstate();
    luaL_dofile(L, "script.lua");
    lua_pcall(L, 0, 0, 0);
    luaL_openlibs(L);
    LuaRef s = getGlobal(L, "testString");
    LuaRef n = getGlobal(L, "number");
    std::string luaString = s.cast<std::string>();
    int answer = n.cast<int>();
    std::cout << luaString << std::endl;
    std::cout << "And here's our number:" << answer << std::endl;

    return 0;
}
*/