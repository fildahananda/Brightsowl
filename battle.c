#include "stackt.h"
#include "queue.h"
#include "boolean.h"
#include "battle.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_STRING_LEN 20

void battle (Player *P, Enemy *M)
/*KAMUS LOKAL
 *Stack S (untuk mengacak action monster)*/
{
	int round, randa, randb, cr,dmg;
	Queue Qp,Qm;
	Stack S;
	char am,ap;
	time_t t;
	
	srand((unsigned) time(&t));
    randa=((rand()%4)+1);
    do
    {
		randb=((rand()%4)+1);
	}
	while (randb==randa);
	round=1;
	cHp(M)=maxHp(stat(M));
	ReadFileM(&S,move(*M),maxMoves(*M));
	while (hpP>0 && hpM>0 && !IsEmptyStack(S))
	{
		CreateEmpty(&Qp,4);
		Pop(&S,&Qm);
		cr=0;
		while (!IsFull(Qp))
		{
			cetakbattle(P,M,Qp,Qm,round,randa,randb,cr,&am);
			printactuser(Qp,cr,&ap);
			inputactuser(&Qp);
		}
		cr=1;
		while (cr<=4)
		{
			cetakbattle(P,M,Qp,Qm,round,randa,randb,cr,&am);
			printactuser(Q,cr,&ap);
			dmg=randomdmg(P,M,pmenang(ap,am));
			if (pmenang(ap,am)==1)
			{
				cHp(*M)-=dmg;
			}
			else
			{
				cHp(*P)-=dmg;
			}
			
			cr++;
		}
	}
}

void printcomment(Player P, Enemy M,int pmenang, int dmg)
{
	if (pmenang==1)
	{
		printnama(nama(P));
		printf(" menyerang! ");
		printnama(nama(M));
		printf(" terkena %d damage!",dmg);
	}
	else
	{
		printnama(nama(M));
		printf(" menyerang! ");
		printnama(nama(P));
		printf(" terkena %d damage!",dmg);
	}
}

void printmonster()
{
	
}

int pmenang(char ap, char am)
{
	int pm;
	
	if (ap=='A')
	{
		if (am=='A')
		{pm=3;}
		else if (am=='B')
		{pm=2;}
		else if (am=='F')
		{pm=1;}
	}
	else if (ap=='B')
	{
		if (am=='A')
		{pm=1;}
		else if (am=='B')
		{
			pm=3;
		}
		else if (am=='F')
		{
			pm=2;
		}
	}
	else if (ap=='F')
	{
		if (am=='A')
		{pm=2;}
		else if (am=='B')
		{
			pm=1;
		}
		else if (am=='F')
		{
			pm=3;
		}
	}
return pm;
}

void printactuser(Queue Q, int cr, char *ap)
{
	Queue Qs;
	char ch;
	int p;
	
	Qs=Q;
	if (!IsFull(Q))
	{
		while (!IsEmpty(Qs))
		{
			Del(&Qs,&ch);
			printf("%c ",ch);
		}
	}
	else
	{
		p=1;
		while (!IsEmpty(Qs))
		{
			Del(&Qs,&ch);
			if (p==cr)
			{
				printf(">");
				(*ap)=cr;
			}
			printf("%c ",ch);
			p++;
		}
	}
}

void printactmons(Queue Q, int a, int b, int cr,char *am)
{
	Queue Qs;
	char ch;
	int p;
	
	Qs=Q;
	p=1;
	while (!IsEmpty(Qs))
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
	
	CreateEmpty(Q,4);
	while (!IsFull(*Q))
	{
		scanf("%c ",&c);
		if (c=='E')
		{
			if (!IsEmpty(*Q))
			{
				Del(Q,&temp);
			}
		}
		else if (c=='A' || c=='B' || c=='F')
		{
			Add(Q,c);
		}
	}
}
 
int randomdmg (Player P, Enemy M, int pmenang)
/*I.S Menerima data dari monster, player, dan kebenaran apakah player menang atau tidak
 * F.S Menghasilkan nilai damage dan mengurangi HP yang kalah*/
{
	int atk,def,dmg;
	
	if (pmenang!=3)
	{
		if (pmenang==1)
		{
			atk = atk(stat(*P));
			def = def(stat(*M));
		}
		else
		{
			atk = atk(stat(*M));
			def = def(stat(*P));
		}
		dmg = (rand()%30)+(atk*5)-(def*3);
		
	}
	else
	{
		dmg=0;
	}
	return dmg;
}

void cetakbattle (Player P, Enemy M, Queue Qp, Queue Qm, int round, int randa, int randb, int cr,  *char am)
{
	printf("===========================================================================\n");
	printf("|\t%s | LVL %d | HP %d | STR %d | DEF %d | Round %d |\n",name(P),lvl(P),cHp(P),str(stat(P)),def(stat(P)),round);
	printf("===========================================================================\n");
	printf("\t%s | HP %d | Command ",name(M),cHp(M));
	printactmons(Qm,randa,randb,cr,&am);
	printf("        |\n");
}

