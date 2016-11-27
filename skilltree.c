//
//  skilltree.c
//  player
//
//  Created by Richard Matthew on 11/14/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#include "skilltree.h"

#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>

/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan
 karena melibatkan modul list rekursif. */

///* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */
//
///* *** Definisi Type Pohon Biner *** */
///* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
//typedef struct tNode *addrNode;
//typedef struct tNode {
//    infotype info;
//    addrNode left;
//    addrNode right;
//} Node;
//
///* Definisi PohonBiner : */
///* Pohon Biner kosong : P = Nil */
//typedef addrNode BinTree;
//
///* *** PROTOTYPE *** */
//
///* *** Selektor *** */
//#define Akar(P) (P)->info
//#define Left(P) (P)->left
//#define Right(P) (P)->right
//

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R){
    /* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
    /* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
    BinTree temp;
    
    temp = AlokNode(Akar);
    if (temp != Nil)
    {
        Left(temp) = L;
        Right(temp) = R;
    }
    
    return temp;
    
}
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
 jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
    
    *P = Tree(Akar, L, R);
    
    
}
/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
 maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode P;
    
    P = (addrNode) malloc ((1)*sizeof(Node));
    if (P !=Nil)
    {
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    
    return P;
}
void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P == Nil);
}

boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (IsTreeEmpty(P))
    {
        return false;
    }
    else{
        return ((Left(P) == Nil) && (Right(P) == Nil));
    }
}
boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else
    {
        if ((Right(P) == Nil) && (Left(P) != Nil))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
}
boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else
    {
        if ((Right(P) != Nil) && (Left(P) == Nil))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    return ((Left(P)!= Nil) && (Right(P) != Nil ));
}
/* *** Traversal *** */
//void PrintPreorder (BinTree P)
///* I.S. P terdefinisi */
///* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
// Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
// Pohon kosong ditandai dengan ().
// Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
///* Contoh:
// (A()()) adalah pohon dengan 1 elemen dengan akar A
// (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
//{
//    printf("(");
//    if (!(IsTreeEmpty(P)))
//    {
//        printf("%d",Akar(P));
//        PrintPreorder(Left(P));
//        PrintPreorder(Right(P));
//    }
//    
//    printf(")");
//    
//}
//void PrintInorder (BinTree P)
///* I.S. P terdefinisi */
///* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
// Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
// Pohon kosong ditandai dengan ().
// Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
///* Contoh:
// (()A()) adalah pohon dengan 1 elemen dengan akar A
// ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
//{
//    printf("(");
//    if (!(IsTreeEmpty(P)))
//    {
//        PrintInorder(Left(P));
//        printf("%d",Akar(P));
//        PrintInorder(Right(P));
//    }
//    
//    printf(")");
//    
//}
//void PrintPostorder (BinTree P)
///* I.S. P terdefinisi */
///* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
// Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
// Pohon kosong ditandai dengan ().
// Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
///* Contoh:
// (()()A) adalah pohon dengan 1 elemen dengan akar A
// ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
//{
//    printf("(");
//    if (!(IsTreeEmpty(P)))
//    {
//        PrintPostorder(Left(P));
//        PrintPostorder(Right(P));
//        printf("%d",Akar(P));
//    }
//    
//    printf(")");
//    
//}
//
void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
 1) Pohon preorder: (A()()) akan ditulis sbb:
 A
 2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
 A
 B
 C
 3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
 A
 B
 D
 C
 E
 */
{
    int i;
    
    if (!IsTreeEmpty(P))
    {
        printf("%d\n",Idx(Akar(P)));
        if(!IsTreeOneElmt(P))
        {
            if(Left(P)!=Nil)
            {
                for (i=0;i<h;i++)
                {
                    printf(" ");
                }
                PrintTree(Left(P), h*2);
            }
            if(Right(P)!=Nil)
            {
                for (i=0;i<h;i++)
                {
                    printf(" ");
                }
                PrintTree(Right(P), h*2);
            }
        }
    }
}

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P))
    {
        return false;
        
    }
    else
    {
        if (IsTreeOneElmt(P))
        {
            return (Idx(Akar(P)) == Idx(X));
        }
        else
        {
            if (Idx(Akar(P)) == Idx(X))
            {
                return true;
            }
            else
            {
                return ((SearchTree(Left(P), X)) || (SearchTree(Right(P), X)));
            }
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        return (NbElmt(Left(P)) + NbElmt(Right(P))+ 1);
    }
}
int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeOneElmt(P))
    {
        return 1;
    }
    else
    {
        int total;
        total = 0;
        
        if (Left(P) != Nil)
        {
            total = total + NbDaun(Left(P));
        }
        if (Right(P) != Nil)
        {
            total = total + NbDaun(Right(P));
        }
        return total;
    }
}

