#include "battle.h"
#include "queue.h"
#include <stdio.h>
#include "enemy.h"
#include "player.h"
#include "stat.h"

void scanname(Name *A);

int main()
{
	Player P;
	Enemy E;
	int l,j,p;
	Queue Qt;
	char n;
	
	printf("nama player: ");
	scanname(&(P.stat.name));
	strRate(P)=20;
	defRate(P)=20;
	hpRate(P)=10;
	maxHp(P)=200;
	cHp(P)=200;
	str(P)=30;
	def(P)=30;
	exp(P)=0;
	lvl(P)=2;
	printf("nama enemy: ");
	scanname(&(E.stat.name));
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
	maxm(E)=p;
	battle(&P,&E);
}

void scanname(Name *A)
{
	char c;
	int i;
	
	i=0;
	do
	{
		scanf("%c",&c);
		(*A).tabName[i]=c;
		i++;
	}while (c!='\n' && c!= '\r');
	(*A).length=i-2;
}
