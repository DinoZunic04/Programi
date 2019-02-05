#include <stdio.h>
#include <string.h>
static int  tabela[8][8];
static int tabelaB[8][8];
static int tabelaC[8][8];
static int potez,kraljevPrviPotezB,kraljevPrviPotezC,topovPrviPotezB1,topovPrviPotezB2,topovPrviPotezC1,topovPrviPotezC2;
int sah(),remi(),pat(),mat(),rokada();
void nacrtaj(),postaviTabelu(),azuriraj(),procisti(),oznaci(int,int),oznaci_(int,int);
int mozeDaSeIgra(int,int,int,int);
int length(char*);
int main()
{
    /*
       0 - prazno polje

      beli:
       1 - pesak
       2 - konj
       3 - lovac
       4 - top
       5 - kraljica
       6 - kralj

      crni:
      11 - pesak
      12 - konj
      13 - lovac
      14 - top
      15 - kraljica
      16 - kralj

    +=20 - oznaceno polje
    */
    int i,j,p,q,r;

    //NASLOV
    char ime[] = "sah",potpis[] = "~Dino Zunic";
    for(i=0;i<length(ime);i++)
    {
        printf("%c ",toupper(ime[i]));
    }printf("\n");
    for(i=0;i<2*length(ime)-length(potpis)-1;i++)
    {
        printf(" ");
    }printf("%s\n\n",potpis);
    printf("<pritisnite bilo koji taster da pocnete>");
    getchar();

    postaviTabelu();

    int dogovor=0;
    while(!remi()||!pat()||!mat())
    {
        if(dogovor)
        {
            dogovor=0;
            printf("Vas protivnik je ponudio remi, da li prihvatate? (D/N)\n");
            char odgovor[1];
            scanf("%s",odgovor);
            if(length(odgovor)==1&&toupper(odgovor[0])=='D')
            {
                printf("Partija se zavrsila nereseno dogovorom igraca.\n");
                break;
            }
        }
        int x1,x2,y1,y2;
        char p1[2],p2[2];
pocetak:
        nacrtaj();
potez_1:
        printf("Unesite polje figure koju zelite da pomerite:");
        while(1)
        {
            scanf("%s",&p1);
            if(p1[0]=='/'&&p1[1]=='r')
            {
                dogovor=1;
                printf("Remi ce biti ponudjen.\n");
                goto potez_1;
            }
            if(length(p1)!=2||!isalpha(p1[0])||!isdigit(p1[1]))
            {
                printf("Neispravan format, unesite polje ponovo:");
                continue;
            }
            //y1
            switch(tolower(p1[0]))
            {
                case 'a':
                    y1=0;
                break;
                case 'b':
                    y1=1;
                break;
                case 'c':
                    y1=2;
                break;
                case 'd':
                    y1=3;
                break;
                case 'e':
                    y1=4;
                break;
                case 'f':
                    y1=5;
                break;
                case 'g':
                    y1=6;
                break;
                case 'h':
                    y1=7;
                break;
                default:
                    printf("Neispravan format, unesite polje ponovo:");
                    continue;
            }
            //x1
            x1=8-p1[1]+'0';
            if(x1>7||x1<0)
            {
                printf("Neispravan format, unesite polje ponovo:");
                continue;
            }
            if(tabela[x1][y1]==0)
            {
                printf("Izabrali ste prazno polje, izaberite polje sa vasom figurom:");
                continue;
            }
            if(!potez)
            {
                if(tabela[x1][y1]>10&&tabela[x1][y1]<17)
                {
                    printf("Izabrali ste protivnikovu figuru, izaberite polje sa vasom figurom:");
                    continue;
                }
                else
                {
                    //BELI
                    oznaci(x1,y1);
                }
            }
            else
            {
                if(tabela[x1][y1]>0&&tabela[x1][y1]<7)
                {
                    printf("Izabrali ste protivnikovu figuru, izaberite polje sa vasom figurom:");
                    continue;
                }
                else
                {
                    //CRNI
                    oznaci(x1,y1);
                }
            }
            int counter=0;
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(tabela[i][j]>=20)
                    {
                        counter++;
                        break;
                    }
                }
            }
            if(counter==0)
            {
                printf("Ne mozete pomeriti izabranu figuru, izaberite neku drugu.");
                continue;
            }
            break;
        }
        nacrtaj();
