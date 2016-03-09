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

#include "fish.h"

bool fish::move(int x,int y){return root.move(x,y);}
bool fish::attack(int x,int y){return root.attack(x,y);}
int fish::getPoint(){return root.getPoint();}
int fish::getLevel(){return root.getLevel();}
int fish::getExp(){return root.getExp();}
int fish::getX(){return root.getX();}
int fish::getY(){return root.getY();}
int fish::getHP(){return root.getHP();}
int fish::getMaxHP(){return root.getMaxHP();}
int fish::getAtt(){return root.getAtt();}
int fish::getSp(){return root.getSp();}
int fish::getID(){return root.getID();}
int fish::askWhat(int x,int y){return root.askWhat(x,y);}
int fish::askHP(int id){return root.askHP(id);}
bool fish::increaseHealth(){return root.increaseHealth();}
bool fish::increaseStrength(){return root.increaseStrength();}
bool fish::increaseSpeed(){return root.increaseSpeed();}
int fish::getTotalPlayer(){return root.getTotalPlayer();}
