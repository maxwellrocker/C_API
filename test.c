#include<stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

int main(void)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, "script.lua");
	
	char buff[256];
	int error;
	while(fgets(buff, sizeof(buff), stdin) != NULL)
	{
		printf(buff);
	}
	
	lua_close(L);
	return 0;
}

/*
int main(int argc, char* argv[])
{
printf("Hello World\n");
}
*/

/*
int main(int argc,char * arg[]){
int a,b,c,d,e,f,i;
a = 0;
b = 8;
c = 29;
d = 44;
e = 444;

printf ("%d %d %d %d %d",a,b,c,d,e);

for (i=0;i<argc;i++) printf("@@ %s \n",arg[i]);
return 0;
}
*/