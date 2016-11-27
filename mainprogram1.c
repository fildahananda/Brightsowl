#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <conio.h>
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "mesinkata.h"
#include "point.h"

void MainProgram (boolean *exit, Player *P, Map *M, boolean *logged);
void TampilanMainMenu();
void MainMenu(Kata *comm, Kata *NG, Kata *SG, Kata *LG, Kata *EX, Kata *BACK);
void NewGame(Player *P, Map *M, boolean *logged, boolean *exit);
void StartGame(Player *P, Map *M, Kata *comm,Kata NG, Kata LG, Kata BACK,boolean *logged, boolean *exit);
void LoadGame(Player *P, Map *M, boolean *logged, boolean *exit);
void Game(Player *P, Map *M, boolean *exit, boolean *logged);
Posisi SearchPosisi(Map M);
void RandomPosisi(Map *M, int i,Posisi *P);
void MoveUp(Posisi *P, Map *M, char *Elmt);
void MoveDown(Posisi *P, Map *M, char *Elmt);
void MoveRight(Posisi *P, Map *M, char *Elmt);
void MoveLeft(Posisi *P, Map *M, char *Elmt);
void TampilanMap(Player *P, Map *M, int ind);
void PrintKata(Kata K);
boolean IsKataSama (Kata K1, Kata K2);
void ReadCommandMap(Posisi *Pos, Player *P, Map *M, boolean *exit, boolean *logged, char *Elmt);
//void wait(int seconds);
int main()
{
	boolean exit=false;
	Player P;
	Map M;
	//LoadEnemy();
	boolean logged=false;
	CreateEmptyPlayer(&P);
	MakeEmptyMap(&M);
	while(!exit)
	{
		MainProgram(&exit,&P,&M,&logged);
	}
return 0;
}
void MainProgram (boolean *exit, Player *P, Map *M, boolean *logged)
{
	system("cls");
	Kata command, NG, SG, LG, EX,BACK;
	MainMenu(&command,&NG,&SG,&LG,&EX,&BACK);
	if(IsKataSama(NG,command))
	{
		NewGame(P,M,logged,exit);
	}else if(IsKataSama(SG,command))
	{
		StartGame(P,M,&command,NG,LG,BACK,logged,exit);
	}else if(IsKataSama(LG,command))
	{
		LoadGame(P,M,logged,exit);
	}else if(IsKataSama(EX,command))
	{
		*exit=true;
	}
}
void TampilanMainMenu()
{
	printf(" -----------------------------------------------------------------------------------------\n");
	printf("|                                          MAIN MENU                                      |\n");
	printf(" -----------------------------------------------------------------------------------------\n");
	printf(" ------------------------------------      NEW GAME      ---------------------------------\n");
	printf(" ------------------------------------      START GAME    ---------------------------------\n");
	printf(" ------------------------------------      LOAD GAME     ---------------------------------\n");
	printf(" ------------------------------------      EXIT          ---------------------------------\n");
	printf(" -----------------------------------------------------------------------------------------\n");
	printf(" *berikan command nama menu untuk memilih\n");
}
void MainMenu(Kata *comm, Kata *NG, Kata *SG, Kata *LG, Kata *EX, Kata *BACK)
{
	TampilanMainMenu();
	char C;
	(*BACK).Length = 4;
	(*BACK).TabKata[1] = 'B';
	(*BACK).TabKata[2] = 'A';
	(*BACK).TabKata[3] = 'C';
	(*BACK).TabKata[4] = 'K';
	
	(*NG).Length = 8;
	(*NG).TabKata[1] = 'N';
	(*NG).TabKata[2] = 'E';
	(*NG).TabKata[3] = 'W';
	(*NG).TabKata[4] = ' ';
	(*NG).TabKata[5] = 'G';
	(*NG).TabKata[6] = 'A';
	(*NG).TabKata[7] = 'M';
	(*NG).TabKata[8] = 'E';
	
	(*SG).Length=10;
	(*SG).TabKata[1] = 'S';
	(*SG).TabKata[2] = 'T';
	(*SG).TabKata[3] = 'A';
	(*SG).TabKata[4] = 'R';
	(*SG).TabKata[5] = 'T';
	(*SG).TabKata[6] = ' ';
	(*SG).TabKata[7] = 'G';
	(*SG).TabKata[8] = 'A';
	(*SG).TabKata[9] = 'M';
	(*SG).TabKata[10]= 'E';
	
	(*LG).Length=9;
	(*LG).TabKata[1] = 'L';
	(*LG).TabKata[2] = 'O';
	(*LG).TabKata[3] = 'A';
	(*LG).TabKata[4] = 'D';
	(*LG).TabKata[5] = ' ';
	(*LG).TabKata[6] = 'G';
	(*LG).TabKata[7] = 'A';
	(*LG).TabKata[8] = 'M';
	(*LG).TabKata[9] = 'E';
	
	(*EX).Length=4;
	(*EX).TabKata[1] = 'E';
	(*EX).TabKata[2] = 'X';
	(*EX).TabKata[3] = 'I';
	(*EX).TabKata[4] = 'T';
	boolean benar=false;
	while(!benar)
	{
		printf("Command: ");
		scanf("%c",&C);
		int i=0;
		while(C!='\n')
		{
			i++;
			(*comm).TabKata[i]=C;
			scanf("%c",&C);
		}
		(*comm).Length=i;
		if((IsKataSama(*NG,*comm))||(IsKataSama(*SG,*comm))||(IsKataSama(*LG,*comm))||(IsKataSama(*EX,*comm)))
		{
			benar=true;
		}else
		{
			printf("Command tidak sesuai, input kembali\n");
		}
	}
}
void NewGame(Player *P, Map *M, boolean *logged, boolean *exit)
{
	char Command,C;
	Posisi Pos;
	addrGraf Adr;
	printf("Username sebelumnya akan terhapus? Lanjutkan? Y or N\n");
	scanf("%c",&Command);
	scanf("%c",&C);
	if(Command=='Y')
	{
		LoadNewPlayer(P);
		MakeMap(15,30,5,M);
		RandomPosisi(M,1,&Pos);
		SimpanMap(M,"map.txt");
		*logged=true;
		printf("Start Game? Y or N\n");
		scanf("%c",&Command);
		scanf("%c",&C);
		if(Command=='Y')
		{
			Game(P,M,exit,logged);
		}else
		{
			MainProgram(exit,P,M,logged);
		}
	}else
	{
		MainProgram(exit,P,M,logged);
	}
}
void StartGame(Player *P, Map *M, Kata *comm,Kata NG, Kata LG, Kata BACK,boolean *logged, boolean *exit)
{
	char C;
	if(logged)
	{
		Game(P,M,exit,logged);
	}else
	{
		printf(" ------------------------------------      NEW GAME?     ---------------------------------\n");
		printf(" ------------------------------------      LOAD GAME?    ---------------------------------\n");
		printf(" ------------------------------------      BACK?         ---------------------------------\n");
		boolean benar=false;
		while(!benar)
		{
			printf("Command: ");
			scanf("%c",&C);
			int i=0;
			while(C!='\n')
			{
				i++;
				(*comm).TabKata[i]=C;
				scanf("%c",&C);
			}
			(*comm).Length=i;
			if((IsKataSama(NG,*comm))||(IsKataSama(LG,*comm))||(IsKataSama(BACK,*comm)))
			{
				benar=true;
			}else
			{
				printf("Command tidak sesuai, input kembali\n,");
			}
		}
		if(IsKataSama(NG,*comm))
		{
			NewGame(P,M,logged,exit);
		}else if(IsKataSama(LG,*comm))
		{
			NewGame(P,M,logged,exit);
		}else if(IsKataSama(BACK,*comm))
		{
			MainProgram(exit,P,M,logged);
		}
	}
}
void LoadGame(Player *P, Map *M, boolean *logged, boolean *exit)
{
	LoadSavedPlayer(P);
	BacaMap(M,"map.txt");
	printf("LOADING FINISHED!!");
	*logged=true;
	printf("Start Game? Y or N");
	char Command;
	scanf("%c",&Command);
		if(Command=='Y')
		{
			Game(P,M,exit,logged);
		}else
		{
			MainProgram(exit,P,M,logged);
		}
}

