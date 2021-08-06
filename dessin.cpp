
#include "figure.h"
#include "dessin.h"
#include <graphics.h>
#include <iostream>
#include <fstream>
#include <string>
#include <limits> 
#include<math.h>
#define PI 3.14159265
using namespace std;

dessin::~dessin(){
};

void dessin::draw(double x,double y){
	setcolor(8);
	 figure cercle(x,y);

	 circle(cercle.x,cercle.y,r);/// dessin cercle du robot
	 setcolor(14);
	//figure ligneD(cercle.x,cercle.y+(r/2));
	///y= c.getX +r/2 x=c.getX
	/* line(ligneD.x-r/3,ligneD.y,ligneD.x+r/3,ligneD.y);
	 figure ligneG(cercle.x,y-(r/2));
	 line(ligneG.x-r/3,ligneG.y,ligneG.x+r/3,ligneG.y);*/
	 
	 /* int arr[] = {cercle.x, cercle.y+r, cercle.x+r, cercle.y,  
                 cercle.x, cercle.y-r, cercle.x, cercle.y+r};
    drawpoly(4, arr); */ //triangle 1er methode
    //	figure ligne(cercle.x,y);
    /*	line(ligne.x,ligne.y,ligne.x+r*cos(alp),ligne.y+ (int)r*sin(alp));
	int xsommet=x + (int)r*cos(alp);
	int ysommet= y+ (int)r*sin(alp);
	
	line(xsommet-r/2,ysommet-r/2,xsommet-r/2,ysommet-r*3/2);*/
	
	
 //dessin des trois cotés du robot       
line(x + (int)r*cos(alp - (M_PI/2)),y+ (int)r*sin(alp - (M_PI/2)), x + (int)r*cos(alp),y+ (int)r*sin(alp));
    
line(x + (int)r*cos(alp), y+ (int)r*sin(alp), x+ (int)r*cos(alp+ (M_PI/2)), y+ (int)r*sin(alp + (M_PI/2)));

line(x + (int)r*cos(alp- (M_PI/2)), y+ (int)r*sin(alp - (M_PI/2)), x+ (int)r*cos(alp+ (M_PI/2)),y+ (int)r*sin(alp+ (M_PI/2))); 
	 
	 
};
void dessin::deplacement(){
	double x0=this->x;
	double y0=this->y;
	double Dd=wd*t*R0;
	double Dg=wg*t*R0;
	dr=(Dd+Dg)/2;
	x+=dr*30;
	double dalp=(Dd-Dg)/D;
	alp+=dalp*3.14/180;/// passer de degres en radian
	rotation(alp,x0,y0);	
};
void dessin::deplacement(double x0,double y0)
{
		x+=x0;
		y+=y0;
		
};

void dessin::ecriture(double instant,double x,double y,double wg,double wd)
{
		ifstream fichier("./position.pts");

	  string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier	
	if(fichier)// si le fichier est lu
	{
	int cpt=0;
	  string ligne; //Une variable pour stocker les lignes lues
   int k=0;
	
	while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
	{
    k++;// compter le nombre de ligne dans el fichier
	}
fichier.close();
  
     int t=0; 
	if(k>1000)t=1;// pour ne pas dépasser 1000 lignes 
	ifstream file("./position.pts");
       string line;
    int Line = 0;
	
        while (getline( file, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            
            if(Line !=t) {	//Si la ligne atteinte est différente de la ligne à supprimer...
               Buffer += line + "\n";//On ajoute le contenu de la ligne dans le contenu à réécrire
			    //cout<<"tets"<<endl;
				}
        }
        
   file.close();
	 ofstream fichier("./position.pts");	
    	fichier<< Buffer; //On écris le texte dedans
        fichier <<"instant= "<<instant<<"ms" <<",x= "<<x << " ,y= " <<y << ",wd= " <<wd << " ,wg =" << wg << endl;
		fichier.close();
 
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
	
}
void dessin::automatique(double x,double y,figure robot)
	{
		/*cout<<"youssseffffffffffffff"<<endl;
		if(abs(abs(wd)-abs(wg))>W0MAX){//////////// eviter tourner dans le vide
	if(wd<wg){
		wg-=wg/2;
		wd-=wd/2;
		}
	if(wd>wg){
		wg-=wg/2;
		wd-=wd/2;
		}
		}
		
		*/
	 
        // if (a1 = b1 and a2 = b2) throw an error 
       	/* double theta =-atan2(x - robot.x, y - robot.y);
        if (theta < 0.0)
            theta += TWOPI;
        alp=RAD2DEG *theta;
        cout <<"alpppppppppppppppppppppppppppppppppppppppppppppppp="<< alp<<endl;
        
        /*
        if(angle ==180)
        {
        	wg+=0.5;
		}
		if(angle>180 && angle <270)
		{
			wg+=0.5;
			cout<<"gauche"<<endl;
			
		}
		else if(angle-90 <270)
			{
				wg -= 0.05*wg;
				wd += 0.05*wd;
				cout<<"droite"<<endl;
			}
		///
	///coordonnées du premier vecteur
/*	double x1p=robot.x;
	double y1p=robot.y;
	
	double x2p=x+r*cos(alp);
	double y2p=y+r*sin(alp);
	
	/// coordonnées du 2eme vecteur
	double x2g=x;
	double y2g=y;
	
//	double angle=atan2((robot.y-y),(robot.x-x))* PI / 180.0;

	/// angle entre les deux vecteur 
	double cosangle=(((x2p*x2g+y2p*y2g)/sqrt((x2p*x2p+y2p*y2p)*(x2g*x2g+y2g*y2g))));
	double u[4]={robot.x,robot.y,robot.x+r*cos(alp),robot.y+r*sin(alp)};
	double v[4]={robot.x,robot.y,x,y};
	
//	double angle=atan2((u[2]-u[0])*(v[3]-v[1])-(u[3]-u[1])*(v[2]-v[0]),(u[2]-u[0])*(v[2]-v[0])-(u[3]-u[1])*(v[3]-v[1]));

//	double angle=acos(cosangle)* PI / 180.0;
//	angle=(angle*3.14)/180;
//	cout <<"angle="<<angle<< endl;

			//		cout<<"--------------->"<<angle<<endl;
			///le cas ou le but est en face  du robot
		/*	if(angle==0)
			{
					wg += 0.09*wg;
					wd += 0.09*wd;
					cout<<"direct"<<endl;
					cout<<"zerooooooooooo"<<endl;
			}
	
				if(angle>90&&angle<180)
			{
					wg -= 0.09*wg;
					wd += 0.09*wd;
					cout<<"droite"<<endl;
			}
			if(angle==0.02)
			{
				wg -= 0.09*wg;
				wd -= 0.09*wd;
				cout<<"derriere"<< endl;
			}
    
		          
				}*/
			
					
		
	}
