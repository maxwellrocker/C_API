#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

/**/
int main(void){
	char buff[256];
	int error;
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	
	while(fgets(buff, sizeof(buff), stdin) != NULL){
		error = luaL_loadbuffer(L, buff, strlen(buff), "line") ||
				lua_pcall(L, 0, 0, 0);
		if(error){
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}
	
	lua_close(L);
	return 0;
}

void error(lua_State* L, const char *fmt, ...){
	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	lua_close(L);
	exit(EXIT_FAILURE);
}


/*
void load (lua_State* L, const char* fname, int* w, int* h)
{
	if(luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
		error(L, "cannot run config. file: %s", lua_tostring(L, -1));
	lua_getglobal(L, "width");
	lua_getglobal(L, "height");
	if(!lua_isnumber(L, -2))
		error(L, "'width' should be a number\n");
	if(!lua_isnumber(L, -1))
		error(L, "'width' should be a number\n");
		
	*w = lua_tointeger(L, -2);
	*h = lua_tointeger(L, -1);
}
*/

/*
#define MAX_COLOR 255
int getfield(lua_State *L, const char* key){
	int result;
	lua_pushstring(L, key);
	lua_gettable(L, -2);
	if(!lua_isnumber(L, -1))
		error(L, "invalid component in back ground color");
	result = (int)lua_tonumber(L, -1) * MAX_COLOR;
	lua_pop(L, 1);
	return result;
}
*/

/*
lua_getglobal(L, "background");
if(lua_isstring(L, -1)){
	const char* name = lua_tostring(L, -1);
	int i;
	for(i = 0; colortable[i].name != NULL; i++){
		if(strcmp(colorname, colortable[i].name) == 0)
			break;
	}
	if(colortable[i].name == NULL)
		error(L, "invalid color name(%s)", colorname);
	else{
		red		= colortable[i].red;
		green	= colortable[i].green;
		bloe	= colortable[i].blue;
	}
}
else if(lua_istable(L, -1)){
	red		= getfield(L, "r");
	green	= getfield(L, "g");
	bloe	= getfield(L, "b");
}
else{
	error(L, "invalid value for 'background'");
}
*/

