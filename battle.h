#ifndef battle_H
#define battle_H

#include "stackt.h"
#include "queue.h"
#include "boolean.h"


void battle (Stack stackm);
/*KAMUS LOKAL
 *Stack S (untuk mengacak action monster)*/

void printactmons(Queue Q, int a, int b, int cr,char *am);
/*I.S Menerima Queue aksi monster
 * F.S Menampilkan aksi monster dengan disembunyikan dua dari empat aksi*/

int pmenang(char ap, char am);
 
void printactuser(Queue Q, int cr, char *ap);
/*I.S Menerima aksi user
 *F.S Memasukkan aksi user pada round*/
 
void printactuser (Queue Q);

int randomdmg (Player *P, Enemy *M, int pmenang);
/*I.S Menerima data dari monster, player, dan kebenaran apakah player menang atau tidak
 * F.S Menghasilkan nilai damage dan mengurangi HP yang kalah*/

void cetakbattle (Player P, Enemy M, Queue Qp, Queue Qm, int round, int randa, int randb, int cr, char *ap, *char am);
#endif
