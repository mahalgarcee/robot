#include <graphics.h>
#include "figure.h"
#include "dessin.h"
#include "obstacle.h"
#include <iostream>
#include<math.h>
#include<conio.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
static const double TWOPI = 6.2831853071795865;
static const double RAD2DEG = 57.2957795130823209;

int main() {
	initwindow(2000,1000,"Test"); /// dessiner la fenetre
	obstacle a;
	double instant=0;
	
               
      
   double x=500;/// abscisse du robot initial
   double y=300;/// ordonnée du robot initial

   
	 dessin robot(x,y);
	 
	 
	 
	 
	 
	 double Xgoal=600;/// abscisse du but
	 double Ygoal=100;/// ordonnée du but
	 double Rgoal=40;/// rayon du but
	 
	 
	 
	 
	 
	int i;
	int c=getch();
	bool test= false ;///test si le robot a touché le but
	bool collision=false;/// TEST DE COLLISION
	int o,e;  
	int mode;//manuelle=0, automatique=1
//	const char *img = "Manuel.bmp";
//	readimagefile(img,10,11,10,10);
//    getch();

		 while (1)
    {

    setbkcolor(15);
    setfillstyle(SOLID_FILL,0);
    floodfill(1,1,15);

////////////////////bouton manuel

    setbkcolor(0);
    setcolor(15);
    settextstyle(10, 0, 7);
    outtextxy(100,85,"MANUAL MODE");
    
    setfillstyle(LINE_FILL,0);
    floodfill(1,1,15);
/////////////////////bouton auto

  
   
    
    								
    setcolor(RED);
    settextstyle(2, 0,7);
    outtextxy(800,700,"Mini projet : réalisé par El garce  maha et Sedki Youssef ");
    outtextxy(800,750,"A l'attention de M.Benhlima Said ");
   
        delay(500);

    getmouseclick(WM_LBUTTONDOWN, o, e);

    cout << "The mouse was clicked at: ";

    cout << "x=" << o;

    cout << " y=" << e << endl;

    

    // Switch back to text mode:
if(100<o&&o<593&&285<e&&e<353){
	mode=1;
break;	
}
if(100<o&&o<668&&85<e&&e<153){
	mode=0;
break;	
}
    }
     
     
setbkcolor(0);
	
if(mode==0)	{
while(c!=27 )
    {
    	settextstyle(2, 0, 5);
    		
    /*	if(abs(abs(robot.wd)-abs(robot.wg))>robot.W0MAX){///EVITER DE TOURNER DANS LE VIDE
	if(robot.wd<robot.wg){
		robot.wg-=robot.wg/3;
		robot.wd-=robot.wd/3;
	}
	if(robot.wd>robot.wg){
		robot.wg-=robot.wg/3;
		robot.wd-=robot.wd/3;
	}
   
	}*/
    		if(GetKeyState(VK_UP) & 0x8000){
    			 	robot.wd+=0.8;
				   	robot.wg+=0.8;
    		         if(abs( abs(robot.wd) -abs(robot.wg)) >= robot.W0MAX){///pour ne pas depasser la vitesse max
					  robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX;       } 
    		}
    			
			 
    		 
    	if(GetKeyState(VK_RIGHT) & 0x8000){////key should be kept pressed
    				robot.wd+=0.8;
    		         if(abs( abs(robot.wd) -abs(robot.wg))>= robot.W0MAX){
					  robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX;       } 
    	 	}
    	if(GetKeyState(VK_LEFT) & 0x8000){
    		robot.wg+=0.8;
    		         if( abs( abs(robot.wd) -abs(robot.wg))>= robot.W0MAX) {
					 robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX; 
					 }       
					}
					
					
    	if(GetKeyState(VK_DOWN) & 0x8000){
    		        	robot.wd-=0.8;
				   	robot.wg-=0.8;
    		         if( abs( abs(robot.wd) -abs(robot.wg))>= robot.W0MAX) {
					 robot.wd = robot.W0MAX; 
    		          robot.wg = robot.W0MAX; 
					 }       
					}
    
        cleardevice();

    	cout <<robot.wg<<endl;
    	cout <<robot.wd<<endl;
    //	cout <<i<<endl;

    	robot.draw(robot.x,robot.y);
    	a.lecture();/// lire les obstacles
    	
    //dessin but
    	setcolor(2);
	 	circle(Xgoal,Ygoal,Rgoal);
	 	outtextxy(Xgoal, Ygoal,"But ");
	// test de collision
	 	obstacle b;
    //	collision=b.collision(robot.x,robot.y,robot.r);
    
    	
		obstacle obs;
		ifstream fichier("./obstacle.obs");
	if(fichier)
	{
		int cpt=0;
	  string ligne; //Une variable pour stocker les lignes lues

    	while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
         {
         int esp1=ligne.find(' ',0);
         string x="";
         for(int i=0;i<esp1;i++)
         {
         	x=x+ligne.at(i);
		 }
		 // object from the class stringstream 
    stringstream ok1(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int Xobs = 0; 
    ok1 >> Xobs;
	 int esp2=ligne.find(' ',esp1+1); 
     x="";
         for(int i=esp1+1;i<esp2;i++)
         {
         	x=x+ligne.at(i);
		 }
	stringstream ok2(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int Yobs = 0; 
    ok2 >> Yobs;
    int r=0;
    x="";
    for(int i=esp2+1;i<ligne.length();i++)
         {
         	x=x+ligne.at(i);
		 }
		stringstream ok3(x); 
    ok3 >> r;
    setcolor(RED);
    obs.Xobs=Xobs;
    obs.Yobs=Yobs;
    obs.Robs=r;
    
    double distance=sqrt(pow(robot.x-Xobs,2)+pow(robot.y-Yobs,2));
    if(distance<abs(r+robot.robs)){/// test de collision
	collision =true;
	break;
	}
	else {
		collision= false;
		cout<<"passssssssssssss de collision";
		cout<<cpt<<endl;
	}
	}}
   		if(collision==true)
   		{
   		 cout<<"collisiookkkkkkkkkkkkkkkn"<<endl;
   		 break;
		}
		robot.ecriture(instant, robot.x,robot.y,robot.wg,robot.wd);
		delay(10);
		
		instant=instant+10;
		robot.deplacement();
    	
    	
    	
    	
    	////// test gagnant 
    	double dist =sqrt(pow(robot.x-Xgoal,2)+pow(robot.y-Ygoal,2));
		int t=(robot.r+Rgoal);
		if(dist<(abs(t))){
		test=true;
			}
		//Generer les buts
		if(test==true)
		{
			Xgoal=100 + (int) (((double) rand() / (double) RAND_MAX) * (800-100));
			Ygoal=100 + (int) (((double) rand() / (double) RAND_MAX) * (800-100));/// generer un nouveau but entre 100 et 800
			test=false;
		}
    	
	}
		cleardevice();
//win affichage
while(getch()!=27&&(collision==true)){
setcolor(4);
settextstyle(8, 0, 7);
setbkcolor(WHITE);
outtextxy(200,200, "Perdu"); 
}
while(getch()!=27&&(test==true)){
setcolor(2);
settextstyle(8, 0, 7);
setbkcolor(WHITE);
outtextxy(200,200, "Gagné"); 
}
}
/*	if(mode==1)
	{
	
	while(1)
	
	{
		
		cout<<collision<<endl;
		int i=1;
		cout<<"ok";
		cout<<i<<endl;
		 //dessin but
    	setcolor(2);
	 	circle(Xgoal,Ygoal,Rgoal);
	 	outtextxy(Xgoal, Ygoal,"But ");
	 	
	 	a.lecture();/// lire les obstacles
    		obstacle obs;
		ifstream fichier("./obstacle.obs");
	if(fichier)
	{
		int cpt=0;
	  string ligne; //Une variable pour stocker les lignes lues

    	while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
         {
         int esp1=ligne.find(' ',0);
         string x="";
         for(int i=0;i<esp1;i++)
         {
         	x=x+ligne.at(i);
		 }
		 // object from the class stringstream 
    stringstream ok1(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int Xobs = 0; 
    ok1 >> Xobs;
	 int esp2=ligne.find(' ',esp1+1); 
     x="";
         for(int i=esp1+1;i<esp2;i++)
         {
         	x=x+ligne.at(i);
		 }
	stringstream ok2(x); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int Yobs = 0; 
    ok2 >> Yobs;
    int r=0;
    x="";
    for(int i=esp2+1;i<ligne.length();i++)
         {
         	x=x+ligne.at(i);
		 }
		stringstream ok3(x); 
    ok3 >> r;
    setcolor(RED);
    obs.Xobs=Xobs;
    obs.Yobs=Yobs;
    obs.Robs=r;
    
    double distance=sqrt(pow(robot.x-Xobs,2)+pow(robot.y-Yobs,2));
    
   // if(distance==abs(r+robot.robs)){/// test de collision

	collision =colision(&robot,obs);
	cout<<collision<< endl;
	if(collision==false) {
		cout<<"pas de collision";
		cout<<cpt<<endl;
		
	}
	// cout<<"collisionnnnnnnnnnnnnnnn"<< endl;
	}
	
	
	}

   		 //dessin but
    	setcolor(2);
	 	circle(Xgoal,Ygoal,Rgoal);
	 	outtextxy(Xgoal, Ygoal,"But ");
	 	///////////////////
		robot.draw(robot.x,robot.y);
		cout<<"mqahhhhhhhhhhhhhha"<<endl;
	if(collision==false)
	{
		robot.automatique(Xgoal,Ygoal,robot);
	}
		robot.deplacement();
		//////////////////

		////// test gagnant 
    	double dist =sqrt(pow(robot.x-Xgoal,2)+pow(robot.y-Ygoal,2));
		int t=(robot.r+Rgoal);
		if(dist<(abs(t))){
		test=true;
			}
		//Generer les buts
		if(test==true)
		{
			Xgoal=100 + (int) (((double) rand() / (double) RAND_MAX) * (800-100));
			Ygoal=100 + (int) (((double) rand() / (double) RAND_MAX) * (800-100)),
			test=false;
		}
		delay(10);
		cleardevice();
		i++;
	}
/*	while(getch()!=27&&(test==true)){
		cleardevice();
		setcolor(2);
		settextstyle(8, 0, 7);
		setbkcolor(WHITE);
		outtextxy(200,200, "Gagné"); */

	
	


return 0;
}
