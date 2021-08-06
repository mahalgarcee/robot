#include <string>
#include <iostream>
#include <fstream>


class obstacle
{
	public:
	double Xobs ,Yobs,Robs;
	obstacle();
	~obstacle();
	void lecture();
	void drawObs(obstacle c);

};

