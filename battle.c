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


void battle (Player *P, Enemy *M, boolean *menang)
/*KAMUS LOKAL
 *Stack S (untuk mengacak action monster)*/
{
	int round, randa, randb, cr;
	Queue Qp,Qm;
	Stack S;
	char am,ap,nu;
	time_t t;
	
	srand((unsigned) time(&t));
    randa=((rand()%4)+1);
    do
    {
		randb=((rand()%4)+1);
	}
	while (randb==randa);
	round=1;
	cHp(*M)=maxHp(*M);
	ReadFileM(&S,move(*M),maxm(*M));
	while (cHp(*P)>0 && cHp(*M)>0 && !IsEmptyStack(S))
	{
		CreateEmptyQue(&Qp,4);
		Pop(&S,&Qm);
		cr=0;
		while (!IsFullQue(Qp))
		{
			printnama((*M).stat.name);
			printf(" attacked!\n");
			cetakbattle(*P,*M,Qp,Qm,round,randa,randb,cr,&am);
			printf("Inputted command: ");
			printactuser(Qp,cr,&ap);
			printf("\n");
			printf("Input command : ");
			inputactuser(&Qp);
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
	printf("ehe");
	if (cHp(*M)<=0)
	{
		(*menang)=true;
	}
	else
	{
		(*menang)=false;
	}
}

void printcomment(Player *P, Enemy *M,char ap, char am)
{
	int dmg;
	
	if (ap=='A')
	{
		if (am=='B')
		{
			printnama((*P).stat.name);
			printf(" attacked! But ");
			printnama((*M).stat.name);
			printf(" blocked!");
		}
		else if (am=='A')
		{
			printnama((*P).stat.name);
			printf(" tries to attack! But ");
			printnama((*M).stat.name);
			printf(" evaded!");
		}
		else if (am=='F')
		{
			dmg=randomdmg(*P,*M,true);
			printnama((*P).stat.name);
			printf(" attacked! ");
			printnama((*M).stat.name);
			printf(" -%d HP",dmg);
			cHp(*M)-=dmg;
		}
	}
	else if (ap=='B')
	{
		if (am=='A')
		{
			printnama((*M).stat.name);
			printf(" attacked! But ");
			printnama((*P).stat.name);
			printf(" blocked!");
		}
		else if (am=='B')
		{
			printnama((*P).stat.name);
			printf(" Blocked. ");
			printnama((*M).stat.name);
			printf(" blocked too. Nothing happened.");
		}
		else if (am=='F')
		{
			dmg=randomdmg(*P,*M,false);
			printnama((*P).stat.name);
			printf(" blocked! but ");
			printnama((*M).stat.name);
			printf(" is too strong. HP-%d",dmg);
			cHp(*P)-=dmg;
		}
	}
	else if (ap=='F')
	{
		if (am=='B')
		{
			dmg=randomdmg(*P,*M,true);
			printnama((*M).stat.name);
			printf(" blocked! but ");
			printnama((*P).stat.name);
			printf(" is too strong. HP-%d",dmg);
			cHp(*M)-=dmg;
		}
		else if (am=='F')
		{
			printnama((*P).stat.name);
			printf(" and ");
			printnama((*M).stat.name);
			printf(" both flocked. Nothing happened.");
		}
		else if (am=='A')
		{
			dmg=randomdmg(*P,*M,false);
			printnama((*M).stat.name);
			printf(" attacked! ");
			printnama((*P).stat.name);
			printf(" -%d HP",dmg);
			cHp(*P)-=dmg;
		}
	}
	printf("\n");
	printf("Push enter to continue\n");
	getchar();
}

void printnama(Name A)
{
	int i;
	
	for (i=0; i<=A.length; i++)
	{
		printf("%c",A.tabName[i]);
	}
}




void printactuser(Queue Q, int cr, char *ap)
{
	Queue Qs;
	char ch;
	int p;
	
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
	char ch;
	int p;
	
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
/*I.S Menerima aksi user
 *F.S Memasukkan aksi user pada round*/
{
	char c,temp;
	
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
/*I.S Menerima data dari monster, player, dan kebenaran apakah player menang atau tidak
 * F.S Menghasilkan nilai damage dan mengurangi HP yang kalah*/
{
	int at,df;
	
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
		return ((rand()%13)+(at*4)-(df*3));
}

void cetakbattle (Player P, Enemy M, Queue Qp, Queue Qm, int round, int randa, int randb, int cr,  char *am)
{
	printf("=======================================================================\n");
	printf("| ");
	printnama(P.stat.name);
	printf(" | LVL %d | HP %d | STR %d | DEF %d | Round %d |\n",lvl(P),cHp(P),str(P),def(P),round);
	printf("=======================================================================\n");
	printf("| ");
	printnama(M.stat.name);
	printf(" | HP %d | Command ",cHp(M));
	printactmons(Qm,randa,randb,cr,am);
	printf("    |\n");
	printf("=======================================================================\n");
}

