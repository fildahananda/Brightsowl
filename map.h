#ifndef MAP_H
#define MAP_H

#include "boolean.h"
#include "graph.h"
#include "matriks.h"
#include "point.h"
#include "mesinkata.h"
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999
/* Indeks tak terdefinisi*/
typedef int IdxType;  /* type indeks */
typedef struct { 
	MATRIKS Mat;
	int Pintu;
	POINT P1;
	POINT P2;
} ElTypeMap;
typedef struct {
	ElTypeMap TI[IdxMax+1]; /* memori tempat penyimpan map (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
} Tab;

typedef struct { 
	Tab ArrMap;
	Graph Graf;
} Map;

#define Mat(M)			(M).Mat
#define NeffMap(M)		((M).ArrMap).Neff
#define ElmtMap(M,i)	((M).ArrMap).TI[i]
#define SmallMap(M,i)	(ElmtMap(M,i)).Mat //MATRIKS
#define Graf(M)			(M).Graf      //GRAPH
#define P1(M,i)			(ElmtMap(M,i)).P1 //POINT
#define P2(M,i)			(ElmtMap(M,i)).P2 //POINT
#define Pintu(M,i)		(ElmtMap(M,i)).Pintu //INT
void MakeNewSmall(int in, int Baris, int Kolom, int P, Map *M, indeks ordinat, indeks absis);
/* I.S. in adalah InfoGraf untuk menyimpan map, Baris dan Kolom adalah dimensi dari map, P adalah jumlah pintu,
		ordinat dan absis adalah pintu dari map sebelumnya 
   F.S. Sebuah matriks map ditambahkan ke M sebagai sambungan map yang telah ada*/
void RandomNext(MATRIKS M,indeks b, indeks k, indeks *b1, indeks *k1);
/* I.S. M adalah matriks map kecil yang digunakan untuk menentukan batasan random, b dan k adalah indeks sebelum random
   F.S. b1 dan k1 adalah hasil random yang membentuk area di dekat indeks b,k*/
void MakeMap(int Baris, int Kolom, int N, Map *P);
/* I.S. Baris dan Kolom adalah ukuran map, N adalah jumlah map kecil yang akan dibuat
   F.S. P adalah Map yang telah terbentuk dari N matriks map berukuran BarisxKolom*/
void RandomEnemy (Map *M);
/* I.S. Map M adalah map yang telah dibuat di MakeMap 
   F.S. Sejumlah Enemy ditempatkan diarea map yang dapat dijangkau pemain*/
void SimpanMap(Map *M, char filename[]);
/* I.S. Map M berisi map yang telh dibuat atau telah dimainkan 
   F.S. Map M disimpan di file "filename"*/
void BacaMap (Map *M,char filename[]);
/* I.S. Map *M kosong/terisi 
   F.S. Mengisi Map M dari file "filename" yang telah dibaca*/
 #endif