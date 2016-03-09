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

	int random(int);                        //���int��Χ�ڵ���
	void separate();                        //���һ�� -----------
	void add_new_player(fish*,std::string); //������ai
	void get_place(int&,int&);              //���һ��λ��
	void get_random_id();                   //�������id
	void game_init();                       //��ʼ��
	void work(int);                         //ÿ��round��������
	void result();                          //������
	void random_food();                     //����ˮ��
	void game_revive();                     //����

public:

	sys(std::string);
	~sys(){};

};
