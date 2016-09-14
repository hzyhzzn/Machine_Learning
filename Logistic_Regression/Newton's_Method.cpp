#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
	ifstream filex("ex4x.dat");
	ifstream filey("ex4y.dat");
	
	double theta[3] = {0,0,0};
	double e = 2.71828182;

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

    double alpha = 0.001;
	
	int step=1;
	int ms=10000;

	while(ms--)
	{	
		double J[3] = {0,0,0};
		double H[3] = {0,0,0};
		for (int k = 0; k < Y.size()-1; ++k)
		{
			double h=1/(1+pow(e,-1*(theta[0]+theta[1]*X[2*k]+theta[2]*X[2*k+1])));
			J[0] += (h - Y[k]); 
			J[1] += (h - Y[k])*X[2*k];
			J[2] += (h - Y[k])*X[2*k+1];

			H[0] += h * (1 - h);
			H[1] += h * (1 - h)*(X[2*k]*X[2*k] + X[2*k+1]*X[2*k+1]);
			H[2] += h * (1 - h)*(X[2*k]*X[2*k] + X[2*k+1]*X[2*k+1]);		
	
		}		
		for(int k = 0;k < 3; ++k) 
		{ 
			theta[k] = theta[k] - J[k]/H[k]; 
		} 
		
	}
	cout<<theta[0]<<" "<<theta[1]<<" "<<theta[2]<<endl;
	return 0;
}
