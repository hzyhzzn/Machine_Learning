#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	ifstream filex("ex4x.dat");
	ifstream filey("ex4y.dat");

	double xf;
	vector<double>X;
	while (filex)
	{
		filex>>xf;
		X.push_back(xf);
	}

	double yf;
	vector<double>Y;
	while (filey)
	{
		filey>>yf;
		Y.push_back(yf);
	}

	double max=X[0];
	double min=X[0];
	for(int i = 0;i < Y.size(); i++) 
	{ 
		int id=2*i;
		if(X[id]>max)
			max=X[id];
		if(X[id]<min)
			min=X[id];
	}
	for(int i = 0;i < Y.size(); i++) 
	{ 
		int id=2*i;
		X[id]=(X[id]-min)/(max-min);
	}

	max=X[1];
	min=X[1];
	for(int i = 0;i < Y.size(); i++) 
	{ 
		int id=2*i+1;
		if(X[id]>max)
			max=X[id];
		if(X[id]<min)
			min=X[id];
	}
	for(int i = 0;i < Y.size(); i++) 
	{ 
		int id=2*i+1;
		X[id]=(X[id]-min)/(max-min);
	}

	double theta[3] = {0,0,0};
	double e = 2.71828182;
	double alpha = 0.1;
	int step=1;
	int ms=5000;

	while(ms--)
	{	

		double diff[3] = {0,0,0};	
		for (int k = 0; k < Y.size(); ++k)
		{


			double h=1/(1.0+pow(e,-1*(theta[0]+theta[1]*X[2*k]+theta[2]*X[2*k+1])));

			diff[0] += (Y[k]-h); 
			diff[1] += (Y[k]-h)*X[2*k];
			diff[2] += (Y[k]-h)*X[2*k+1];


		}		
		for(int i = 0;i < 3; ++i) 
		{ 
			theta[i] = theta[i]+alpha*(diff[i]); 
		}

		double loss = 0;
		for (int k = 0; k < Y.size(); ++k)
		{
			double pred=pow(e,theta[0]+theta[1]*X[2*k]+theta[2]*X[2*k+1]);
			loss += Y[k]==1 ? pred/(pred+1) : 1/(pred+1);	
		}    
		printf("step %d :   loss:%lf\n",step++,loss);
	}
	printf("%lf %lf %lf\n",theta[0],theta[1],theta[2]);

	return 0;
}
