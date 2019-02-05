#include <stdio.h>
#include <stdlib.h>
static int tabela[4][4],poeni,brojPoteza;
int stepen(int),poraz(),jesuJednake(int temp[4][4]);
void nacrtaj(),promeni(char);
int main()
{
    int i,j;
    int pobeda=0;
    char potez;
    time_t t;
    srand((unsigned) time(&t));
    printf("2 0 4 8\n~Tutkamon inc.\n\n");
    getchar();
pocetak:
    for(i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            tabela[i][j]=0;
        }
    }
    int x,y,p;
    x=rand()%4;
    y=rand()%4;
    p=rand()%100+1;
    if(p<91)
        tabela[x][y]=1;
    else
        tabela[x][y]=2;
drugiBroj:
    x=rand()%4;
    y=rand()%4;
    if(tabela[x][y]==0)
    {
        p=rand()%100+1;
        if(p<91)
            tabela[x][y]=1;
        else
            tabela[x][y]=2;
    }
    else
        goto drugiBroj;
    brojPoteza=0;poeni=0;
    while(1)
    {
        nacrtaj();
        while(1)
        {
            printf("Unesite potez: ");
            potez=getchar();
            getchar();
            potez=tolower(potez);
            if(potez=='w'||potez=='a'||potez=='s'||potez=='d')
                break;
            else
                printf("Unesite W, A, S ili D.\n");
        }
        promeni(potez);
        pobeda=0;
        for(i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if(tabela[i][j]==11)
                {
                    pobeda++;
                }
            }
        }
        if(pobeda)
        {
            nacrtaj();
            printf("Cestitam, pobedili ste!\n\nBroj poteza: %8d\nPoeni:       %8d\n\n",brojPoteza,poeni);
            break;
        }
        else if(poraz())
        {
            nacrtaj();
            printf("Izgubili ste...\n\nBroj poteza: %8d\nPoeni:       %8d\n\n",brojPoteza,poeni);
            break;
        }
    }
    printf("Da li biste zeleli da igrate ponovo? (Y/N)\n");
    char izbor=getchar();
    getchar();
    izbor=tolower(izbor);
    if(izbor=='y')
        goto pocetak;
    return 0;
}

