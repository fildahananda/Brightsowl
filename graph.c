#include "graph.h"
#include <stdlib.h>
/* PROTOTYPE */
/****************** TEST GRAF KOSONG ******************/
boolean IsEmptyGraph (Graph G)
/* Mengirim true jika graf kosong.*/
{
	return (G==Nil);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyGraph (Graph *G)
/* I.S. L sembarang  */
/* F.S. Terbentuk graf kosong. Lihat definisi di atas. */
{
	*G=Nil;
}
/****************** Manajemen Memori ******************/
addrGraf AlokasiGraph (infograf X)
/* Mengirimkan addrGraf hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraf tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	addrGraf P;
	P=(addrGraf) malloc (sizeof(ElmtGraph));
	if (P!=Nil)
	{
		InfoGraf(P)=X;
		Kanan(P)=Nil;
		Kiri(P)=Nil;
	}
	return P;
}
void DealokasiGraph (addrGraf P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraf P */
{
	free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addrGraf SearchGraf (Graph G, infograf X)
{
	addrGraf P;
	P=G;
	boolean found=false;
	while((!found)&&(P!=Nil))
	{
		if(InfoGraf(P)==X)
		{
			found=true;
		}
		else
		{
			P=Kanan(P);
		}
	}
	return P;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertKanan (Graph *G, infograf Y)
{
	addrGraf P,Pt;
	P=AlokasiGraph(Y);
	Pt=*G;
	if(Pt!=Nil)
	{
		while(Kanan(Pt)!=Nil)
		{
			Pt=Kanan(Pt);
		}
		Kanan(P)=Kanan(Pt);
		Kanan(Pt)=P;
		Kiri(P)=Pt;
	}else
	{
		*G=P;
	}
}

void InsertKiri (Graph *G, infograf Y)
{
	addrGraf P,Pt;
	P=AlokasiGraph(Y);
	Pt=*G;
	if(Pt!=Nil)
	{
			Kiri(P)=Kiri(Pt);
			Kiri(Pt)=P;
			Kanan(P)=Pt;
	}else
	{
		*G=P;
	}
}