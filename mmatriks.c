#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

int main () {
	MATRIKS M;
	indeks i,j,a,b,y,z;
	
	printf("Ini MakeMATRIKS dengan NB = 3 dan NK = 3 disimpan ke matriks M\n");
	MakeMATRIKS (3,3,&M);
	
	printf("\n");
	
	printf("Ini isi matriks tipe char\n");
	printf("Elmt(M,1,1) = 'T'\n");
	printf("Elmt(M,1,2) = 'B'\n");
	printf("Elmt(M,1,3) = 'K'\n");
	printf("Elmt(M,2,1) = 'A'\n");
	printf("Elmt(M,2,2) = 'J'\n");
	printf("Elmt(M,2,3) = 'B'\n");
	printf("Elmt(M,3,1) = 'B'\n");
	printf("Elmt(M,3,2) = 'G'\n");
	printf("Elmt(M,3,3) = 'W'\n");
	
	Elmt(M,1,1) = 'T';
	Elmt(M,1,2) = 'B';
	Elmt(M,1,3) = 'K';
	Elmt(M,2,1) = 'A';
	Elmt(M,2,2) = 'J';
	Elmt(M,2,3) = 'B';
	Elmt(M,3,1) = 'B';
	Elmt(M,3,2) = 'G';
	Elmt(M,3,3) = 'W';
	
	/*for (i=1; i<=4;i++) {
		for (j=1; j<=4; j++) {
			scanf("%c",&Elmt(M,i,j));
		}
	}*/
	printf("\n");
	printf("Ini TulisMatriks indentasi 5 \n");
	TulisMATRIKS(M,5);
	
	printf("\n");
	/*
	printf("Banyaknya elemen matriks M = ", NBElmt(M));
	printf("\n");
	printf("Indeks baris terkecil matriks M = ", GetFirstIdxBrs (M));
	printf("\n");
	printf("Indeks kolom terkecil matriks M = ", GetFirstIdxKol (M));
	printf("\n");
	printf("Indeks baris terbesar matriks M = ", GetLastIdxBrs (M));
	printf("\n");
	printf("Indeks kolom terbesar matriks M = ", GetLastIdxKol (M));
	printf("\n");
	
	printf("\n");
	printf("Ini mencari keberadaan suatu nilai bertipe char 'A' berada di baris dan kolom berapa\n");
	SearchElmt(M, 'A', &a,&b);
	y=a;
	z=b;
	printf("Char 'A' berada di baris = \n", y);
	printf("Char 'A' berada di kolom = \n", z);
	*/
	return 0;
}