potez_2:
        printf("Unesite polje na koje pomerate figuru:");
        while(1)
        {
            scanf("%s",&p2);
            if(p2[0]=='/'&&p2[1]=='b')
            {
                procisti();
                goto pocetak;
            }
            if(p2[0]=='/'&&p2[1]=='r')
            {
                dogovor=1;
                printf("Remi ce biti ponudjen.\n");
                goto potez_2;
            }
            if(!(length(p2)==2||isalpha(p2[0])||isdigit(p2[1])))
            {
                printf("Neispravan format, unesite polje ponovo:");
                continue;
            }
            //y2
            switch(tolower(p2[0]))
            {
                case 'a':
                    y2=0;
                break;
                case 'b':
                    y2=1;
                break;
                case 'c':
                    y2=2;
                break;
                case 'd':
                    y2=3;
                break;
                case 'e':
                    y2=4;
                break;
                case 'f':
                    y2=5;
                break;
                case 'g':
                    y2=6;
                break;
                case 'h':
                    y2=7;
                break;
                default:
                    printf("Neispravan format, unesite polje ponovo:");
                    continue;
            }
            //x2
            x2=8-p2[1]+'0';
            if(x2>7)
            {
                printf("Neispravan format, unesite polje ponovo:");
                continue;
            }
            //x2&&y2
            if(tabela[x2][y2]<20)
            {
                    printf("Nepravilan potez, unesite neko od markiranih polja:");
                    continue;
            }
            break;
        }
        procisti();
        if(x1==7&&y1==4&&tabela[7][4]==6&&x2==7&&y2==6)
        {
            tabela[7][6]=6;tabela[7][4]=0;
            tabela[7][5]=4;tabela[7][7]=0;
        }
        else if(x1==7&&y1==4&&tabela[7][4]==6&&x2==7&&(y2==2||y2==1))
        {
            tabela[7][2]=6;tabela[7][4]=0;
            tabela[7][3]=4;tabela[7][0]=0;
        }
        else if(x1==0&&y1==4&&tabela[0][4]==16&&x2==0&&y2==6)
        {
            tabela[0][6]=16;tabela[0][4]=0;
            tabela[0][5]=14;tabela[0][7]=0;
        }
        else if(x1==0&&y1==4&&tabela[0][4]==16&&x2==0&&(y2==2||y2==1))
        {
            tabela[0][2]=16;tabela[0][4]=0;
            tabela[0][3]=14;tabela[0][0]=0;
        }
        else
        {
            tabela[x2][y2]=tabela[x1][y1];
            tabela[x1][y1]=0;
        }
        //promocija
        if((x2==0&&tabela[x2][y2]==1)||(x2==7&&tabela[x2][y2]==11))
        {
            int pretvaranje;
            printf("\nUnesite redni broj figure u koju ce se pesak pretvoriti:\n\t1. Konj\n\t2. Lovac\n\t3. Top\n\t4. Kraljica\nUnos:");
            while(1)
            {
                scanf("%d",&pretvaranje);
                if(pretvaranje<1||pretvaranje>4)
                {
                    printf("Unesite odgovarajuci broj od 1 do 4:");
                    continue;
                }
                else
                {
                    tabela[x2][y2]+=pretvaranje;
                    break;
                }
            }
        }
        azuriraj();
        potez++;potez%=2;
    }
    //KRAJ
    printf("<pritisnite bilo koji taster kako biste iskljucili program>");
    getchar();
    return 0;
}
int length(char st[])
{
    int c=0,i;
    for(i=0;st[i]!='\0';i++)
    {
        c++;
    }
    return c;
}
void nacrtaj()
{
    int i,j;

    if(!potez)
    {
        printf("BELI IGRA.\n");
        for(i=0;i<60;i++)   printf("_");printf("\n\n");
        printf("     A   B   C   D   E   F   G   H\n    ");
        for(i=0;i<31;i++)   printf("_");
        printf(" \n");
        for(i=0;i<8;i++)
        {
            printf("%d  |",8-i);
            for(j=0;j<8;j++)
            {
                switch(tabela[i][j])
                {
                    case  0:
                        printf("   |");
                    break;
                    case  1:
                        printf("p  |");
                    break;
                    case  2:
                        printf("s  |");
                    break;
                    case  3:
                        printf("L  |");
                    break;
                    case  4:
                        printf("T  |");
                    break;
                    case  5:
                        printf("Q  |");
                    break;
                    case  6:
                        printf("K  |");
                    break;
                    case 11:
                        printf("pc |");
                    break;
                    case 12:
                        printf("sc |");
                    break;
                    case 13:
                        printf("Lc |");
                    break;
                    case 14:
                        printf("Tc |");
                    break;
                    case 15:
                        printf("Qc |");
                    break;
                    case 16:
                        printf("Kc |");
                    break;
                    case 20:
                        printf(" * |");
                    break;
                    case 31:
                        printf("pc*|");
                    break;
                    case 32:
                        printf("sc*|");
                    break;
                    case 33:
                        printf("Lc*|");
                    break;
                    case 34:
                        printf("Tc*|");
                    break;
                    case 35:
                        printf("Qc*|");
                    break;
                    case 36:
                        printf("Kc*|");
                    break;
                }
            }
            printf("  %d\n",8-i);
            if(i<7)
            {
                printf("   |");
                for(j=0;j<8;j++)   printf("___|");
                printf("\n");
            }
        }
        printf("   |");
        for(i=0;i<8;i++)   printf("___|");
        printf("\n\n");
        printf("     A   B   C   D   E   F   G   H\n\n");
        for(i=0;i<60;i++)   printf("_");printf("\n\n");
    }
    else
    {
        printf("CRNI IGRA.\n");
        for(i=0;i<60;i++)   printf("_");printf("\n\n");
        printf("     H   G   F   E   D   C   B   A\n    ");
        for(i=0;i<31;i++)   printf("_");
        printf(" \n");
        for(i=7;i>=0;i--)
        {
            printf("%d  |",8-i);
            for(j=7;j>=0;j--)
            {
                switch(tabela[i][j])
                {
                    case  0:
                        printf("   |");
                    break;
                    case  1:
                        printf("pb |");
                    break;
                    case  2:
                        printf("sb |");
                    break;
                    case  3:
                        printf("Lb |");
                    break;
                    case  4:
                        printf("Tb |");
                    break;
                    case  5:
                        printf("Qb |");
                    break;
                    case  6:
                        printf("Kb |");
                    break;
                    case 11:
                        printf("p  |");
                    break;
                    case 12:
                        printf("s  |");
                    break;
                    case 13:
                        printf("L  |");
                    break;
                    case 14:
                        printf("T  |");
                    break;
                    case 15:
                        printf("Q  |");
                    break;
                    case 16:
                        printf("K  |");
                    break;
                    case 20:
                        printf(" * |");
                    break;
                    case 21:
                        printf("pb*|");
                    break;
                    case 22:
                        printf("sb*|");
                    break;
                    case 23:
                        printf("Lb*|");
                    break;
                    case 24:
                        printf("Tb*|");
                    break;
                    case 25:
                        printf("Qb*|");
                    break;
                    case 26:
                        printf("Kb*|");
                    break;
                }
            }
            printf("  %d\n",8-i);
            if(i>0)
            {
                printf("   |");
                for(j=0;j<8;j++)   printf("___|");
                printf("\n");
            }
        }
        printf("   |");
        for(i=0;i<8;i++)   printf("___|");
        printf("\n\n");
        printf("     H   G   F   E   D   C   B   A\n\n");
        for(i=0;i<60;i++)   printf("_");printf("\n\n");
    }
}
void postaviTabelu()
{
    int i;
    //kraljevi
    tabela[0][4]=16;
    tabela[7][4]= 6;
    //kraljice
    tabela[0][3]=15;
    tabela[7][3]= 5;
    //topovi
    tabela[0][0]=14;tabela[0][7]=14;
    tabela[7][0]= 4;tabela[7][7]= 4;
    //lovci
    tabela[0][2]=13;tabela[0][5]=13;
    tabela[7][2]= 3;tabela[7][5]= 3;
    //konji
    tabela[0][1]=12;tabela[0][6]=12;
    tabela[7][1]= 2;tabela[7][6]= 2;
    //pesaci
    for(i=0;i<8;i++)
    {
        tabela[1][i]=11;
        tabela[6][i]= 1;
    }
}
int mozeDaSeIgra(int x1,int y1,int x2,int y2)
{
    int i,j,temp[8][8],toReturn=1;
    memcpy(temp, tabela, sizeof(temp));
    tabela[x2][y2]=tabela[x1][y1];
    tabela[x1][y1]=0;
    azuriraj();
    if(sah())
        toReturn=0;
    memcpy(tabela, temp, sizeof(tabela));
    azuriraj();
    return toReturn;
}
int sah()
{
    int i,j,x,y;
    if(!potez)
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(tabela[i][j]==6)
                {
                    x=i;y=j;
                    break;
                }
            }
        }
        if(tabelaC[x][y]==1)
            return 1;
        else
            return 0;
    }
    else
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(tabela[i][j]==16)
                {
                    x=i;y=j;
                    break;
                }
            }
        }
        if(tabelaB[x][y]==1)
            return 1;
        else
            return 0;
    }
    return 0;
}
int remi()
{
    return 0;
}
int pat()
{
    printf("pat();\n");
    if(sah())
        return 0;
    int i,j,k,l;
    if(!potez)
    {
        for(i=0;i<8;i++)
        {
            printf("%d: ",i);
            for(j=0;j<8;j++)
            {
                printf("%d ",j);
                if(tabela[i][j]>0&&tabela[i][j]<7)
                    oznaci(i,j);
            }
            printf("\n");
        }
    }
    else
    {
        for(i=0;i<8;i++)
        {
            printf("%d: ",i);
            for(j=0;j<8;j++)
            {
                printf("%d ",j);
                if(tabela[i][j]>10&&tabela[i][j]<17)
                    oznaci(i,j);
            }
            printf("\n");
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(tabela[i][j]>=20)
            {
                procisti();
                return 0;
            }
        }
    }
    procisti();
    return 1;
}
int mat()
{
    if(!sah())
        return 0;
    int i,j;
    if(!potez)
    {
        for(i=0;i<8;i++)
        {
            printf("%d: ",i);
            for(j=0;j<8;j++)
            {
                printf("%d ",j);
                if(tabela[i][j]>0&&tabela[i][j]<7)
                    oznaci(i,j);
            }
            printf("\n");
        }
    }
    else
    {
        for(i=0;i<8;i++)
        {
            printf("%d: ",i);
            for(j=0;j<8;j++)
            {
                printf("%d ",j);
                if(tabela[i][j]>10&&tabela[i][j]<17)
                    oznaci(i,j);
            }
            printf("\n");
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(tabela[i][j]>=20)
            {
                procisti();
                return 0;
            }
        }
    }
    procisti();
    return 1;
}
void azuriraj()
{
    int i,j,temp[8][8];
    memcpy(temp, tabela, sizeof(temp));
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            tabelaB[i][j]=0;
            tabelaC[i][j]=0;
        }
    }
    procisti();
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(tabela[i][j]>0&&tabela[i][j]<7)
                oznaci_(i,j);
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(tabela[i][j]>=20)
                tabelaB[i][j]=1;
        }
    }
    procisti();
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(tabela[i][j]>10&&tabela[i][j]<17)
                oznaci_(i,j);
        }
    }
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(tabela[i][j]>=20)
                tabelaC[i][j]=1;
        }
    }
    memcpy(tabela, temp, sizeof(tabela));
}
void procisti()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            while(tabela[i][j]>=20)
                tabela[i][j]-=20;
        }
    }
}
void oznaci(int x1, int y1)
{
    int i,j,p,q,r;
    switch(tabela[x1][y1])
    {
        case 1:
            //pesak
            if(mozeDaSeIgra(x1,y1,x1-1,y1)&&tabela[x1-1][y1]==0)
                tabela[x1-1][y1]+=20;
            if(y1!=0&&mozeDaSeIgra(x1,y1,x1-1,y1-1)&&tabela[x1-1][y1-1]>10)
                tabela[x1-1][y1-1]+=20;
            if(y1!=7&&mozeDaSeIgra(x1,y1,x1-1,y1+1)&&tabela[x1-1][y1+1]>10)
                tabela[x1-1][y1+1]+=20;
            if(x1==6&&mozeDaSeIgra(6,y1,4,y1)&&tabela[4][y1]==0)
                tabela[4][y1]+=20;
            //en passant

        break;
        case 2:
            //konj
            for(p=1;p<3;p++)
            {
                for(q=-1;q<2;q+=2)
                {
                    for(r=-1;r<2;r+=2)
                    {
                        if(x1+p*q>=0&&x1+p*q<8&&y1+(3-p)*r>=0&&y1+(3-p)*r<8)
                        {
                            if(mozeDaSeIgra(x1,y1,x1+p*q,y1*(3-p)*r)&&(tabela[x1+p*q][y1+(3-p)*r]==0||tabela[x1+p*q][y1+(3-p)*r]>6))
                                tabela[x1+p*q][y1+(3-p)*r]+=20;
                        }
                    }
                }
            }
        break;
        case 3:
            //lovac
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1+i))
                {
                    if(tabela[x1+i][y1+i]==0)
                        tabela[x1+i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1+i]>6)
                            tabela[x1+i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1-i))
                {
                    if(tabela[x1+i][y1-i]==0)
                        tabela[x1+i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1-i]>6)
                            tabela[x1+i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1+i))
                {
                    if(tabela[x1-i][y1+i]==0)
                        tabela[x1-i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1+i]>6)
                            tabela[x1-i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1-i))
                {
                    if(tabela[x1-i][y1-i]==0)
                        tabela[x1-i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1-i]>6)
                            tabela[x1-i][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 4:
            //top
            for(i=1;x1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1))
                {
                    if(tabela[x1+i][y1]==0)
                        tabela[x1+i][y1]+=20;
                    else
                    {
                        if(tabela[x1+i][y1]>6)
                            tabela[x1+i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1))
                {
                    if(tabela[x1-i][y1]==0)
                        tabela[x1-i][y1]+=20;
                    else
                    {
                        if(tabela[x1-i][y1]>6)
                            tabela[x1-i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1+i))
                {
                    if(tabela[x1][y1+i]==0)
                        tabela[x1][y1+i]+=20;
                    else
                    {
                        if(tabela[x1][y1+i]>6)
                            tabela[x1][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1-i))
                {
                    if(tabela[x1][y1-i]==0)
                        tabela[x1][y1-i]+=20;
                    else
                    {
                        if(tabela[x1][y1-i]>6)
                            tabela[x1][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 5:
            //kraljica
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1+i))
                {
                    if(tabela[x1+i][y1+i]==0)
                        tabela[x1+i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1+i]>6)
                            tabela[x1+i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1-i))
                {
                    if(tabela[x1+i][y1-i]==0)
                        tabela[x1+i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1-i]>6)
                            tabela[x1+i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1+i))
                {
                    if(tabela[x1-i][y1+i]==0)
                        tabela[x1-i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1+i]>6)
                            tabela[x1-i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1-i))
                {
                    if(tabela[x1-i][y1-i]==0)
                        tabela[x1-i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1-i]>6)
                            tabela[x1-i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1))
                {
                    if(tabela[x1+i][y1]==0)
                        tabela[x1+i][y1]+=20;
                    else
                    {
                        if(tabela[x1+i][y1]>6)
                            tabela[x1+i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1))
                {
                    if(tabela[x1-i][y1]==0)
                        tabela[x1-i][y1]+=20;
                    else
                    {
                        if(tabela[x1-i][y1]>6)
                            tabela[x1-i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1+i))
                {
                    if(tabela[x1][y1+i]==0)
                        tabela[x1][y1+i]+=20;
                    else
                    {
                        if(tabela[x1][y1+i]>6)
                            tabela[x1][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1-i))
                {
                    if(tabela[x1][y1-i]==0)
                        tabela[x1][y1-i]+=20;
                    else
                    {
                        if(tabela[x1][y1-i]>6)
                            tabela[x1][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 6:
            //kralj
            if(x1!=7&&y1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1+1,y1+1)&&(tabela[x1+1][y1+1]==0||tabela[x1+1][y1+1]>6))
                    tabela[x1+1][y1+1]+=20;
            }
            if(x1!=0&&y1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1-1,y1+1)&&(tabela[x1-1][y1+1]==0||tabela[x1-1][y1+1]>6))
                    tabela[x1-1][y1+1]+=20;
            }
            if(x1!=7&&y1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1+1,y1-1)&&(tabela[x1+1][y1-1]==0||tabela[x1+1][y1-1]>6))
                    tabela[x1+1][y1-1]+=20;
            }
            if(x1!=0&&y1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1-1,y1-1)&&(tabela[x1-1][y1-1]==0||tabela[x1-1][y1-1]>6))
                    tabela[x1-1][y1-1]+=20;
            }
            if(x1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1+1,y1)&&(tabela[x1+1][y1]==0||tabela[x1+1][y1]>6))
                    tabela[x1+1][y1]+=20;
            }
            if(x1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1-1,y1)&&(tabela[x1-1][y1]==0||tabela[x1-1][y1]>6))
                    tabela[x1-1][y1]+=20;
            }
            if(y1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1+1)&&(tabela[x1][y1+1]==0||tabela[x1][y1+1]>6))
                    tabela[x1][y1+1]+=20;
            }
            if(y1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1-1)&&(tabela[x1][y1-1]==0||tabela[x1][y1-1]>6))
                    tabela[x1][y1-1]+=20;
            }
            //ROKADA
            //O-O
            //1. uslov: kralj i top kojima se vrsi rokada nisu pomerani sa svojih pozicija od pocetka partije
            if(kraljevPrviPotezB&&topovPrviPotezB1)
            {
            //2. uslov: na poljima između kralja i topa s kojim se rokira nema drugih figura
            if((tabela[7][5]==0||tabela[7][5]==20)&&(tabela[7][6]==0||tabela[7][5]==0))
            {
            //3. uslov: kralj koji se rokira nije pod sahom
            if(!sah())
            {
            //4. uslov: polje preko kojeg kralj prelazi kao i polje do kojeg kralj dolazi nisu pod udarom
            if(!(tabelaC[7][5]||tabelaC[7][6]))
            {
            if(rokada(0))
            tabela[7][6]+=20;
            }}}}

            //O-O-O
            //1. uslov: kralj i top kojima se vrsi rokada nisu pomerani sa svojih pozicija od pocetka partije
            if(kraljevPrviPotezB&&topovPrviPotezB2)
            {
            //2. uslov: na poljima između kralja i topa s kojim se rokira nema drugih figura
            if((tabela[7][3]==0||tabela[7][3]==20)&&(tabela[7][2]==0||tabela[7][2]==20)&&(tabela[7][1]==0||tabela[7][1]==20))
            {
            //3. uslov: kralj koji se rokira nije pod sahom
            if(!sah())
            {
            //4. uslov: polje preko kojeg kralj prelazi kao i polje do kojeg kralj dolazi nisu pod udarom
            if(!(tabelaC[7][3]||tabelaC[7][2]))
            {
            if(rokada(1))
            {
            tabela[7][2]+=20;
            tabela[7][1]+=20;
            }
            }}}}
        break;
        case 11:
            //pesak
            if(mozeDaSeIgra(x1,y1,x1+1,y1)&&tabela[x1+1][y1]==0)
                tabela[x1+1][y1]+=20;
            if(y1!=0&&mozeDaSeIgra(x1,y1,x1+1,y1-1)&&(tabela[x1+1][y1-1]>0&&tabela[x1+1][y1-1]<7))
                tabela[x1+1][y1-1]+=20;
            if(y1!=7&&mozeDaSeIgra(x1,y1,x1+1,y1+1)&&(tabela[x1+1][y1+1]>0&&tabela[x1+1][y1+1]<7))
                tabela[x1+1][y1+1]+=20;
            if(x1==1&&mozeDaSeIgra(1,y1,3,y1)&&tabela[3][y1]==0)
                tabela[3][y1]+=20;
            break;
        case 12:
            //konj
            for(p=1;p<3;p++)
            {
                for(q=-1;q<2;q+=2)
                {
                    for(r=-1;r<2;r+=2)
                    {
                        if(x1+p*q>=0&&x1+p*q<8&&y1+(3-p)*r>=0&&y1+(3-p)*r<8)
                        {
                            if(mozeDaSeIgra(x1,y1,x1+p*q,y1*(3-p)*r)&&(tabela[x1+p*q][y1+(3-p)*r]<11||tabela[x1+p*q][y1+(3-p)*r]>16))
                                tabela[x1+p*q][y1+(3-p)*r]+=20;
                        }
                    }
                }
        }
        break;
        case 13:
            //lovac
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1+i))
                {
                    if(tabela[x1+i][y1+i]==0)
                        tabela[x1+i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1+i]<7)
                            tabela[x1+i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1-i))
                {
                    if(tabela[x1+i][y1-i]==0)
                        tabela[x1+i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1-i]<7)
                            tabela[x1+i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1+i))
                {
                    if(tabela[x1-i][y1+i]==0)
                        tabela[x1-i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1+i]<7)
                            tabela[x1-i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1-i))
                {
                    if(tabela[x1-i][y1-i]==0)
                        tabela[x1-i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1-i]<7)
                            tabela[x1-i][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 14:
            //top
            for(i=1;x1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1))
                {
                    if(tabela[x1+i][y1]==0)
                        tabela[x1+i][y1]+=20;
                    else
                    {
                        if(tabela[x1+i][y1]<7)
                            tabela[x1+i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1))
                {
                    if(tabela[x1-i][y1]==0)
                        tabela[x1-i][y1]+=20;
                    else
                    {
                        if(tabela[x1-i][y1]<7)
                            tabela[x1-i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1+i))
                {
                    if(tabela[x1][y1+i]==0)
                        tabela[x1][y1+i]+=20;
                    else
                    {
                        if(tabela[x1][y1+i]<7)
                            tabela[x1][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1-i))
                {
                    if(tabela[x1][y1-i]==0)
                        tabela[x1][y1-i]+=20;
                    else
                    {
                        if(tabela[x1][y1-i]<7)
                            tabela[x1][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 15:
            //kraljica
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1+i))
                {
                    if(tabela[x1+i][y1+i]==0)
                        tabela[x1+i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1+i]<7)
                            tabela[x1+i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1-i))
                {
                    if(tabela[x1+i][y1-i]==0)
                        tabela[x1+i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1-i]<7)
                            tabela[x1+i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1+i))
                {
                    if(tabela[x1-i][y1+i]==0)
                        tabela[x1-i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1+i]<7)
                            tabela[x1-i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1-i))
                {
                    if(tabela[x1-i][y1-i]==0)
                        tabela[x1-i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1-i]<7)
                            tabela[x1-i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1+i,y1))
                {
                    if(tabela[x1+i][y1]==0)
                        tabela[x1+i][y1]+=20;
                    else
                    {
                        if(tabela[x1+i][y1]<7)
                            tabela[x1+i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1-i,y1))
                {
                    if(tabela[x1-i][y1]==0)
                        tabela[x1-i][y1]+=20;
                    else
                    {
                        if(tabela[x1-i][y1]<7)
                            tabela[x1-i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1+i))
                {
                    if(tabela[x1][y1+i]==0)
                        tabela[x1][y1+i]+=20;
                    else
                    {
                        if(tabela[x1][y1+i]<7)
                            tabela[x1][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1-i))
                {
                    if(tabela[x1][y1-i]==0)
                        tabela[x1][y1-i]+=20;
                    else
                    {
                        if(tabela[x1][y1-i]<7)
                            tabela[x1][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 16:
            //kralj
            if(x1!=7&&y1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1+1,y1+1)&&(tabela[x1+1][y1+1]<7))
                    tabela[x1+1][y1+1]+=20;
            }
            if(x1!=0&&y1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1-1,y1+1)&&(tabela[x1-1][y1+1]<7))
                    tabela[x1-1][y1+1]+=20;
            }
            if(x1!=7&&y1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1+1,y1-1)&&(tabela[x1+1][y1-1]<7))
                    tabela[x1+1][y1-1]+=20;
            }
            if(x1!=0&&y1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1-1,y1-1)&&(tabela[x1-1][y1-1]<7))
                    tabela[x1-1][y1-1]+=20;
            }
            if(x1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1+1,y1)&&(tabela[x1+1][y1]<7))
                    tabela[x1+1][y1]+=20;
            }
            if(x1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1-1,y1)&&(tabela[x1-1][y1]<7))
                    tabela[x1-1][y1]+=20;
            }
            if(y1!=7)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1+1)&&(tabela[x1][y1+1]<7))
                    tabela[x1][y1+1]+=20;
            }
            if(y1!=0)
            {
                if(mozeDaSeIgra(x1,y1,x1,y1-1)&&(tabela[x1][y1-1]<7))
                    tabela[x1][y1-1]+=20;
            }
            //ROKADA
            //O-O
            //1. uslov: kralj i top kojima se vrsi rokada nisu pomerani sa svojih pozicija od pocetka partije
            if(kraljevPrviPotezC&&topovPrviPotezC1)
            {
            //2. uslov: na poljima između kralja i topa s kojim se rokira nema drugih figura
            if((tabela[0][5]==0||tabela[0][5]==20)&&(tabela[0][6]==0||tabela[0][5]==0))
            {
            //3. uslov: kralj koji se rokira nije pod sahom
            if(!sah())
            {
            //4. uslov: polje preko kojeg kralj prelazi kao i polje do kojeg kralj dolazi nisu pod udarom
            if(!(tabelaB[0][5]||tabelaB[0][6]))
            {
            if(rokada(0))
            tabela[0][6]+=20;
            }}}}

            //O-O-O
            //1. uslov: kralj i top kojima se vrsi rokada nisu pomerani sa svojih pozicija od pocetka partije
            if(kraljevPrviPotezC&&topovPrviPotezC2)
            {
            //2. uslov: na poljima između kralja i topa s kojim se rokira nema drugih figura
            if((tabela[0][3]==0||tabela[0][3]==20)&&(tabela[0][2]==0||tabela[0][2]==20)&&(tabela[0][1]==0||tabela[0][1]==20))
            {
            //3. uslov: kralj koji se rokira nije pod sahom
            if(!sah())
            {
            //4. uslov: polje preko kojeg kralj prelazi kao i polje do kojeg kralj dolazi nisu pod udarom
            if(!(tabelaB[0][3]||tabelaB[0][2]))
            {
            if(rokada(1))
            {
            tabela[0][2]+=20;
            tabela[0][1]+=20;
            }
            }}}}
        break;
    }
}
void oznaci_(int x1, int y1)
{
    int i,j,p,q,r;
    switch(tabela[x1][y1])
    {
        case 1:
            //pesak
            if(tabela[x1-1][y1]==0)
                tabela[x1-1][y1]+=20;
            if(y1!=0&&tabela[x1-1][y1-1]>10)
                tabela[x1-1][y1-1]+=20;
            if(y1!=7&&tabela[x1-1][y1+1]>10)
                tabela[x1-1][y1+1]+=20;
            if(x1==6&&tabela[4][y1]==0)
                tabela[4][y1]+=20;
            //en passant

        break;
        case 2:
            //konj
            for(p=1;p<3;p++)
            {
                for(q=-1;q<2;q+=2)
                {
                    for(r=-1;r<2;r+=2)
                    {
                        if(x1+p*q>=0&&x1+p*q<8&&y1+(3-p)*r>=0&&y1+(3-p)*r<8)
                        {
                            if((tabela[x1+p*q][y1+(3-p)*r]==0||tabela[x1+p*q][y1+(3-p)*r]>6))
                                tabela[x1+p*q][y1+(3-p)*r]+=20;
                        }
                    }
                }
            }
        break;
        case 3:
            //lovac
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(tabela[x1+i][y1+i]==0)
                    tabela[x1+i][y1+i]+=20;
                else
                {
                    if(tabela[x1+i][y1+i]>6)
                        tabela[x1+i][y1+i]+=20;
                    break;
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(tabela[x1+i][y1-i]==0)
                    tabela[x1+i][y1-i]+=20;
                else
                {
                    if(tabela[x1+i][y1-i]>6)
                        tabela[x1+i][y1-i]+=20;
                    break;
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(tabela[x1-i][y1+i]==0)
                    tabela[x1-i][y1+i]+=20;
                else
                {
                    if(tabela[x1-i][y1+i]>6)
                        tabela[x1-i][y1+i]+=20;
                    break;
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(tabela[x1-i][y1-i]==0)
                    tabela[x1-i][y1-i]+=20;
                else
                {
                    if(tabela[x1-i][y1-i]>6)
                        tabela[x1-i][y1-i]+=20;
                    break;
                }
            }
        break;
        case 4:
            //top
            for(i=1;x1+i<8;i++)
            {
                if(tabela[x1+i][y1]==0)
                    tabela[x1+i][y1]+=20;
                else
                {
                    if(tabela[x1+i][y1]>6)
                        tabela[x1+i][y1]+=20;
                    break;
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(tabela[x1-i][y1]==0)
                    tabela[x1-i][y1]+=20;
                else
                {
                    if(tabela[x1-i][y1]>6)
                        tabela[x1-i][y1]+=20;
                    break;
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(tabela[x1][y1+i]==0)
                    tabela[x1][y1+i]+=20;
                else
                {
                    if(tabela[x1][y1+i]>6)
                        tabela[x1][y1+i]+=20;
                    break;
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(tabela[x1][y1-i]==0)
                    tabela[x1][y1-i]+=20;
                else
                {
                    if(tabela[x1][y1-i]>6)
                        tabela[x1][y1-i]+=20;
                    break;
                }
            }
        break;
        case 5:
            //kraljica
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(tabela[x1+i][y1+i]==0)
                    tabela[x1+i][y1+i]+=20;
                else
                {
                    if(tabela[x1+i][y1+i]>6)
                        tabela[x1+i][y1+i]+=20;
                    break;
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(tabela[x1+i][y1-i]==0)
                    tabela[x1+i][y1-i]+=20;
                else
                {
                    if(tabela[x1+i][y1-i]>6)
                        tabela[x1+i][y1-i]+=20;
                    break;
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(tabela[x1-i][y1+i]==0)
                    tabela[x1-i][y1+i]+=20;
                else
                {
                    if(tabela[x1-i][y1+i]>6)
                        tabela[x1-i][y1+i]+=20;
                    break;
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(tabela[x1-i][y1-i]==0)
                    tabela[x1-i][y1-i]+=20;
                else
                {
                    if(tabela[x1-i][y1-i]>6)
                        tabela[x1-i][y1-i]+=20;
                    break;
                }
            }
            for(i=1;x1+i<8;i++)
            {
                if(tabela[x1+i][y1]==0)
                    tabela[x1+i][y1]+=20;
                else
                {
                    if(tabela[x1+i][y1]>6)
                        tabela[x1+i][y1]+=20;
                    break;
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(tabela[x1-i][y1]==0)
                    tabela[x1-i][y1]+=20;
                else
                {
                    if(tabela[x1-i][y1]>6)
                        tabela[x1-i][y1]+=20;
                    break;
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(tabela[x1][y1+i]==0)
                    tabela[x1][y1+i]+=20;
                else
                {
                    if(tabela[x1][y1+i]>6)
                        tabela[x1][y1+i]+=20;
                    break;
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(tabela[x1][y1-i]==0)
                    tabela[x1][y1-i]+=20;
                else
                {
                    if(tabela[x1][y1-i]>6)
                        tabela[x1][y1-i]+=20;
                    break;
                }
            }
        break;
        case 6:
            //kralj
            if(x1!=7&&y1!=7)
            {
                if((tabela[x1+1][y1+1]==0||tabela[x1+1][y1+1]>6))
                    tabela[x1+1][y1+1]+=20;
            }
            if(x1!=0&&y1!=7)
            {
                if((tabela[x1-1][y1+1]==0||tabela[x1-1][y1+1]>6))
                    tabela[x1-1][y1+1]+=20;
            }
            if(x1!=7&&y1!=0)
            {
                if((tabela[x1+1][y1-1]==0||tabela[x1+1][y1-1]>6))
                    tabela[x1+1][y1-1]+=20;
            }
            if(x1!=0&&y1!=0)
            {
                if((tabela[x1-1][y1-1]==0||tabela[x1-1][y1-1]>6))
                    tabela[x1-1][y1-1]+=20;
            }
            if(x1!=7)
            {
                if((tabela[x1+1][y1]==0||tabela[x1+1][y1]>6))
                    tabela[x1+1][y1]+=20;
            }
            if(x1!=0)
            {
                if((tabela[x1-1][y1]==0||tabela[x1-1][y1]>6))
                    tabela[x1-1][y1]+=20;
            }
            if(y1!=7)
            {
                if((tabela[x1][y1+1]==0||tabela[x1][y1+1]>6))
                    tabela[x1][y1+1]+=20;
            }
            if(y1!=0)
            {
                if((tabela[x1][y1-1]==0||tabela[x1][y1-1]>6))
                    tabela[x1][y1-1]+=20;
            }
            //rokada
        break;
        case 11:
            //pesak
            if(tabela[x1+1][y1]==0)
                tabela[x1+1][y1]+=20;
            if(y1!=0&&(tabela[x1+1][y1-1]>0&&tabela[x1+1][y1-1]<7))
                tabela[x1+1][y1-1]+=20;
            if(y1!=7&&(tabela[x1+1][y1-1]>0&&tabela[x1+1][y1-1]<7))
                tabela[x1+1][y1+1]+=20;
            if(x1==1&&tabela[3][y1]==0)
                tabela[3][y1]+=20;
            break;
        case 12:
            //konj
            for(p=1;p<3;p++)
            {
                for(q=-1;q<2;q+=2)
                {
                    for(r=-1;r<2;r+=2)
                    {
                        if(x1+p*q>=0&&x1+p*q<8&&y1+(3-p)*r>=0&&y1+(3-p)*r<8)
                        {
                            if((tabela[x1+p*q][y1+(3-p)*r]<11||tabela[x1+p*q][y1+(3-p)*r]>16))
                                tabela[x1+p*q][y1+(3-p)*r]+=20;
                        }
                    }
                }
        }
        break;
        case 13:
            //lovac
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1+i][y1+i]==0)
                        tabela[x1+i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1+i]<7)
                            tabela[x1+i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1+i][y1-i]==0)
                        tabela[x1+i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1-i]<7)
                            tabela[x1+i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1-i][y1+i]==0)
                        tabela[x1-i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1+i]<7)
                            tabela[x1-i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1-i][y1-i]==0)
                        tabela[x1-i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1-i]<7)
                            tabela[x1-i][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 14:
            //top
            for(i=1;x1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1+i][y1]==0)
                        tabela[x1+i][y1]+=20;
                    else
                    {
                        if(tabela[x1+i][y1]<7)
                            tabela[x1+i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1-i][y1]==0)
                        tabela[x1-i][y1]+=20;
                    else
                    {
                        if(tabela[x1-i][y1]<7)
                            tabela[x1-i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1][y1+i]==0)
                        tabela[x1][y1+i]+=20;
                    else
                    {
                        if(tabela[x1][y1+i]<7)
                            tabela[x1][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1][y1-i]==0)
                        tabela[x1][y1-i]+=20;
                    else
                    {
                        if(tabela[x1][y1-i]<7)
                            tabela[x1][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 15:
            //kraljica
            for(i=1;x1+i<8&&y1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1+i][y1+i]==0)
                        tabela[x1+i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1+i]<7)
                            tabela[x1+i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8&&y1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1+i][y1-i]==0)
                        tabela[x1+i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1+i][y1-i]<7)
                            tabela[x1+i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1-i][y1+i]==0)
                        tabela[x1-i][y1+i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1+i]<7)
                            tabela[x1-i][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0&&y1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1-i][y1-i]==0)
                        tabela[x1-i][y1-i]+=20;
                    else
                    {
                        if(tabela[x1-i][y1-i]<7)
                            tabela[x1-i][y1-i]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1+i][y1]==0)
                        tabela[x1+i][y1]+=20;
                    else
                    {
                        if(tabela[x1+i][y1]<7)
                            tabela[x1+i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;x1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1-i][y1]==0)
                        tabela[x1-i][y1]+=20;
                    else
                    {
                        if(tabela[x1-i][y1]<7)
                            tabela[x1-i][y1]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1+i<8;i++)
            {
                if(1)
                {
                    if(tabela[x1][y1+i]==0)
                        tabela[x1][y1+i]+=20;
                    else
                    {
                        if(tabela[x1][y1+i]<7)
                            tabela[x1][y1+i]+=20;
                        break;
                    }
                }
            }
            for(i=1;y1-i>=0;i++)
            {
                if(1)
                {
                    if(tabela[x1][y1-i]==0)
                        tabela[x1][y1-i]+=20;
                    else
                    {
                        if(tabela[x1][y1-i]<7)
                            tabela[x1][y1-i]+=20;
                        break;
                    }
                }
            }
        break;
        case 16:
            //kralj
            if(x1!=7&&y1!=7)
            {
                if((tabela[x1+1][y1+1]<7))
                    tabela[x1+1][y1+1]+=20;
            }
            if(x1!=0&&y1!=7)
            {
                if((tabela[x1-1][y1+1]<7))
                    tabela[x1-1][y1+1]+=20;
            }
            if(x1!=7&&y1!=0)
            {
                if((tabela[x1+1][y1-1]<7))
                    tabela[x1+1][y1-1]+=20;
            }
            if(x1!=0&&y1!=0)
            {
                if((tabela[x1-1][y1-1]<7))
                    tabela[x1-1][y1-1]+=20;
            }
            if(x1!=7)
            {
                if((tabela[x1+1][y1]<7))
                    tabela[x1+1][y1]+=20;
            }
            if(x1!=0)
            {
                if((tabela[x1-1][y1]<7))
                    tabela[x1-1][y1]+=20;
            }
            if(y1!=7)
            {
                if((tabela[x1][y1+1]<7))
                    tabela[x1][y1+1]+=20;
            }
            if(y1!=0)
            {
                if((tabela[x1][y1-1]<7))
                    tabela[x1][y1-1]+=20;
            }
            //rokada
        break;
    }
}
int rokada(int t)
{
    //!t O-O
    // t O-O-O
    int temp[8][8],i,j,x=(1-potez)*7,toReturn=1;
    memcpy(temp, tabela, sizeof(temp));
    tabela[x][4-4*t+2]=6;tabela[x][4]=0;
    tabela[x][4-2*t+1]=4;tabela[x][(1-t)*7]=0;
    azuriraj();
    if(sah())
        toReturn=0;
    memcpy(tabela, temp, sizeof(tabela));
    azuriraj();
    return toReturn;
}
