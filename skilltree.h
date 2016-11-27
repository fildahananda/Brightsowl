//
//  skilltree.h
//  player
//
//  Created by Richard Matthew on 11/14/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#ifndef skilltree_h
#define skilltree_h
#include "boolean.h"
#include <stdio.h>


/* Modul lain yang digunakan : */
#include "boolean.h"

#define Nil NULL

/* *** Definisi Type Pohon Biner *** */
typedef struct {
    int idx;
    char type;
    char opr;
    int rate;
    boolean unlock;
} infotype;
typedef struct tNode *addrNode;
typedef struct tNode {
    infotype info;
    addrNode left;
    addrNode right;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

#define Idx(S) (S).idx
#define Type(S) (S).type
#define Opr(S) (S).opr
#define Unlock(S) (S).unlock
#define Rate(S) (S).rate

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

/* Manajemen Memory */
addrNode AlokNode (infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
 maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode (addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt (BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

boolean IsAvailable ( BinTree P, int idx);

/* *** Traversal *** */
void PrintUnlock (BinTree P);

void PrintLock (BinTree P);

void PrintSkill (BinTree P, boolean cek);

void PrintAvailableSkill (BinTree P);

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

boolean SearchTreeIdx (BinTree P, int X);

BinTree SearchAdrIdx (BinTree P, int X);

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun (BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */

/* *** Operasi lain *** */
void ConstructTree (BinTree *P, infotype X);

void AddDaunAfter (BinTree *P, int X, infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu indeks dari node pada Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
 sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */


#endif /* skilltree_h */
