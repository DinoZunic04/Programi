#include <stdio.h>
int main()
{
	int godina,mesec,dan,jelPrestupna=0;
	printf("Unesite datum:");
	scanf("%d/%d/%d.",&dan,&mesec,&godina);
	if(godina%4==0&&(godina%100!=0||godina%400==0))
		jelPrestupna=1;
	switch(mesec)
	{
		case 2:
			if(jelPrestupna==0)
			{
				if(dan==28){
					dan=1;
					mesec=3;
				}else
				{
					dan++;
				}
			}else
			{
				if(dan==29){
					dan=1;
					mesec=3;
				}else
				{
					dan++;
				}
			}
		break;
		case  1:
		case  3:
		case  5:
		case  7:
		case  8:
		case 10:
		case 12:
			if(dan==31)
			{
				dan=1;
				if(mesec==12)
				{
					mesec=1;
					godina++;
				}else
				{
					mesec++;
				}
			}else
			{
				dan++;
			}
		break;
		default:
			if(dan==30)
			{
				dan=1;
				mesec++;
			}else
			{
				dan++;
			}
	}//switch
	printf("%2d/%2d/%4d.\n",dan,mesec,godina);
	scanf("%d",dan);
	return 0;
}
