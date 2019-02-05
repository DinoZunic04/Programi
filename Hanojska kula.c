#include <stdio.h>
#define MAX 9
static int hanoi[3][8];
static int brojDiskova;
void nacrtaj();
int main() {
	printf("H A N O J S K A   K U L A\n");
	printf("              ~Dino Zunic\n\n");
	getchar();
	printf("<Unesite 1 ako zelite da procitate pravila igre>\n");
	char tutorijal;
	scanf("%c",&tutorijal);
	if(tutorijal=='1')
	{
		printf("\nHanojska kula je zagonetka koja se sastoji iz 3 sipke i nekoliko diskova.\n");
		printf("Diskovi su razlicitih velicina i poredjani su u rastucem redosledu na prvoj sipci (najveci je na dnu, a najmanji na vrhu).\n");
		printf("Cilj igre je da se svi diskovi prenesu sa prve sipke na drugu ili trecu.\n\n");
		getchar();getchar();
		printf("PRAVILA:\n\n");
		printf("\t1. Samo jedan disk moze da se pomera istovremeno.\n");
		printf("\t2. Disk moze da se pomera samo ako na njemu nema drugih diskova (mora biti na vrhu).\n");
		printf("\t3. Veci disk ne moze biti pomeren na manji.\n\n");
		getchar();
	}
	printf("Unesite broj diskova, maksimalan broj je %d:",MAX-1);
	while(1)
	{
		scanf("%d",&brojDiskova);
		if(brojDiskova>1&&brojDiskova<=MAX-1)
			break;
		else if(brojDiskova<1)
			printf("Broj diskova ocigledno mora biti pozitivan, unesite neki normalan broj:");
		else if(brojDiskova==1)
			printf("Zar je toliko tesko pomeriti jedan disk? Unesite malo veci broj diskova:");
		else
			printf("Maksimalan broj diskova je %d, unesite neki manji broj:",MAX-1);
	}
	printf("\n\n");
	int i,j;
	for(i=brojDiskova;i>0;i--)
	{
		hanoi[0][brojDiskova-i]=i;
	}
	int counter=0;
	char p,r;
	while(1)
	{
		nacrtaj();
		printf("Unesite sipku sa koje pomerate disk:");
		while(1)
		{
			scanf("%c",&p);
			p=toupper(p);
			if(p=='\n')
				continue;
			else if(p=='A'||p=='B'||p=='C')
				break;
			else
				printf("Unesite ili A ili B ili C:");
		}
		printf("Unesite sipku na koju stavljate disk sa sipke %c:",p);
		while(1)
		{
			scanf("%c",&r);
			r=toupper(r);
			if(r=='\n')
				continue;
			else if(r=='A'||r=='B'||r=='C')
				break;
			else
				printf("Unesite ili A ili B ili C:");
		}
		int a,b,c=-1,d=-1,temp;
		switch(p)
		{
			case 'A':
				a=0;
			break;
			case 'B':
				a=1;
			break;
			case 'C':
				a=2;
			break;
		}
		switch(r)
		{
			case 'A':
				b=0;
			break;
			case 'B':
				b=1;
			break;
			case 'C':
				b=2;
			break;
		}
		for(i=brojDiskova-1;i>=0;i--)
		{
			if(hanoi[a][i]!=0)
			{
				c=i;
				break;
			}
		}
		for(i=brojDiskova-1;i>=0;i--)
		{
			if(hanoi[b][i]!=0)
			{
				d=i;
				break;
			}
		}
		if(c==-1)
		{
			printf("Sipka %c nema diskova.\n",p);
			continue;
		}
		if(p==r)
			continue;
		if(hanoi[a][c]>hanoi[b][d]&&hanoi[b][d]!=0)
		{
			printf("Ne mozete staviti veci disk na manji.\n");
			continue;
		}
		hanoi[b][d+1]=hanoi[a][c];
		hanoi[a][c]=0;
		counter++;
		if(hanoi[1][brojDiskova-1]==1||hanoi[2][brojDiskova-1]==1)
		{
			nacrtaj();
			printf("Cestitam, pobedili ste!\nBroj poteza:%4d.\n",counter);
			int minPoteza=1;
			for(i=0;i<brojDiskova;i++)
				minPoteza*=2;
			minPoteza--;
			if(counter==minPoteza)
				printf("Resili ste ovu zagonetku na najefikasniji nacin!\n");
			else
				printf("Najefikasniji nacin:%4d poteza\n",minPoteza);
			break;
		}
	}
	scanf("%d",&i);
	return 0;
}
void nacrtaj()
{
	int i,j,k;
	for(i=0;i<6*brojDiskova+9;i++)
	{
		putchar('-');
	}
	printf("\n");
	for(i=0;i<6*brojDiskova+9;i++)
		{
			if(i==1+brojDiskova)
			putchar('A');
			else if(i==1+brojDiskova+1+brojDiskova+2+brojDiskova)
			putchar('B');
			else if(i==1+brojDiskova+1+brojDiskova+2+brojDiskova+1+brojDiskova+2+brojDiskova)
			putchar('C');
			else
				putchar(' ');
		}
	printf("\n\n");
	for(i=0;i<brojDiskova;i++)
	{
		for(j=0;j<6*brojDiskova+9;j++)
		{
			if(j==1+brojDiskova||j==1+brojDiskova+1+brojDiskova+2+brojDiskova||j==1+brojDiskova+1+brojDiskova+2+brojDiskova+1+brojDiskova+2+brojDiskova)
				putchar('|');
			else
				putchar(' ');
		}
		printf("\n");
		for(j=0;j<6*brojDiskova+9;j++)
		{
			if(j==1+brojDiskova||j==3*brojDiskova+4||j==5*brojDiskova+7)
			{
				if(hanoi[j/(2*brojDiskova+3)][brojDiskova-i-1]>0)
					printf("%d",hanoi[j/(2*brojDiskova+3)][brojDiskova-i-1]);
				else
					putchar('|');
			}	
			else if(j>0&&j<2*brojDiskova+2)
			{
				k=abs(j-brojDiskova-1);
				if(k<=hanoi[j/(2*brojDiskova+3)][brojDiskova-i-1])
					putchar('*');
				else
					putchar(' ');	
			}	
			else if(j>2*brojDiskova+3&&j<4*brojDiskova+5)
			{
				k=abs(j-3*brojDiskova-4);
				if(k<=hanoi[j/(2*brojDiskova+3)][brojDiskova-i-1])
					putchar('*');
				else
					putchar(' ');	
			}	
			else if(j>4*brojDiskova+6&&j<6*brojDiskova+8)
			{
				k=abs(j-5*brojDiskova-7);
				if(k<=hanoi[j/(2*brojDiskova+3)][brojDiskova-i-1])
					putchar('*');
				else
					putchar(' ');	
			}
			else
				putchar(' ');
		}
		printf("\n");
	}
	printf("\n\n");
	for(i=0;i<6*brojDiskova+9;i++)
	{
		putchar('-');
	}
	printf("\n\n");
}
