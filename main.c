#include <stdio.h>
#include <math.h>
#include <time.h>
#define PI 3.14

int main(){
	srand(time(NULL));
	int n=20,i,w=50;
	double a[100],b[100],c[100];
	for(i=0;i<100;i++)
	{
		a[i]=(double)(rand()%1000)/1000;
		b[i]=(double)(rand()%1000)/1000;
		c[i]=(double)(rand()%1000)/1000;
		//printf("%8.4lf %8.4lf %8.4lf\n",a[i],b[i],c[i]);
	}
	for(n=1;n>0;n++)
	{
	printf("============================%6d      ============\n",n);
	
	double t,x;
	for(x=0;x<600/PI;x+=0.5/PI)
	{
		t=0;
		for(i=0;i<n;i++)	t+=a[i]*(sin(b[i]*x+c[i])+1);
		t*=w/(double)n/2;
		
		for(i=0;i<=w;i++)
		{
			if(i<(int)t)		printf("+");
			else if(i==(int)t)	printf("|");
			else				printf(" ");
		}
		printf("\n");
		for(i=0;i<999999;i++);	
	}
	}	
	return 0;
}
