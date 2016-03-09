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

#include "st01.h"
#include "st02.h"
#include "st03.h"

#include "fish_sys.h"

bool cmp_id(const info_pl &a,const info_pl &b){return a.id<b.id;}
bool cmp_st(const info_pl &a,const info_pl &b){return a.st>b.st;}

bool cmp_sp(const info_pl &a,const info_pl &b)
{
	if (a.sp!=b.sp) return a.sp>b.sp;
	if (a.hp*b.maxhp!=b.hp*a.maxhp) return a.hp*b.maxhp>b.hp*a.maxhp;
	return a.score+a.exp<b.score+b.exp;
}

bool cmp_score_exp_id(const info_pl &a,const info_pl &b)
{
	if (a.score+a.exp!=b.score+b.exp) return a.score+a.exp>b.score+b.exp;
	return a.id<b.id;
}

int sys::random(int n)
{
	int m=(rand()<<15)+rand();
	return m%n;
};

void sys::get_place(int &x,int &y)
{
	while (1)
	{
		x=random(N)+1;
		y=random(M)+1;
		if (root.map[x][y]==EMPTY) return;
	}
}

void sys::separate()
{
	for (int i=0;i<50;i++) std::cout<<'-';
	std::cout<<std::endl;
}

void sys::add_new_player(fish *ai,std::string name)
{
	sys_data.push_back(sys_pl(ai));
	root.data.push_back(info_pl(name));
}

void sys::get_random_id()
{
	std::cout<<"id distribution"<<'\n';
	tot=sys_data.size();
	root.tot=tot;
	std::vector<int> tmp;
	for (int i=0;i<tot;i++) tmp.push_back(i+1);
	random_shuffle(tmp.begin(),tmp.end());
	for (int i=0;i<tot;i++)
	{
		sys_data[i].id=tmp[i];
		sys_data[i].ai->setID(tmp[i]);
		root.data[i].id=tmp[i];
		std::cout<<root.data[i].name<<" 's id : "<<tmp[i]<<'\n';
	}
	separate();
};

void sys::game_init()
{
//	std::cout<<"init"<<'\n';
	root.init_ing=1;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			root.map[i][j]=EMPTY;
	sort(sys_data.begin(),sys_data.end());
	sort(root.data.begin(),root.data.end(),cmp_id);
	for (int i=0;i<tot;i++)
	{

		root.nowpl=root.data[i];
		sys_data[i].ai->init();
		srand(time(0)+rand());
		root.data[i]=root.nowpl;

		if (root.data[i].maxhp!=0)
		{
			int x,y;
			get_place(x,y);
			root.data[i].x=x;
			root.data[i].y=y;
			root.data[i].st=1;
			root.data[i].dead=0;
			root.map[x][y]=root.data[i].id;
//				gui_py.setcolor(x,y,"fish");
		}
		else
		{
			root.dead++;
			root.data[i].dead=1;
			root.data[i].st=-root.dead;
		}
	}
	root.init_ing=0;
//	separate();
}

void sys::random_food()
{
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
			if (root.map[i][j]==FOOD)
			{
				root.map[i][j]=0;
//					gui_py.setcolor(i,j,"");
			}
	for (int i=0;i<MAX_FOOD;i++)
	{
		int x,y;
		get_place(x,y);
		root.map[x][y]=FOOD;
//			gui_py.setcolor(x,y,"food");
	}
}

void sys::game_revive()
{
	root.revive_ing=1;
	sort(root.data.begin(),root.data.end(),cmp_st);
	for (int i=0;i<tot;i++)
	{
		if (root.data[i].dead) root.data[i].dead=0;
		else if (root.data[i].st<0)
		{
			int x,y,id=root.data[i].id;

			root.nowpl=root.data[i];
			sys_data[id-1].ai->revive(x,y);
			srand(time(0)+rand());
			root.data[i]=root.nowpl;

			if (root.data[i].maxhp!=0)
			{
				if (x<1 || x>N || y<1 || y>M || root.map[x][y]!=EMPTY) get_place(x,y);
				root.map[x][y]=id;
				root.data[i].x=x;
				root.data[i].y=y;
				root.data[i].dead=0;
				root.data[i].st=1;
				root.data[i].hp=std::max(root.data[i].maxhp/10,1);
//					gui_py.setcolor(x,y,"fish");
			}
			else
			{
				root.dead++;
				root.data[i].dead=1;
				root.data[i].st=-root.dead;
			}
		}
	}
	root.revive_ing=0;
}

void sys::work(int round)
{
//	std::cout<<"round "<<round<<'\n';
	std::cerr<<round<<'\n';
	if (round%5==1) random_food();
	game_revive();
	sort(root.data.begin(),root.data.end(),cmp_sp);
	for (int i=0;i<tot;i++)
	{
		int id=root.data[i].id;

		if (!root.data[i].dead && root.data[i].st==1)
		{
			root.data[i].move=1;
			root.data[i].attack=1;

			root.nowpl=root.data[i];
//			std::cerr<<"    "<<root.data[i].name<<'\n';
			sys_data[id-1].ai->play();
			srand(time(0)+rand());
			root.data[i]=root.nowpl;

		}
	}
//	separate();
//	std::cout<<"round "<<round<<" result"<<'\n';
/*	sort(root.data.begin(),root.data.end(),cmp_score_exp_id);
	for (int i=0;i<tot;i++)
	{
		root.nowpl=root.data[i];
		std::cout<<root.data[i].name<<"   id: "<<root.data[i].id<<"   exp: "<<root.getExp()<<'\n';
	}*/
//	separate();
}

void sys::result()
{
	for (int i=0;i<tot;i++)
	{
		root.nowpl=root.data[i];
		root.data[i].exp=root.getExp();
	}
	sort(root.data.begin(),root.data.end(),cmp_score_exp_id);
	std::cout<<"final result"<<'\n';
	for (int i=0;i<tot;i++)
	{
		root.nowpl=root.data[i];
		std::cout<<root.data[i].name;
		std::cout<<"   id: "<<root.data[i].id;
		std::cout<<"   level: "<<root.data[i].level;
		std::cout<<"   exp: "<<root.data[i].exp;
		std::cout<<"   score: "<<root.data[i].score;
		std::cout<<"   hp: "<<std::max(0,root.data[i].hp);
		std::cout<<"   maxhp: "<<root.data[i].maxhp;
		std::cout<<"   str: "<<root.data[i].str;
		std::cout<<"   spe: "<<root.data[i].sp;
		std::cout<<'\n';
	}
}

sys::sys(std::string password)
{
	if (password!="egoist") return;
	sys_data.clear();
	root.data.clear();
	for (int i=0;i<1;i++) add_new_player(new st01(),"st01");
	for (int i=0;i<1;i++) add_new_player(new st02(),"st02");
	for (int i=0;i<1;i++) add_new_player(new st03(),"st03");
	get_random_id();
	game_init();
	root.dead=0;
	for (int i=1;i<=game_round;i++)	work(i);
	result();
}
