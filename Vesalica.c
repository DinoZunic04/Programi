#include <stdio.h>

void nacrtaj(int n)
{
    switch(n)
    {
        case 0:
            break;
        case 1:
        _          _  	      __
|  |        |  |	     |  |
|           |  O	     |  O
|           |  |\ 	     | /|\
|           |  |	     |  |
|           |		     | / \
|           | 		     |
|           |    	     |

    }
}
int areEq(char s1[], char s2[])
{
    int i,len1,len2;
    for(i=0;s1[i]!='\0';i++)    len1++;
    for(i=0;s2[i]!='\0';i++)    len2++;
    if(len1!=len2)
        return 0;
    for(i=0;i<len1;i++)
    {
        if(s1[i]!=s2[i])
            return 0;
    }
    return 1;
}
int main()
{
    char rec[100],s,pokusaj[100],izlaz[100],c;
    int i=0,counter = 0, potez=1,poeni = 0,j=0,chk = 0;
    printf("Unesite rec (rec ce biti automatski izbrisana sa ekrana):");
    while((c=getchar())!='\n'&&c!=' ')
    {
        rec[i]=c;
        i++;
    }
    counter=i;
    for(i=0;i<counter;++i)
    {
        izlaz[i]='_';
        printf("%c ",izlaz[i]);
    }
    while(!areEq(izlaz,rec)&&potez<=5*counter&&poeni<7)
    {
        printf("Unesite slovo: ");
        s=getchar();
        for(j=0;j<counter;++j)
		   {
		   	  if(rec[j] == s)
		   	   ++chk;
		   }
		 if(!chk)
		   	++poeni;
        for(i=0;i<counter;++i)
        {
		   if(chk)
		   {
		   	 if(rec[i] == s)
		   	  izlaz[i] = s;
		   }

		  printf("%c ",izlaz[i]);
		}
        printf("\n");
        printf("Pogadjajte rec: ");
        scanf("%s",&pokusaj);
        if(areEq(rec,pokusaj))
        {
            printf("Pogodili ste rec u %d pokusaj(a)!", potez);
            break;
        }
        else
            printf("Nije.\n");
        potez++;
        getchar();
    }
    return 0;
}
