#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double X[15];
	double Y[15]={2.000,2.500,2.900,3.147,4.515,4.903,5.365,5.704,6.853,7.971,8.561,10.000,11.280,12.900,0}; 
	for (int i = 0; i < 15; ++i)
	{
		X[i]=i;
	}

	double diff=0;
	double diff1=0;
	double alpha=0.01;
	double theta[2]={0,0};
	double epsilon = 0.0001;
	double error0=0;
	double temp = 0;
	
	while(true)
	{		
		for (int k = 13; k >= 0; --k)
		{
			diff =(theta[0] + theta[1] * X[k])-Y[k];
			theta[0]=theta[0]-alpha*diff;
			theta[1]=theta[1]-alpha*diff*X[k];			
		}
	
	cout<<diff<<endl;
	cout<<theta[0]<<" "<<theta[1]<<endl;
	
	double error1 = 0;
	for (int k = 0; k < 14; ++k)
	{
		error1 += ( Y[k]-( theta[0] + theta[1] * X[k]  ) )*( Y[k]-( theta[0] + theta[1] * X[k]  ) )/2;
			
	}    
    if (abs(error1-error0) < epsilon)
    {
    	temp=error1;
    	break;
	}
        
    else
        error0 = error1;
	}
	
	cout<<temp<<endl;
	Y[14]=theta[0]+theta[1]*X[14];
	cout<<Y[14]<<endl;
	return 0;
}
