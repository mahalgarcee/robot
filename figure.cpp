#include "figure.h"
#include <graphics.h>
#include <iostream>
#include<math.h>
#include<conio.h>
using namespace std;
figure::~figure() {};
figure::figure(){};
figure::figure(double x0, double y0){
	x=x0;
	y=y0;
};

void figure::deplacement(double x0,double y0)
{
		x+=x0;
		y+=y0;
		
};
	
	void figure::rotation(double theta,double x0,double y0)
{    
	    deplacement(-x0,-y0);	
		double x1=x;
		double y1=y;
		x=((x1*cos(theta))-(y1*sin(theta)));
		y=((x1*sin(theta))+(y1*cos(theta)));
		deplacement(x0,y0);
		cout<<x;
		cout<<" ";
		cout<<y<<endl;
};
void figure::drawobs(){
	setcolor(4);// couleur rouge
	 figure cercle((int)x,(int)y);
	 circle(cercle.x,cercle.y,robs);/// dessin cercle  de centre x,y
};


