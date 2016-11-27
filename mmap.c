#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h" 
typedef POINT Posisi;
void RandomPosisi(Map *M, int i, addrGraf *Adr,Posisi *P);
void Move(char C,Posisi *P, addrGraf *CMap, Map *M);
void MoveUp(Posisi *P, addrGraf *CMap, Map *M);
void MoveDown(Posisi *P, addrGraf *CMap, Map *M);
void MoveRight(Posisi *P, addrGraf *CMap, Map *M);
void MoveLeft(Posisi *P, addrGraf *CMap, Map *M);
void TampilanMap(Player *P, Map *M, int ind);
void PrintKata(Kata K);
boolean IsKataSama (Kata K1, Kata K2);
void ReadCommand(Posisi *P, addrGraf *CMap, Map *M);
int main()
{
Map M;
int i;
Posisi P;
Player PL;
addrGraf AdrG;
char C1,C2;
MakeMap(15,30,5,&M);
printf("Sudah bikin map\n");
RandomPosisi(&M,1,&AdrG,&P);
printf("Absis P:%d, Ordinat P:%d, Map ke:%d\n",Absis(P),Ordinat(P),InfoGraf(AdrG));
//MakeNewSmall(1,20,40,1,&M,10,1);
//TulisMATRIKS(SmallMap(M,InfoGraf(AdrG)));
printf("%d\n",InfoGraf(AdrG));
lengthName(PL)=5;
tabName(PL)[1]='B';
tabName(PL)[2]='O';
tabName(PL)[3]='C';
tabName(PL)[4]='A';
tabName(PL)[5]='N';
lvl(PL)=1;
cHp(PL)=100;
str(PL)=10;
def(PL)=50;
exp(PL)=99;
printf("berhasil inisiasi\n");
for(i=1;i<=6;i++){
	TampilanMap(&PL,&M,InfoGraf(AdrG));
ReadCommand(&P,&AdrG,&M);
system("cls");
}
/*for(i=1;i<=5;i++)
{
	TulisMATRIKS(SmallMap(M,i));
	printf("\n\n");
}*/
/*BacaMap(&M);
for (i=1;i<=NeffMap(M);i++)
{
		TulisMATRIKS(SmallMap(M,i));
}*/
SimpanMap(&M,"map.txt");
BacaMap(&M,"map.txt");
/*for(i=1;i<=NeffMap(M);i++)
{
	TulisMATRIKS(SmallMap(M,i),5);
	printf("\n\n");
}*/
return 0;
}

void RandomPosisi(Map *M, int i, addrGraf *Adr,Posisi *P)
{
	srand(time(NULL));
	boolean cocok=false;
	*Adr=SearchGraf(Graf(*M),i);
	Ordinat(*P)=rand()%NBrsEff(SmallMap(*M,i))+1;
	Absis(*P)=rand()%NKolEff(SmallMap(*M,i))+1;
	while(cocok==false)
	{
		if(Elmt(SmallMap(*M,i),Ordinat(*P),Absis(*P))=='-')
		{
			cocok=true;
		}else{
			Ordinat(*P)=rand()%NBrsEff(SmallMap(*M,i))+1;
			Absis(*P)=rand()%NKolEff(SmallMap(*M,i))+1;
		}
	}
	Elmt(SmallMap(*M,i),Ordinat(*P),Absis(*P))='P';
}

void Move(char C,Posisi *P, addrGraf *CMap, Map *M)
{
	if(C=='u')
	{
		MoveUp(P,CMap,M);
	}else if(C=='d')
	{
		MoveDown(P,CMap,M);
	}else if(C=='r')
	{
		MoveRight(P,CMap,M);
	}else if(C=='l')
	{
		MoveLeft(P,CMap,M);
	}
}

void MoveUp(Posisi *P, addrGraf *CMap, Map *M)
{
	if(Ordinat(*P)==1)
	{
		printf("You cannot go upside\n");
	}else if (Elmt(SmallMap(*M,InfoGraf(*CMap)),(Ordinat(*P)-1),Absis(*P))=='#')
	{
		printf("You cannot go upside\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='-';
		Ordinat(*P)--;
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='P';
	}
}
void MoveDown(Posisi *P, addrGraf *CMap, Map *M)
{
	if(Ordinat(*P)==NBrsEff(SmallMap(*M,InfoGraf(*CMap))))
	{
		printf("You cannot go downside side\n");
	}else if (Elmt(SmallMap(*M,InfoGraf(*CMap)),(Ordinat(*P)+1),Absis(*P))=='#')
	{
		printf("You cannot go downside side\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='-';
		Ordinat(*P)++;
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='P';
	}
}

void MoveRight(Posisi *P, addrGraf *CMap, Map *M)
{
	if(Absis(*P)==NKolEff(SmallMap(*M,InfoGraf(*CMap))))
	{
		if(Kanan(*CMap)!=Nil)
		{
			Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='-';
			*CMap=Kanan(*CMap);
			*P=P1(*M,InfoGraf(*CMap));
			Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='P';
		}else
		{
			printf("You cannot go to the right side\n");
		}
	}else if (Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),(Absis(*P)+1))=='#')
	{
		printf("You cannot go to the right side\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='-';
		Absis(*P)++;
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='P';
		
	}
}

void MoveLeft(Posisi *P, addrGraf *CMap, Map *M)
{
	if(Absis(*P)==1)
	{
		if(Kiri(*CMap)!=Nil)
		{
			Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='-';
			*CMap=Kiri(*CMap);
			*P=P2(*M,InfoGraf(*CMap));
			Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='P';
		}else
		{
			printf("You cannot go to the left side\n");
		}
	}else if (Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),(Absis(*P)-1))=='#')
	{
		printf("You cannot go to the left side\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='-';
		Absis(*P)--;
		Elmt(SmallMap(*M,InfoGraf(*CMap)),Ordinat(*P),Absis(*P))='P';
	}
}