//boolean IsSkewLeft (BinTree P)
///* Mengirimkan true jika P adalah pohon condong kiri */
///* Pohon kosong adalah pohon condong kiri */
//{
//    if (IsTreeEmpty(P))
//    {
//        return true;
//    }
//    else
//    {
//        if (Right(P) != Nil)
//        {
//            return false;
//        }
//        else
//        {
//            return (IsSkewLeft(Left(P)));
//        }
//    }
//}
//boolean IsSkewRight (BinTree P)
///* Mengirimkan true jika P adalah pohon condong kanan */
///* Pohon kosong adalah pohon condong kanan */
//{
//    if (IsTreeEmpty(P))
//    {
//        return true;
//    }
//    else
//    {
//        if (Left(P) != Nil)
//        {
//            return false;
//        }
//        else
//        {
//            return (IsSkewRight(Right(P)));
//        }
//    }
//}

int Level (BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
 Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
{
    if (IsTreeOneElmt(P) || Idx(Akar(P)) == Idx(X))
    {
        return 1;
    }
    else
    {
        if (SearchTree(Left(P), X))
        {
            return (1 + (Level(Left(P), X)));
        }
        else
        {
            return (1 + (Level(Right(P), X)));
        }
    }
}
int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
 Mengirim "height" yaitu tinggi dari pohon */
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        int l;
        int r;
        l = (1+ Tinggi(Left(P)));
        r = (1+ Tinggi(Right(P)));
        if (l>=r)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
}
/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    if (IsTreeEmpty(*P))
    {
        *P = AlokNode(X);
    }
    else
    {
        AddDaunTerkiri(&Left(*P), X);
    }
}
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
 sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    if (IsTreeOneElmt(*P)&&(Idx(Akar(*P)) == Idx(X)))
    {
        if (Kiri)
        {
            Left(*P) = AlokNode(Y);
        }
        else
        {
            Right(*P) = AlokNode(Y);
        }
    }
    else
    {
        if (SearchTree(Left(*P), X))
        {
            AddDaun(&(Left(*P)), X, Y, Kiri);
        }
        else
        {
            AddDaun(&(Right(*P)), X, Y, Kiri);
        }
    }
}
void DelDaunTerkiri (BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
 disimpan pada daun terkiri yang dihapus */
{
    if (IsTreeOneElmt(*P))
    {
        *X = Akar(*P);
        *P=Nil;
        DealokNode(*P);
    }
    else
    {
        if (IsUnerLeft(*P))
        {
            DelDaunTerkiri(&(Left(*P)), X);
        }
        else
        {
            DelDaunTerkiri(&(Right(*P)), X);
        }
    }
}
void DelDaun (BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
    if (IsTreeOneElmt(*P) && (Idx(Akar(*P)) == Idx(X)))
    {
        *P = Nil;
        DealokNode(*P);
    }
    else
    {
        if (SearchTree(Left(*P), X))
        {
            DelDaun(&Left(*P), X);
        }
        
        if (SearchTree(Right(*P), X))
        {
            DelDaun(&Right(*P), X);
        }
    }
}

boolean SearchTreeIdx (BinTree P, int X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P))
    {
        return false;
        
    }
    else
    {
        if (IsTreeOneElmt(P))
        {
            return (Idx(Akar(P)) == X);
        }
        else
        {
            if (Idx(Akar(P)) == X)
            {
                return true;
            }
            else
            {
                return ((SearchTreeIdx(Left(P), X)) || (SearchTreeIdx(Right(P), X)));
            }
        }
    }
}


void AddDaunAfter (BinTree *P, int X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
 sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    if (Idx(Akar(*P)) == X)
    {
        if (Kiri)
        {
            Left(*P) = AlokNode(Y);
        }
        else
        {
            Right(*P) = AlokNode(Y);
        }
    }
    else
    {
        if (SearchTreeIdx(Left(*P), X))
        {
            AddDaunAfter(&(Left(*P)), X, Y, Kiri);
        }
        else
        {
            AddDaunAfter(&(Right(*P)), X, Y, Kiri);
        }
    }
}

void ConstructTree (BinTree *P, infotype X)
{
    switch (Idx(X)) {
        case 1:
        {
            *P = AlokNode(X);
            Left(*P) = Nil;
            Right(*P) = Nil;
            break;
        }
        case 2:
        {
            AddDaunAfter(P, 1, X, true);
            break;
        }
        case 3:
        {
            AddDaunAfter(P, 1, X, false);
            break;
        }
        case 4:
        {
            AddDaunAfter(P, 2, X, true);
            break;
        }
        case 5:
        {
            AddDaunAfter(P, 2, X, false);
            break;
        }
        case 6:
        {
            AddDaunAfter(P, 3, X, true);
            break;
        }
        case 7:
        {
            AddDaunAfter(P, 3, X, false);
            break;
        }
        case 8:
        {
            AddDaunAfter(P, 4, X, true);
            break;
        }
        case 9:
        {
            AddDaunAfter(P, 4, X, false);
            break;
        }
        case 10:
        {
            AddDaunAfter(P, 5, X, true);
            break;
        }
        case 11:
        {
            AddDaunAfter(P, 5, X, false);
            break;
        }
        case 12:
        {
            AddDaunAfter(P, 6, X, true);
            break;
        }
        case 13:
        {
            AddDaunAfter(P, 6, X, false);
            break;
        }
        case 14:
        {
            AddDaunAfter(P, 7, X, true);
            break;
        }
        case 15:
        {
            AddDaunAfter(P, 7, X, false);
            break;
        }
        default:
            break;
    }
}
