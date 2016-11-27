#include "stackt.h"
#include "queue.h"
#include "boolean.h"
#include "battle.h"
#include "enemy.h"
#include "player.h"
#include "stat.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/* PROCEDURE BATTLE */

void battle (Player *P, Enemy *M, int *menang)
{
	/*KAMUS*/
	int round, randa, randb, cr;
	Queue Qp,Qm;
	Stack S;
	char am,ap;
	time_t t;
	
	/*ALGORITMA*/
	srand((unsigned) time(&t));
    randa=((rand()%4)+1);
    do
    {
		randb=((rand()%4)+1);
	}
	while (randb==randa);
	round=1;
	cHp(*M)=maxHp(*M);
	ReadFileM(&S,move(*M),maxM(*M));
	while (cHp(*P)>0 && cHp(*M)>0 && !IsEmptyStack(S))
	{
		CreateEmptyQue(&Qp,4);
		Pop(&S,&Qm);
		cr=0;
		while (!IsFullQue(Qp))
		{
			PrintNama(name(*M));
			printf(" attacked!\n");
			cetakbattle(*P,*M,Qp,Qm,round,randa,randb,cr,&am);
			printf("Inputted command: ");
			printactuser(Qp,cr,&ap);
			printf("\n");
			printf("Input command : ");
			inputactuser(&Qp);
			printf("\n");
		}
		getchar();
		cr=1;
		while (cr<=4 && cHp(*P)>0 && cHp(*M)>0)
		{
			cetakbattle(*P,*M,Qp,Qm,round,randa,randb,cr,&am);
			printf("Inputted command: ");
			printactuser(Qp,cr,&ap);
			printf("\n");
			printcomment(P,M,ap,am);
			cr++;
		}
		round++;
	}
	if (cHp(*M)<=0)
	{
		(*menang)=1;
		AddExp(P,round,maxM(*M));
	}
	else if (cHp(*P)<=0)
	{
		(*menang)=2;
	}
	else
	{
		(*menang)=3;
	}
}

void printcomment(Player *P, Enemy *M,char ap, char am)
{
	/*KAMUS*/
	int dmg;
	
	/*ALGORITMA*/
	if (ap=='A')
	{
		if (am=='B')
		{
			PrintNama(name(*P));
			printf(" attacked! But ");
			PrintNama(name(*M));
			printf(" blocked!");
		}
		else if (am=='A')
		{
			PrintNama(name(*P));
			printf(" tries to attack! But ");
			PrintNama(name(*M));
			printf(" evaded!");
		}
		else if (am=='F')
		{
			dmg=randomdmg(*P,*M,true);
			PrintNama(name(*P));
			printf(" attacked! ");
			PrintNama(name(*M));
			printf(" -%d HP",dmg);
			cHp(*M)-=dmg;
		}
	}
	else if (ap=='B')
	{
		if (am=='A')
		{
			PrintNama(name(*M));
			printf(" attacked! But ");
			PrintNama(name(*P));
			printf(" blocked!");
		}
		else if (am=='B')
		{
			PrintNama(name(*P));
			printf(" Blocked. ");
			PrintNama(name(*M));
			printf(" blocked too. Nothing happened.");
		}
		else if (am=='F')
		{
			dmg=randomdmg(*P,*M,false);
			PrintNama(name(*P));
			printf(" blocked! but ");
			PrintNama(name(*M));
			printf(" is too strong. HP-%d",dmg);
			cHp(*P)-=dmg;
		}
	}
	else if (ap=='F')
	{
		if (am=='B')
		{
			dmg=randomdmg(*P,*M,true);
			PrintNama(name(*M));
			printf(" blocked! but ");
			PrintNama(name(*P));
			printf(" is too strong. HP-%d",dmg);
			cHp(*M)-=dmg;
		}
		else if (am=='F')
		{
			PrintNama(name(*P));
			printf(" and ");
			PrintNama(name(*M));
			printf(" both flocked. Nothing happened.");
		}
		else if (am=='A')
		{
			dmg=randomdmg(*P,*M,false);
			PrintNama(name(*M));
			printf(" attacked! ");
			PrintNama(name(*P));
			printf(" -%d HP",dmg);
			cHp(*P)-=dmg;
		}
	}
	printf("\n");
	printf("Push enter to continue\n");
	getchar();
}

void printactuser(Queue Q, int cr, char *ap)
{
	/*KAMUS*/
	Queue Qs;
	char ch;
	int p;
	
	/*ALGORITMA*/
	Qs=Q;
	if (!IsFullQue(Q))
	{
		while (!IsEmptyQue(Qs))
		{
			Del(&Qs,&ch);
			printf("%c ",ch);
		}
	}
	else
	{
		p=1;
		while (!IsEmptyQue(Qs))
		{
			Del(&Qs,&ch);
			if (p==cr)
			{
				printf(">");
				(*ap)=ch;
			}
			printf("%c ",ch);
			p++;
		}
	}
}

void printactmons(Queue Q, int a, int b, int cr,char *am)
{
	/*KAMUS*/
	char ch;
	int p;
	
	/*ALGORITMA*/
	p=1;
	while (p<=4)
	{
		Del(&Q,&ch);
		if ((p==a || p==b) && cr<p)
		{
			printf("# ");
		}
		else if (cr==p)
		{
			printf(">%c ",ch);
			(*am)=ch;
		}
		else
		{
			printf("%c ",ch);
		}
		p++;
	}
}
 
void inputactuser (Queue *Q)
{
	/*KAMUS*/
	char c,temp;
	
	/*ALGORITMA*/
	scanf(" %c",&c);
	if (c=='E')
	{
		if (!IsEmptyQue(*Q))
		{
			Del(Q,&temp);
		}
	}
		else if (c=='A' || c=='B' || c=='F')
	{
		Add(Q,c);
	}
}
 
int randomdmg (Player P, Enemy M, boolean pmenang)
{
	/*KAMUS*/
	int at,df,dmg;
	
	/*ALGORITMA*/
	if (pmenang)
	{
		at = str(P);
		df = def(M);
	}
	else
	{
		at = str(M);
		df = def(P);
	}
	dmg= (at*4)-(df*3);
	if (dmg<=0)
	{
		dmg=(rand()%13);
	}
	else
	{
		dmg+=(rand()%13);
	}
	return dmg;
}

void cetakbattle (Player P, Enemy M, Queue Qp, Queue Qm, int round, int randa, int randb, int cr,  char *am)
{
	/*ALGORITMA*/
	printf("=======================================================================\n");
	printf("| ");
	PrintNama(name(P));
	printf(" | LVL %d | HP %d | STR %d | DEF %d | Round %d |\n",lvl(P),cHp(P),str(P),def(P),round);
	printf("=======================================================================\n");
	printf("| ");
	PrintNama(name(M));
	printf(" | HP %d | Command ",cHp(M));
	printactmons(Qm,randa,randb,cr,am);
	printf("    |\n");
	printf("=======================================================================\n");
}

