/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "boolean.h"
#include "queue.h"
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQue (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (NBElmtQue(Q)==0);
}
boolean IsFullQue (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
{
	return (NBElmtQue(Q) == MaxElQ);
}
int NBElmtQue (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	/* KAMUS */
	int temp;
	/* ALGORITMA */
	if (Head(Q) < TailQ(Q))
	{
		temp = TailQ(Q) - Head(Q)+1;
	}
	else if (Head(Q) == TailQ(Q))
	{
		if (Head(Q) == Nill)
		{
			temp = 0;
		}
		else
		{
			temp = 1;
		}
	}
	else
	{
		temp = (MaxElQ - Head(Q)) + TailQ(Q)+1;
	}
	return temp;
}

/* *** Kreator *** */
void CreateEmptyQue (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */
{
	/* KAMUS */
	
	/* ALGORITMA */
	(*Q).T = (infotypeq *) malloc ((Max+1) * sizeof(infotypeq));
	if ((*Q).T != NULL)
	{
		Head(*Q) = Nill;
		TailQ(*Q) = Nill;
	}
}

/* *** Destruktor *** */
void DeAlokasiQue(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */
{
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotypeq X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika TailQ(Q)=MaxElQ+1 maka geser isi tabel, shg Head(Q)=1 */
{
	if (IsEmptyQue(*Q))
	{
		Head(*Q)=1;
		TailQ(*Q)=1;
	}
	else if (TailQ(*Q) == MaxElQ)
	{
		TailQ(*Q) = 1;
	}
	else
	{
		TailQ(*Q)++;
	}
	InfoTail(*Q) = X;
}
void Del(Queue * Q, infotypeq * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju";Q mungkin kosong */
{
	*X = InfoHead(*Q);
	if (NBElmtQue(*Q) == 1)
	{
		Head(*Q) = Nill;
		TailQ(*Q) = Nill;
	}
	else if (Head(*Q) == MaxElQ)
	{
		Head(*Q) = 1;
	}
	else
	{
		Head(*Q)++;
	}
	
}