void Game(Player *P, Map *M, boolean *exit, boolean *logged)
{
	Posisi Pos;
	Enemy E;
	boolean gameover=false;
	int hasil;
	char Elmt;
	*exit=false;
	printf("LETS PLAY ");
	PrintNama(name(*P));
	printf("\n");
	Area(Pos)=SearchGraf(Graf(*M),1);
	SearchElmt(SmallMap(*M,1),'P',&Ordinat(Titik(Pos)),&Absis(Titik(Pos)));
	printf("Pos:%d %d\n",Ordinat(Titik(Pos)),Absis(Titik(Pos)));
	//Pos=SearchPosisi(*M);
	//printf("telah dicari\n");
	while((!gameover)&&(!(*exit)))
	{
		TampilanMap(P,M,InfoGraf(Area(Pos)));
        ReadCommandMap(&Pos,P,M,exit,logged,&Elmt);
		printf("Pos:%d %d\n",Ordinat(Titik(Pos)),Absis(Titik(Pos)));
		if((Elmt=='E')||(Elmt=='B'))
		{
			printf("Oh there's a monster here, Let's Battle\n");
			//wait(1);
			system("cls");
			if(Elmt=='E')
			{
				GetEnemy(&E,lvl(*P),exp(*P));
			}else
			{
				printf("THE BOSS IS COMING\n");
				GetBoss(&E,lvl(*P),exp(*P));
			}
			battle(P,&E,&hasil);
			//switch (hasil){
			//	case 1: Menang(); break;
			//	case 2: Kalah(); break;
			//	case 3: Seri(); break;
			//	default: GameOver(); gameover=true; break;
			}
		}
}

