#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctime>

#include "fish_sys.h"

info root;
//gui gui_py;

int main()
{
	srand(time(0));
	freopen("play.log","w",stdout);
	sys hehe("egoist");
	Py_Finalize();
	fclose(stdout);
	return 0;
}
