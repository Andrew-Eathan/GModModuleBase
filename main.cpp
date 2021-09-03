/*

	------- GMOD Binary Module Base by AndrewEathan -------

	This example module comes pre-packaged with https://github.com/Facepunch/gmod-module-base/tree/development, and it's fully set up with Debug/Release x32/x64 building.
	It hasn't been updated in 2 years so you can be sure you're not missing out on potential updates, while also avoiding tedious downloading and setup. 
	The Additional Include Directory is set to $(SolutionDir)include, so place any includes there, or modify it yourself in the project settings if you wish.

	By default this builds to a clientside module, but building for serverside is as simple as changing the name of the dll from gmcl_ to gmsv_.
	To build to both, you can create another template project in this solution for the other realm, clientside or serverside.

	After you build, place the .dll in garrysmod/lua/bin.
	NOTE: If you use any other dlls in your binary module, they will need to be placed in the GarrysMod folder!
	Garry's Mod loads those dlls from its root folder (again, GarrysMod)

	To include the resulting module in Garry's Mod, simply write:
		require("binary_module_name")

	Including the prefix/suffix of the .dll's name isn't necessary, Garry's Mod does the work for you there.
	To change the output module name, simply change the solution name.

*/

#include "GarrysMod/Lua/Interface.h"
#include <string>

using namespace GarrysMod::Lua;

void LUA_Print(ILuaBase* LUA, std::string text)
{
	LUA->PushSpecial(SPECIAL_GLOB);
	LUA->GetField(-1, "print");
	LUA->PushString(text.c_str());
	LUA->Call(1, 0);
	LUA->Pop();
}

// Called when the module is loaded
GMOD_MODULE_OPEN()
{
	LUA_Print(LUA, "Module opened");
	LUA_Print(LUA, "hi");
	return 0;
}

// Called when the module is unloaded
GMOD_MODULE_CLOSE()
{
	LUA_Print(LUA, "Module closed");
	return 0;
}