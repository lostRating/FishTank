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

#include "fish_gui.h"

void gui::setcolor(int x,int y,std::string what)
{
	PyTuple_SetItem(argv_py,0,Py_BuildValue("l",x));
	PyTuple_SetItem(argv_py,1,Py_BuildValue("l",y));
	PyTuple_SetItem(argv_py,2,Py_BuildValue("s",what.c_str()));
	PyEval_CallObject(func_py,argv_py);
}
