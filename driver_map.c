#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h" 

void TampilanMap(Player *P, Map *M, int ind);


int main()
{
	Map M,MT;

	int i;
	Posisi P;
	Player PL;
	addrGraf AdrG;
	char C1,C2;
	
	MakeMap(15,30,5,&M);
	printf("Sudah bikin map baris=15, kolom=30\n");

	//MakeNewSmall(1,20,40,1,&M,10,1);
	//TulisMATRIKS(SmallMap(M,InfoGraf(AdrG)));

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
	/*for(i=1;i<=6;i++){*/

	/*
	MakeNewSmall(1,20,40,1,&M,10,1);
	printf("Ini MakeNewSmall\n");
	*/
	
	/*ReadCommand(&P,&AdrG,&M);
	system("cls");
	}*/
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
	printf("Map sudah disimpan, bisa langsung cek di map.txt\n");
	printf("\n");
	/*
	printf("Map Terbaca\n");
	BacaMap(&M,"map.txt");
	printf("\n");*/
	/*for(i=1;i<=NeffMap(M);i++)
	{
		TulisMATRIKS(SmallMap(M,i),5);
		printf("\n\n");
	}*/
	printf("Mengecek apakah map sudah tercetak random\n");
	MakeMap(15,30,5,&MT);
	printf("Sudah bikin map baris=15, kolom=30\n");

	
	SimpanMap(&MT,"maps.txt");
	printf("Map sudah disimpan, bisa langsung cek di maps.txt\n");
	printf("\n");

	printf("Membuat map yg berisi jd kosong\n");
	MakeEmptyMap(&MT);
	SimpanMap(&MT,"mapl.txt");
	printf("Map sudah disimpan, bisa langsung cek di mapl.txt MAP kosong\n");
	printf("\n");
	/*MakeEmptyMap(&MT);
	printf("Map sudah kosong\n");
	*/

	return 0;
}