Posisi SearchPosisi(Map M)
{
	Posisi P;
	boolean found=false;
	indeks Brs,Kol;
	printf("dicari\n");
	int i=1;
	while((i<=NeffMap(M))&&(!found))
	{
		SearchElmt(SmallMap(M,i),'P',&Brs,&Kol);
		printf("telah dicari\n");
		if((Brs!=0)&&(Kol!=0))
		{
			found=true;
			Ordinat(Titik(P))=Brs;
			Absis(Titik(P))=Kol;
			//Area(P)=SearchGraf(Graf(M),i);
		}
		i++;
	}
	return P;
}
void RandomPosisi(Map *M, int i,Posisi *P)
{
	srand(time(NULL));
	boolean cocok=false;
	Area(*P)=SearchGraf(Graf(*M),i);
	Ordinat(Titik(*P))=rand()%NBrsEff(SmallMap(*M,i))+1;
	Absis(Titik(*P))=rand()%NKolEff(SmallMap(*M,i))+1;
	while(cocok==false)
	{
		if(Elmt(SmallMap(*M,i),Ordinat(Titik(*P)),Absis(Titik(*P)))=='-')
		{
			cocok=true;
		}else{
			Ordinat(Titik(*P))=rand()%NBrsEff(SmallMap(*M,i))+1;
			Absis(Titik(*P))=rand()%NKolEff(SmallMap(*M,i))+1;
		}
	}
	Elmt(SmallMap(*M,i),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
}

void MoveUp(Posisi *P, Map *M, char *Elmt)
{
	if(Ordinat(Titik(*P))==1)
	{
		printf("You cannot go upside\n");
	}else if (Elmt(SmallMap(*M,InfoGraf(Area(*P))),(Ordinat(Titik(*P))-1),Absis(Titik(*P)))=='#')
	{
		printf("You cannot go upside\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='-';
		Ordinat(Titik(*P))--;
		*Elmt=Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)));
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
	}
}
void MoveDown(Posisi *P, Map *M,char *Elmt)
{
	if(Ordinat(Titik(*P))==NBrsEff(SmallMap(*M,InfoGraf(Area(*P)))))
	{
		printf("You cannot go downside side\n");
	}else if (Elmt(SmallMap(*M,InfoGraf(Area(*P))),(Ordinat(Titik(*P))+1),Absis(Titik(*P)))=='#')
	{
		printf("You cannot go downside side\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='-';
		Ordinat(Titik(*P))++;
		*Elmt=Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)));
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
	}
}

void MoveRight(Posisi *P, Map *M, char *Elmt)
{
	if(Absis(Titik(*P))==NKolEff(SmallMap(*M,InfoGraf(Area(*P)))))
	{
		if(Kanan(Area(*P))!=Nil)
		{
			Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='-';
			Area(*P)=Kanan(Area(*P));
			Titik(*P)=P1(*M,InfoGraf(Area(*P)));
			*Elmt=Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)));
			Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
		}else
		{
			printf("You cannot go to the right side\n");
		}
	}else if (Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),(Absis(Titik(*P))+1))=='#')
	{
		printf("You cannot go to the right side\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='-';
		Absis(Titik(*P))++;
		*Elmt=Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)));
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
		
	}
}

void MoveLeft(Posisi *P, Map *M, char *Elmt)
{
	if(Absis(Titik(*P))==1)
	{
		if(Kiri(Area(*P))!=Nil)
		{
			Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='-';
			Area(*P)=Kiri(Area(*P));
			Titik(*P)=P2(*M,InfoGraf(Area(*P)));
			*Elmt=Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)));
			Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
		}else
		{
			printf("You cannot go to the left side\n");
		}
	}else if (Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),(Absis(Titik(*P))-1))=='#')
	{
		printf("You cannot go to the left side\n");
	}else
	{
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='-';
		Absis(Titik(*P))--;
		*Elmt=Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)));
		Elmt(SmallMap(*M,InfoGraf(Area(*P))),Ordinat(Titik(*P)),Absis(Titik(*P)))='P';
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
void ReadCommandMap(Posisi *Pos, Player *P, Map *M, boolean *exit, boolean *logged, char *Elmt) {
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
		MoveUp(Pos,M,Elmt);
		
	} else if (IsKataSama(comm, GODO)) {
		MoveDown(Pos,M,Elmt);
	
	} else if (IsKataSama(comm, GOLE)) {
		MoveLeft(Pos,M,Elmt);
	
	} else if (IsKataSama(comm, GORI)) {
		MoveRight(Pos,M,Elmt);
	
	} else if (IsKataSama(comm, SKL)) {
		PrintUnlock(skill(*P));
        PrintLock(skill(*P));
		printf("ketik Y untuk tutup:");
		scanf("%c",&C);
	} else if (IsKataSama(comm, SVE)) {
		SimpanMap(M,"map.txt");
		SimpanPlayer(P,"savedplayer.txt");
		printf("SAVED!!!\n");
		//wait(1);
	} else if (IsKataSama(comm, LO)) {
		LoadSavedPlayer(P);
	} else if (IsKataSama(comm, EX)) {
		*exit=true;
	}
}
//void wait(int seconds)
//{
//	clock_t tunggu;
//	tunggu=clock()+seconds*CLOCKS_PER_SEC;
//	while(clock() <tunggu){}
//}
