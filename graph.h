#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "boolean.h"

#define Nil NULL
typedef int infograf;
typedef struct tElmtGraph *addrGraf;
typedef struct tElmtGraph{
    infograf info;
	addrGraf kanan;
	addrGraf kiri;
} ElmtGraph;

typedef addrGraf Graph;

/* Notasi Akses */
#define InfoGraf(P) (P)->info
#define Kiri(P) (P)->kiri
#define Kanan(P) (P)->kanan

/* PROTOTYPE */
/****************** TEST GRAF KOSONG ******************/
boolean IsEmptyGraph (Graph G);
/* Mengirim true jika graf kosong.*/
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyGraph (Graph *G);
/* I.S. L sembarang  */
/* F.S. Terbentuk graf kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addrGraf AlokasiGraph (infograf X);
/* Mengirimkan addrGraf hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrGraf tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void DealokasiGraph (addrGraf P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrGraf P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
addrGraf SearchGraf (Graph G, infograf X);

void InsertKanan (Graph *G, infograf Y);


void InsertKiri (Graph *G, infograf Y);
#endif