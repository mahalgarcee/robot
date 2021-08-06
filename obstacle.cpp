#include "obstacle.h"
#include <string>
#include <iostream>
#include <graphics.h>
#include <fstream>
#include <cstdlib>
#include<math.h>
#include <sstream> 
using namespace std; 
obstacle::obstacle()
{
	Xobs =Yobs=Robs=0;
}
obstacle::~obstacle()
{
	
}
void obstacle::lecture()
{
		obstacle obs;
		ifstream fichier("./obstacle.obs");
	if(fichier)
{
	int cpt=0;
	  string ligne; //Une variable pour stocker les lignes lues

    	while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
         {
        cpt=cpt+1;
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
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    ok3 >> r;
    setcolor(RED);
    obs.Xobs=Xobs;
    obs.Yobs=Yobs;
    obs.Robs=r;
    drawObs(obs);
	cout<<"okt";
	cout<<cpt<<endl;
	outtextxy(Xobs, Yobs,"obs");


}
         
    	
}

else cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;

}
void obstacle:: drawObs(obstacle c)
{
	double x=c.Xobs;
	double y=c.Yobs;
	double r=c.Robs;
	circle(x,y,r);
	
}

