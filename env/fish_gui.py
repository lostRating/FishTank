from random import randrange
from graphics import *
from button import Button
from dieview import DieView

#############################################

def setcolor(x,y,what):
    i=(x-1)*40+y-1
    if (what==''):
        s[i].rect.setFill('white')
    if (what=='fish'):
        s[i].rect.setFill('blue')
    if (what=='food'):
        s[i].rect.setFill('green')

#############################################

def init():
    win = GraphWin("Fish",1200,800)
    win.setCoords(0, 0, 60, 40)
    win.setBackground("lightblue")
    i=0
    j=40
    while 1:
        j=j-1
        if (j==-1):
            j=39
            i=i+1
            if (i==40):
                break
        tmp=Button(win,Point(i+0.6,j+0.4),1,1,'','white')
        s.append(tmp)

#############################################

s=[]
init()
