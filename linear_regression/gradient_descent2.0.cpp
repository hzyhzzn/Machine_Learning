#include <iostream>
#include <math.h>
using namespace std;

double abs(double a){
	return a>0?a:-a;
}


int main()
{
	double X[15];
	double Y[15] = {2.000,2.500,2.900,3.147,4.515,4.903,5.365,5.704,6.853,7.971,8.561,10.000,11.280,12.900,0}; 
	for (int i = 0; i < 15; ++i)
	{
		X[i] = i;
	}

	double alpha = 0.001;
	double theta[2] = {0,0};
	int step=1;
	int ms=1000;

	while(ms--)
	{	
		double diff[2] = {0,0};
		
		for (int k = 0; k < 14; ++k)
		{
			diff[0] += (theta[0] + theta[1] * X[k])-Y[k];
			diff[1] += ((theta[0] + theta[1] * X[k])-Y[k])*X[k];				
		}		
		for(int k = 0;k < 2; ++k) 
		{ 
			theta[k] = theta[k]-alpha*(diff[k]); 
		} 
		
		double error1 = 0;
		for (int k = 0; k < 14; ++k)
		{
			error1 += ( Y[k]-( theta[0] + theta[1] * X[k]  ) )*( Y[k]-( theta[0] + theta[1] * X[k]  ) )/2;				
		}    
		printf("step %d :   loss:%lf\n",step++,error1);
  	
	}
		
	Y[14]=theta[0]+theta[1]*14;
	cout<<Y[14]<<endl;		
	return 0;
}
