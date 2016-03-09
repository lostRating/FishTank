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

#include "fish_info.h"

void info::levelup(info_pl &nowpl)
{
	while (nowpl.exp>nowpl.level)
	{
		nowpl.exp-=nowpl.level+1;
		nowpl.level++;
		nowpl.point+=LEVEL_POINT;
	}
}

bool info::move(int x,int y)//�ƶ���ĳ��λ��
{
	if (init_ing) return 0;
	if (revive_ing) return 0;
	if (x<1 || x>N || y<1 || y>M) return 0;
	if (!nowpl.move) return 0;
	if (map[x][y]!=nowpl.id && map[x][y]!=EMPTY) return 0;
	if (abs(x-nowpl.x)+abs(y-nowpl.y)>nowpl.sp) return 0;
	map[nowpl.x][nowpl.y]=0;
//		gui_py.setcolor(nowpl.x,nowpl.y,"");
	nowpl.x=x;
	nowpl.y=y;
	map[x][y]=nowpl.id;
//		gui_py.setcolor(x,y,"fish");
	nowpl.move=0;
	return 1;
}

bool info::attack(int x,int y)//����ĳ��λ��
{
	if (init_ing) return 0;
	if (revive_ing) return 0;
	if (x<1 || x>N || y<1 || y>M) return 0;
	if (!nowpl.attack) return 0;
	if (map[x][y]==EMPTY) return 0;
	if (abs(x-nowpl.x)+abs(y-nowpl.y)!=1) return 0;
	if (map[x][y]==FOOD)
	{
		if (nowpl.str!=0)
		{
			nowpl.attack=0;
			nowpl.move=0;
			map[x][y]=EMPTY;
//				std::cerr<<x<<' '<<y<<'\n';
//				gui_py.setcolor(x,y,"");
			nowpl.exp++;
			nowpl.hp=std::min(nowpl.maxhp,nowpl.hp+std::max(2,nowpl.maxhp/10));
			levelup(nowpl);
			return 1;
		}
		else return 0;
	}
	for (int i=0;i<tot;i++)
		if (data[i].id!=nowpl.id && data[i].x==x && data[i].y==y && data[i].hp>0)
		{
			nowpl.attack=0;
			nowpl.move=0;
			data[i].hp-=nowpl.str;
			if (data[i].hp<=0)
			{
//				std::cout<<data[i].id<<" "<<data[i].hp<<" "<<nowpl.str<<'\n';
				dead++;
				data[i].st=-dead;
				data[i].dead=1;
				map[data[i].x][data[i].y]=EMPTY;
//					std::cerr<<x<<' '<<y<<'\n';
//					gui_py.setcolor(data[i].x,data[i].y,"");
				nowpl.exp+=std::max(1,data[i].level/2);
				if (data[i].level>nowpl.level)
					nowpl.score+=(data[i].level-nowpl.level)*2;
				levelup(nowpl);
				return 1;
			}
		}
}

int info::getPoint()//���ص�ǰ���ʣ�����
{
	return nowpl.point;
}

int info::getLevel()//���ص�ǰ��ҵȼ�
{
	return nowpl.level;
}

int info::getExp()//���ص�ǰ��Ҿ���
{
	return (nowpl.level+1)*nowpl.level/2-1+nowpl.exp;
}

int info::getX()//���ص�ǰ��Һ�����
{
	return nowpl.x;
}

int info::getY()//���ص�ǰ���������
{
	return nowpl.y;
}

int info::getHP()//���ص�ǰ�������ֵ
{
	return nowpl.hp;
}

int info::getMaxHP()//���ص�ǰ�����������
{
	return nowpl.maxhp;
}

int info::getAtt()//���ص�ǰ��ҹ�����
{
	return nowpl.str;
}

int info::getSp()//���ص�ǰ����ٶ�
{
	return nowpl.sp;
}

int info::getID()//��ȡ���ID
{
	return nowpl.id;
}

int info::askWhat(int x,int y)//���ص�ͼĳ��λ�����ݣ����ID��FOOD��EMPTY��
{
	if (init_ing) return EMPTY;
	if (revive_ing) return EMPTY;
	if (x<1 || x>N || y<1 || y>M) return EMPTY;
	return map[x][y];
}

int info::askHP(int id)//ѯ��ĳ�����ID��ǰѪ��
{
	if (nowpl.id==id) return nowpl.hp;
	for (int i=0;i<tot;i++)
		if (data[i].id==id) return data[i].hp;
}

bool info::increaseHealth()//����health����1
{
	if (nowpl.point==0) return 0;
	nowpl.point--;
	nowpl.maxhp+=2;
	nowpl.hp+=2;
	return 1;
}

bool info::increaseStrength()//����Strength����1
{
	if (nowpl.point==0) return 0;
	nowpl.point--;
	nowpl.str++;
	return 1;
}

bool info::increaseSpeed()//����Speed����1
{
	if (nowpl.point==0) return 0;
	nowpl.point--;
	nowpl.sp++;
	return 1;
}

int info::getTotalPlayer()
{
	return data.size();
}
