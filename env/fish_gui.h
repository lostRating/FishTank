#pragma once

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

#include "python\Python.h"

class gui
{

private:

	void setcolor(int,int,std::string);
	PyObject *file_py;
	PyObject *func_py;
	PyObject *argv_py;

public:

	friend class sys;
	friend class info;

	gui()
	{
		Py_Initialize();
		file_py=PyImport_ImportModule("fish_gui");
		func_py=PyObject_GetAttrString(file_py,"setcolor");
		argv_py=PyTuple_New(3);
	}

	~gui(){}

};
