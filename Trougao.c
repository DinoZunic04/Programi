#include <stdio.h>
#include <math.h>
#define PI 3.14159265
static int dimenzije;
void napisiUgao(double t)
{
    double x=t;
    x*=180.0/PI;
    int a[3];
    a[0]=(int)(x);
    a[1]=(int)((x-floor(x))*60.0);
    a[2]=(int)((((x-floor(x))*60.0)-floor((x-floor(x))*60.0))*60.0);

    printf("%3d*",a[0]);
    if(a[1]!=0)
        printf(" %2d\'",a[1]);
    if(a[2]!=0)
        printf(" %2d\"",a[2]);
}
double povrsinaTrougla(double a, double b, double c)
{
    double s=(a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
double duzinaDuzi(double a[], double b[])
{
    int i;
    double s=0.0;
    for(i=0;i<dimenzije;i++)
        s+=(a[i]-b[i])*(a[i]-b[i]);
    return sqrt(s);
}
int main() {
    int i,j,k;
    printf("T R O U G A O\n~Dino\n\n");
    while(1)
    {
        printf("Unesite broj dimenzija: ");
        scanf("%d",&dimenzije);
        if(dimenzije<=0)
            printf("Broj dimenzija mora biti prirodan.\n");
        else if(dimenzije==1)
            printf("Nije moguce nacrtati trougao na pravoj liniji.\n");
        else if(dimenzije>3)
        {
            if(dimenzije==4)
                printf("Malo ste preterali, cetvorodimenzionalni prostor ne postoji (osim ako ste matematicar).\n");
            else if(dimenzije<21)
                printf("Malo ste preterali, prostor sa %d dimenzija ne postoji (osim ako ste matematicar).\n",dimenzije);
            else if(dimenzije%10==1)
                printf("Malo ste preterali, prostor sa %d dimenzijom ne postoji (osim ako ste matematicar).\n",dimenzije);
            else if(dimenzije%10<5)
                printf("Malo ste preterali, prostor sa %d dimenzije ne postoji (osim ako ste matematicar).\n",dimenzije);
            else
                printf("Malo ste preterali, prostor sa %d dimenzija ne postoji (osim ako ste matematicar).\n",dimenzije);
        }
        else
            break;
    }
    double t[3][dimenzije];
label:
    for(i=0;i<3;i++){
    for(j=0;j<dimenzije;j++){
        printf("Unesite ");
        switch(j)
        {
            case 0:printf("x ");break;
            case 1:printf("y ");break;
            case 2:printf("z ");break;
        }
        printf("koordinatu tacke ");
        switch(i)
        {
            case 0:printf("A: ");break;
            case 1:printf("B: ");break;
            case 2:printf("C: ");break;
        }
        scanf("%lf",&t[i][j]);
    }}
    for(i=0;i<3;i++){
        int check[2]={0,0};
        for(j=0;j<dimenzije;j++)
        {
            if(t[i][j]!=t[(i+1)%3][j])
                check[0]++;
            if(t[i][j]!=t[(i+2)%3][j])
                check[1]++;
        }
        if(!check[0]||!check[0])
        {
            printf("Uneli ste tacke sa istim koordinatama, tacke se ne smeju preklapati.\n");
            goto label;
        }
    }
    double vAB[dimenzije],vAC[dimenzije],vK[dimenzije];
    int vCheck=0;
    for(i=0;i<dimenzije;i++)
    {
        vAB[i]=t[0][i]-t[1][i];
        vAC[i]=t[0][i]-t[2][i];
        vK[i]=vAB[i]/vAC[i];
    }
    for(i=0;i<dimenzije;i++)
    {
        if(vK[i]!=vK[(i+1)%dimenzije])
            vCheck++;
    }
    if(!vCheck)
    {
        printf("Tacke su kolinearne(pripadaju istoj pravoj).\nTrougao se ne moze napraviti od kolinearnih tacaka.\n");
        goto label;
    }
    double a=duzinaDuzi(t[1],t[2]), b=duzinaDuzi(t[0],t[2]), c=duzinaDuzi(t[0],t[1]);
    printf("\nstranice:\na = %.6lf\nb = %.6lf\nc = %.6lf\n\n",a,b,c);
    double alfa,beta,gama;
    alfa=acos((b*b+c*c-a*a)/2.0/b/c);
    beta=acos((a*a+c*c-b*b)/2.0/a/c);
    gama=acos((b*b+a*a-c*c)/2.0/a/b);
    printf("uglovi:\n<BAC = ");napisiUgao(alfa);
    printf("\n<ABC = ");napisiUgao(beta);
    printf("\n<ACB = ");napisiUgao(gama);
    printf("\n\n");
    double povrsina,obim;
    obim=a+b+c;
    povrsina = povrsinaTrougla(a,b,c);
    printf("obim:\nO=%.6lf\n\npovrsina:\nA = %.6lf\n\n",obim,povrsina);
    double ha,hb,hc;
    ha=2.0*povrsina/a;
    hb=2.0*povrsina/b;
    hc=2.0*povrsina/c;
    printf("visine:\nha=%.6lf\nhb=%.6lf\nhc=%.6lf\n\n",ha,hb,hc);
    if(dimenzije==3)
    {
        double tp[3][3][3];
        for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        for(k=0;k<3;k++){
            tp[i][j][k]=t[j][k];
        }
        tp[i][j][i]=0.0;
        }}
        double as[3],bs[3],cs[3];
        for(i=0;i<3;i++)
        {
            as[i]=duzinaDuzi(tp[i][1],tp[i][2]);
            bs[i]=duzinaDuzi(tp[i][0],tp[i][2]);
            cs[i]=duzinaDuzi(tp[i][0],tp[i][1]);
        }
        double povrsine[3];
        printf("povrsina projekcije trougla na:\n");
        for(i=0;i<3;i++)
        {
            povrsine[i]=povrsinaTrougla(as[i],bs[i],cs[i]);
            switch(i)
            {
                case 0:
                printf("yOz ravan: ");
                break;
                case 1:
                printf("xOz ravan: ");
                break;
                case 2:
                printf("xOy ravan: ");
                break;
            }
            printf("%.6lf\n",povrsine[i]);
        }
    }
    getchar();getchar();
    return 0;
}
