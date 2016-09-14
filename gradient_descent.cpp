#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double X[15];
	double Y[15] = {2.000,2.500,2.900,3.147,4.515,4.903,5.365,5.704,6.853,7.971,8.561,10.000,11.280,12.900,0}; 
	for (int i = 0; i < 15; ++i)
	{
		X[i] = i;
	}


	double alpha = 0.0015;
	double theta[2] = {0,0};
	double epsilon = 0.0001;
	double error0 = 0;
	
	
	while(true)
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
		
		cout<<diff[0]<<" "<<diff[1]<<endl;
		cout<<theta[0]<<" "<<theta[1]<<endl;
		
		//退出迭代条件 
		double error1 = 0;
		for (int k = 0; k < 14; ++k)
		{
			error1 += ( Y[k]-( theta[0] + theta[1] * X[k]  ) )*( Y[k]-( theta[0] + theta[1] * X[k]  ) )/2;				
		}    
  		if (abs(error1-error0) < epsilon)
  		{
  			cout<<error1<<endl;
  			break;
		}    	
    	else
        	error0 = error1;
	}
		
	Y[14]=theta[0]+theta[1]*14;
	cout<<Y[14]<<endl;		//2014房价 
	return 0;
}
