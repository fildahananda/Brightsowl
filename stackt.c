/* File : stackt.h */
/* NAMA		: Lathifah Nurrahmah */
/* NIM		: 13515046 */
/* TOPIK	: STACK */
/* DESKRIPSI: Realisasi ADT stack */

#include "stackt.h"
#include "boolean.h"
#include "arraypos.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nill */
{
	/*KAMUS*/
	
	/*ALGORITMA*/
	Top(*S) = Nill;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	/*KAMUS*/
	
	/*ALGORITMA*/
	return (Top(S) == Nill);
}
boolean IsFullStack (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	/*KAMUS*/
	
	/*ALGORITMA*/
	return (Top(S) == MaxElS);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotypes X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	/*KAMUS*/
	
	/*ALGORITMA*/
	Top(*S)++;
	InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotypes* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	/*KAMUS*/
	
	/*ALGORITMA*/
	*X = InfoTop(*S);
	Top(*S)--;
}

void ReadFileM (Stack *S, Queue *TQ,int l)
{
	int i;
	TabInt p;
	int n,q;
	time_t t;
	
	
	srand((unsigned) time(&t));
	MakeEmptyi(&p);
	for (i=1; i<=(l); i++)
	{
		q=rand();
		n=((q%l)+1);
		while (SearchB(p,n))
		{
			q=rand();
			n=(q%l)+1;
		}
		AddAsLastEli(&p,n);
	}
	CreateEmptyStack(S);
	i=GetFirstIdxi(p);
	while (!IsFullStack(*S) && i<=GetLastIdxi(p))
	{
		Push(S, TQ[Elmti(p,i)]);
		i++;
	}
}
