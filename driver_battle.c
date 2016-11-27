#include "battle.h"
#include "queue.h"
#include <stdio.h>
#include "enemy.h"
#include "player.h"
#include "stat.h"
#include "boolean.h"

void scanname(Name *A);

int main()
{
	Player P;
	Enemy E;
	int l,j,p;
	Queue Qt;
	int menang;
	char n;
	
	printf("nama player: ");
	scanname(&(name(P)));
	strRate(P)=20;
	defRate(P)=20;
	hpRate(P)=10;
	maxHp(P)=200;
	cHp(P)=200;
	str(P)=30;
	def(P)=60;
	exp(P)=0;
	lvl(P)=2;
	printf("nama enemy: ");
	scanname(&(name(E)));
	strRate(E)=20;
	defRate(E)=20;
	hpRate(E)=10;
	maxHp(E)=200;
	cHp(E)=200;
	str(E)=30;
	def(E)=30;
	scanf ("%d",&p);
	for (l=1;l<=p;l++)
	{
		CreateEmptyQue(&Qt,4);
		for (j=1;j<=4;j++)
		{
			scanf(" %c",&n); /*n=CC*/
							/*ADV()*/
			Add(&Qt,n);
		}
		move(E)[l]=Qt;
	}
	maxM(E)=p;
	battle(&P,&E,&menang);
	if (menang==1)
	{
		printf("Player menang\n");
	}
	else if (menang==2)
	{
		printf("Player kalah\n");
	}
	else
	{
		printf("Seri\n");
	}
}

void scanname(Name *A)
{
	char c;
	int i;
	
	i=0;
	do
	{
		scanf("%c",&c);
		(*A).TabKata[i]=c;
		i++;
	}while (c!='\n' && c!= '\r');
	(*A).Length=i-2;
}