void nacrtaj()
{
    printf("potez: %-10dpoeni: %-10d\n\n\n",brojPoteza+1,poeni);
    int i,j;
    printf("_____________________\n");
    for(i=0;i<4;i++)
    {
        printf("|    |    |    |    |\n|");
        for (j=0;j<4;j++) {
            if(tabela[i][j]==0)
                printf("____|");
            else
            {
                if(tabela[i][j]<4)
                    printf("_%d__|",stepen(tabela[i][j]));
                else if(tabela[i][j]<7)
                    printf("_%d_|",stepen(tabela[i][j]));
                else if(tabela[i][j]<10)
                    printf("%d_|",stepen(tabela[i][j]));
                else
                    printf("%d|",stepen(tabela[i][j]));
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int stepen(int a)
{
    int i,toReturn=1;
    for (i=0;i<a;i++) {
        toReturn*=2;
    }
    return toReturn;
}

void promeni(char c)
{
    brojPoteza++;
    int i,j,k,chk=0,jelPomereno=1;
    switch(c)
    {
        case 'a':
            for(i=0;i<4;i++)
            {
                for(j=1;j<4;j++)
                {
                    if(tabela[i][j]!=0)
                    {
                        for(k=j;k>0&&tabela[i][k-1]==0;k--)
                        {
                            jelPomereno=0;
                            tabela[i][k-1]=tabela[i][k];
                            tabela[i][k]=0;
                        }
                        if(tabela[i][k-1]==tabela[i][k]&&!chk)
                        {
                            jelPomereno=0;
                            chk=1;
                            tabela[i][k-1]++;
                            poeni+=stepen(tabela[i][k-1]);
                            tabela[i][k]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
        case 'd':
            for(i=0;i<4;i++)
            {
                for(j=2;j>=0;j--)
                {
                    if(tabela[i][j]!=0)
                    {
                        for(k=j;k<3&&tabela[i][k+1]==0;k++)
                        {
                            jelPomereno=0;
                            tabela[i][k+1]=tabela[i][k];
                            tabela[i][k]=0;
                        }
                        if(tabela[i][k+1]==tabela[i][k]&&!chk)
                        {
                            jelPomereno=0;
                            chk=1;
                            tabela[i][k+1]++;
                            poeni+=stepen(tabela[i][k+1]);
                            tabela[i][k]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
        case 'w':
            for(i=0;i<4;i++)
            {
                for(j=1;j<4;j++)
                {
                    if(tabela[j][i]!=0)
                    {
                        for(k=j;k>0&&tabela[k-1][i]==0;k--)
                        {
                            jelPomereno=0;
                            tabela[k-1][i]=tabela[k][i];
                            tabela[k][i]=0;
                        }
                        if(tabela[k-1][i]==tabela[k][i]&&!chk)
                        {
                            jelPomereno=0;
                            chk=1;
                            tabela[k-1][i]++;
                            poeni+=stepen(tabela[k-1][i]);
                            tabela[k][i]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
        case 's':
            for(i=0;i<4;i++)
            {
                for(j=2;j>=0;j--)
                {
                    if(tabela[j][i]!=0)
                    {
                        for(k=j;k<3&&tabela[k+1][i]==0;k++)
                        {
                            jelPomereno=0;
                            tabela[k+1][i]=tabela[k][i];
                            tabela[k][i]=0;
                        }
                        if(tabela[k+1][i]==tabela[k][i]&&!chk)
                        {
                            jelPomereno=0;
                            chk=1;
                            tabela[k+1][i]++;
                            poeni+=stepen(tabela[k+1][i]);
                            tabela[k][i]=0;
                        }
                        else
                            chk=0;
                    }
                }
                chk=0;
            }
        break;
    }
    time_t t;
    srand((unsigned) time(&t));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(tabela[i][j]==0)
                chk++;
        }
    }
    if(jelPomereno)
        brojPoteza--;
    if(!chk||jelPomereno)
        return;
    while(1)
    {
        int x,y,p;
        x=rand()%4;
        y=rand()%4;
        if(tabela[x][y]==0)
        {
            p=rand()%100+1;
            if(p<91)
                tabela[x][y]=1;
            else
                tabela[x][y]=2;
            break;
        }
    }
}

int poraz()
{
    int temp[4][4],tempBrojPoteza,tempPoeni,chk;
    tempBrojPoteza=brojPoteza;
    tempPoeni=poeni;
    memcpy(temp, tabela, sizeof(temp));
    promeni('a');
    if(!jesuJednake(temp))
    {
        memcpy(tabela, temp, sizeof(tabela));
        brojPoteza=tempBrojPoteza;
        poeni=tempPoeni;
        return 0;
    }
    promeni('w');
    if(!jesuJednake(temp))
    {
        memcpy(tabela, temp, sizeof(tabela));
        brojPoteza=tempBrojPoteza;
        poeni=tempPoeni;
        return 0;
    }
    promeni('s');
    if(!jesuJednake(temp))
    {
        memcpy(tabela, temp, sizeof(tabela));
        brojPoteza=tempBrojPoteza;
        poeni=tempPoeni;
        return 0;
    }
    promeni('d');
    if(!jesuJednake(temp))
    {
        memcpy(tabela, temp, sizeof(tabela));
        brojPoteza=tempBrojPoteza;
        poeni=tempPoeni;
        return 0;
    }
    brojPoteza=tempBrojPoteza;
    poeni=tempPoeni;
    return 1;
}

int jesuJednake(int t[4][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(tabela[i][j]!=t[i][j])
                return 0;
        }
    }
    return 1;
}
