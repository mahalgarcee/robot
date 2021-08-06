#include <graphics.h>
//#include "figure.h"
class dessin : public figure
{
public:
	double r;
	static const double D=0.05;
    static const double R0=0.02;
    static const double t=0.1;
    static const double W0MAX=10;
    double alp;
    double wd,wg;
    double dr;
    double dalpha;
    static const double TWOPI = 6.2831853071795865;
    static const double RAD2DEG = 57.2957795130823209;
public:
    dessin(){
    x=0;y=0;r=50;
    wg=5,wd=5;
    alp=0;
	}
    ~dessin();
    dessin(double x0,double y0) {
    x=x0;
    y=y0;
     r=25;// rayon de robot dessiné
     wg=5,wd=5;
     alp=0;
	}
    void draw(double x,double y);
    void deplacement();
    void deplacement(double x0,double y0);
    //ecrire position du robot
    void ecriture(double instant,double x,double y,double wg,double wd);
    ///deplacement auto
    void automatique(double x,double y,figure robot);
};

