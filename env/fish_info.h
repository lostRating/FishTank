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
#include "fish_gui.h"

//extern gui gui_py;

struct info_pl
{
	bool move,attack;
	int id,dead,score,point,level,exp,x,y,str,sp,hp,maxhp,st;
	std::string name;

	info_pl(){}

	info_pl(std::string __name)
	{
		name=__name;
		level=1;
		exp=0;
		str=0;
		sp=0;
		hp=0;
		maxhp=0;
		point=10;
		score=0;
		dead=0;
	}

};

class info
{

private:

	std::vector<info_pl> data;
	bool init_ing;
	bool revive_ing;
	int map[N+1][M+1];
	int tot;
	int dead;
	info_pl nowpl;

	void levelup(info_pl&);

public:

	friend bool cmp_score_id(const info_pl&,const info_pl&);
	friend bool cmp_sp(const info_pl&,const info_pl&);
	friend bool cmp_id(const info_pl&,const info_pl&);

	friend class sys;

	info(){}
	~info(){}

	bool move(int,int);//移动到某个位置
	bool attack(int,int);//攻击某个位置
	int getPoint();//返回当前玩家剩余点数
	int getLevel();//返回当前玩家等级
	int getExp();//返回当前玩家经验
	int getX();//返回当前玩家横坐标
	int getY();//返回当前玩家纵坐标
	int getHP();//返回当前玩家生命值
	int getMaxHP();//返回当前玩家生命上限
	int getAtt();//hollysky返回当前玩家攻击力
	int getSp();//返回当前玩家速度
	int getID();//获取玩家ID
	int askWhat(int,int);//返回地图某个位置内容（玩家ID或FOOD或EMPTY）
	int askHP(int);//询问某个玩家ID当前血量
	bool increaseHealth();//增加health属性1
  bool increaseStrength();//增加Strength属性1
	bool increaseSpeed();//增加Speed属性1
	int getTotalPlayer();

};
