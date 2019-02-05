#include <stdio.h>

int main() {
	int i,j,stepen;
	int paskalovTrougao[100][102];
	paskalovTrougao[0][0]=0;paskalovTrougao[0][1]=1;paskalovTrougao[0][2]=0;
	for(i=1;i<100;i++)
	{
		paskalovTrougao[i][0]=0;paskalovTrougao[i][i+2]=0;
		for(j=1;j<i+2;j++)
		{
			paskalovTrougao[i][j]=paskalovTrougao[i-1][j-1]+paskalovTrougao[i-1][j];
		}
	}

	printf("Unesite stepen binoma(od 1 do 100):");
	scanf("%d",&stepen);

	printf("(a+b)^%d=\n",stepen);

	for(j=0;j<stepen+1;j++)
	{
		if(j==0)
			printf("a^%d",stepen);
		else if(j==stepen)
			printf("b^%d",stepen);
		else if(j==1)
			printf("%d * a^%d * b",paskalovTrougao[stepen][2],stepen-1);
		else if(j==stepen-1)
			printf("%d * a * b^%d",paskalovTrougao[stepen][2],stepen-1);
		else
			printf("%d * a^%d * b^%d",paskalovTrougao[stepen][j+1],stepen-j,j);
		if(j<stepen)
			printf("  +  ");
	}
	scanf("%d",&i);
	return 0;
}
