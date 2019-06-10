#include <stdio.h>
#include <time.h>
#include <math.h>
int l(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}
int main()
{
	srand(time(NULL));
	char s[]=" .+oO@";
	//printf("%d\n",l(s));
	//getchar();getchar();
	int w=50,i,j;
	int delay[w],pro[w][w],t;
	for(i=0;i<w;i++)
		delay[i]=rand()%(4*w)+w;
	for(i=0;i<w;i++){
	for(j=0;j<w;j++)
		pro[i][j]=0;
	}
	
	for(t=0;t>-1;t++)
	{
		for(j=0;j<w;j++)
		{
			for(i=w-1;i>=0;i--)
			{
				int k;
				for(k=l(s)-1;k>0;k--)
				{
					if(pro[i][j]==k)
					{
						pro[i][j]--;
						if(i+1+sq(1+8*i)/2<w)	pro[i+1+sq(1+8*i)/2][j]=k;
						break;
					}
				}
			}
			if(t%delay[j]==0)	pro[0][j]=l(s)-1;
		}
		system("cls");
		for(i=0;i<w;i++)
		{
			for(j=0;j<w;j++)
				printf("%c",s[pro[i][j]]);
			printf("\n");
		}
	}
	return 0;
}
int sq(int a)
{
	int i;
	for(i=0;i<a;i++)
		if(i*i==a) return i;
}
