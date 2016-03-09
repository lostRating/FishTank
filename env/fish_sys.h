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

#include "i_am_not_constants.h"
#include "fish.h"
#include "fish_info.h"

extern info root;
//extern gui gui_py;

struct sys_pl
{
	int id;
	fish *ai;
	sys_pl(fish *__ai){ai=__ai;}
	bool operator< (const sys_pl &b)const {return id<b.id;}
};

class sys
{

private:

	int tot;
	std::vector<sys_pl> sys_data;

	int random(int);                        //随机int范围内的数
	void separate();                        //输出一行 -----------
	void add_new_player(fish*,std::string); //加入新ai
	void get_place(int&,int&);              //随机一个位置
	void get_random_id();                   //随机分配id
	void game_init();                       //初始化
	void work(int);                         //每个round的主过程
	void result();                          //输出结果
	void random_food();                     //生成水藻
	void game_revive();                     //复活

public:

	sys(std::string);
	~sys(){};

};
