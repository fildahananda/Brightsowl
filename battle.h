//ADT BATTLE
//MENANGANI BATTLE USER DENGAN ENEMY

#ifndef battle_H
#define battle_H

#include "stackt.h"
#include "queue.h"
#include "boolean.h"
#include "enemy.h"
#include "stat.h"
#include "player.h"


void battle (Player *P, Enemy *M, int *menang, int *rnd);
/*I.S. Menerima variabel Player dan Enemy 
 * F.S. Membuat tampilan battle dan mengolah perhitungan damage*/

void printactmons(Queue Q, int a, int b, int cr,char *am);
/*I.S Menerima Queue aksi monster
 * F.S Menampilkan aksi monster dengan disembunyikan dua dari empat aksi*/
 
void printactuser(Queue Q, int cr, char *ap);
/*I.S Menerima aksi user
 *F.S Memasukkan aksi user pada round*/
 
 
void inputactuser (Queue *Q);
/*I.S Menerima masukan aksi user
 * F.S. Memasukkan aksi user ke Queue*/


void printcomment(Player *P, Enemy *M,char ap, char am);
/*I.S. Menerima masukan aksi player dan monster saat itu
 * F.S. Menampilkan comment pada battle*/

int randomdmg (Player P, Enemy M, boolean pmenang);
/*I.S Menerima data dari monster, player, dan kebenaran apakah player menang atau tidak
 * F.S Menghasilkan nilai damage dan mengurangi HP yang kalah*/

void cetakbattle (Player P, Enemy M, Queue Qp, Queue Qm, int round, int randa, int randb, int cr, char *am);
/*I.S. Menerima parameter-parameter untuk mencetak tampilan battle
 * F.S. Menampilkan tampilan battle secara umum */
#endif