void TampilanMap(Player *P, Map *M, int ind)
{
	int i,p;
	//printf("l:%d, nkol:%d\n",lengthName(P),NKolEff(SmallMap(M,ind)));
	p=(lengthName(*P)+NKolEff(SmallMap(*M,ind))+29);
	for(i=1;i<=p;i++)
	{
		printf("-");
	}
	printf("\n");
	printf("  ");
	for(i=1;i<=lengthName(*P);i++)
	{
		printf("%c",tabName(*P)[i]);
	}
	printf("  |");
	printf("  LVL:%d  |",lvl(*P));
	printf("  HP:%d  |",cHp(*P));
	printf("  STR:%d  |",str(*P));
	printf("  DEF:%d  |",def(*P));
	printf("  EXP:%d  |\n",exp(*P));
	for(i=1;i<=p;i++)
	{
		printf("-");
	}
	printf("\n");
	TulisMATRIKS(SmallMap(*M,ind),(lengthName(*P)+17));
	for(i=1;i<=p;i++)
	{
		printf("-");
	}
	printf("\n");
	
}

void PrintKata(Kata K)
{
	int i;
	for(i=1;i<K.Length;i++)
	{
		printf("%c",K.TabKata[i]);
	}
}

boolean IsKataSama (Kata K1, Kata K2) {
	int i;
	if (K1.Length != K2.Length) {
		return false;
	} else {
		i = 1;
		while ((i<K1.Length) && (K1.TabKata[i] == K2.TabKata[i])) {
			i++;
		}
		return (K1.TabKata[i] == K2.TabKata[i]) ;
	
	} 

}
void ReadCommand(Posisi *P, addrGraf *CMap, Map *M) {
/* comm merupakan inputan dari pemain */
	Kata comm;
	char C;
	Kata GOUP;
	
	GOUP.Length = 2;
	GOUP.TabKata[1] = 'G';
	GOUP.TabKata[2] = 'U';
		
	Kata GODO;
	
	GODO.Length = 2;
	GODO.TabKata[1] = 'G';
	GODO.TabKata[2] = 'D';
	
	Kata GOLE;
	
	GOLE.Length = 2;
	GOLE.TabKata[1] = 'G';
	GOLE.TabKata[2] = 'L';
	
	Kata GORI;
	
    GORI.Length = 2;
    GORI.TabKata[1] = 'G';
    GORI.TabKata[2] = 'R';
    
	Kata SKL;
	
    SKL.Length = 5;
    SKL.TabKata[1] = 'S';
    SKL.TabKata[2] = 'K';
    SKL.TabKata[3] = 'I';
    SKL.TabKata[4] = 'L';
    SKL.TabKata[5] = 'L';

	Kata SVE;
	
    SVE.Length = 4;
    SVE.TabKata[1] = 'S';
    SVE.TabKata[2] = 'A';
    SVE.TabKata[3] = 'V';
    SVE.TabKata[4] = 'E';
    
    Kata LO;
	
    LO.Length = 4;
    LO.TabKata[1] = 'L';
    LO.TabKata[2] = 'O';
    LO.TabKata[3] = 'A';
    LO.TabKata[4] = 'D';
    
    Kata EX;
	
    EX.Length = 4;
    EX.TabKata[1] = 'E';
    EX.TabKata[2] = 'X';
    EX.TabKata[3] = 'I';
    EX.TabKata[4] = 'T';

	printf("Command: ");
	scanf("%c",&C);
	int i=0;
	while(C!='\n')
	{
		i++;
		comm.TabKata[i]=C;
		scanf("%c",&C);
	}
	comm.Length=i;
	if (IsKataSama(comm, GOUP)) {
		MoveUp(P,CMap,M);
		
	} else if (IsKataSama(comm, GODO)) {
		MoveDown(P,CMap,M);
	
	} else if (IsKataSama(comm, GOLE)) {
		MoveLeft(P,CMap,M);
	
	} else if (IsKataSama(comm, GORI)) {
		MoveRight(P,CMap,M);
	
	} else if (IsKataSama(comm, SKL)) {
		printf("SKILl Tampil\n");
		
	} else if (IsKataSama(comm, SVE)) {
		SimpanMap(M,"map.txt");
	
	} else if (IsKataSama(comm, LO)) {
		printf("SAMPAI KETEMU LAGI\n");
		printf("DATA TERSIMPAN\n");
		
	} else if (IsKataSama(comm, EX)) {

	}
}