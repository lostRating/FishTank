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

	bool move(int,int);//�ƶ���ĳ��λ��
	bool attack(int,int);//����ĳ��λ��
	int getPoint();//���ص�ǰ���ʣ�����
	int getLevel();//���ص�ǰ��ҵȼ�
	int getExp();//���ص�ǰ��Ҿ���
	int getX();//���ص�ǰ��Һ�����
	int getY();//���ص�ǰ���������
	int getHP();//���ص�ǰ�������ֵ
	int getMaxHP();//���ص�ǰ�����������
	int getAtt();//hollysky���ص�ǰ��ҹ�����
	int getSp();//���ص�ǰ����ٶ�
	int getID();//��ȡ���ID
	int askWhat(int,int);//���ص�ͼĳ��λ�����ݣ����ID��FOOD��EMPTY��
	int askHP(int);//ѯ��ĳ�����ID��ǰѪ��
	bool increaseHealth();//����health����1
  bool increaseStrength();//����Strength����1
	bool increaseSpeed();//����Speed����1
	int getTotalPlayer();

};
