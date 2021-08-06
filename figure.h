#include <graphics.h>

class figure
{
public:
	double x, y,robs;
public:	
	figure(double x0, double y0);
	figure();
    ~figure();
    void rotation(double theta, double x0, double y0);
    void drawobs();//draw obstacle
    void deplacement(double x0,double y0);
};


