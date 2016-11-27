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

boolean IsAvailable ( BinTree P, int idx)
{
    if (idx == Idx(Akar(P)))
    {
        return (!Unlock(Akar(P)));
    }
    else
    {
        if(!(IsTreeOneElmt(P)))
        {
            if(IsBiner(P))
            {
                return ((IsAvailable(Left(P), idx) || IsAvailable(Right(P), idx)));
            }
            else
            {
                if (IsUnerLeft(P))
                {
                    return IsAvailable(Left(P), idx);
                }
                else
                {
                    return IsAvailable(Right(P), idx);
                }
            }
        }
        else
        {
            return false;
        }
    }
}

/* *** Traversal *** */
void PrintUnlock (BinTree P)
{
    if (Unlock(Akar(P)))
    {
    printf("Skill yang sudah diaktifkan:\n");
    PrintSkill(P, true);
    }
    else
    {
        printf("Belum ada skill yang aktif\n");
    }
}
void PrintLock (BinTree P)
{
    printf("Skill yang belum diaktifkan:\n");
    PrintSkill(P, false);
}

void PrintSkill (BinTree P, boolean cek)
{
    if(Unlock(Akar(P)) == cek)
    {
        switch (Type(Akar(P)))
        {
            case 'h':
            case 'H':
            {
                printf("HP ");
                break;
            }
            case 's':
            case 'S':
            {
                printf("STR ");
                break;
            }
            case 'd':
            case 'D':
            {
                printf("DEF ");
            }
            default:
                break;
        }
        printf("%c%d\n", Opr(Akar(P)), Rate(Akar(P)));
    }
    if(!(IsTreeOneElmt(P)))
    {
        if (IsBiner(P))
        {
            PrintSkill(Left(P), cek);
            PrintSkill(Right(P), cek);
            
        }
        else
        {
            if(IsUnerLeft(P))
            {
                PrintSkill(Left(P), cek);
            }
            else
            {
                PrintSkill(Right(P), cek);
            }
        }
        
    }
}

void PrintAvailableSkill (BinTree P)
{
    if (!(Unlock(Akar(P))))
    {
        printf("%d ",Idx(Akar(P)));
        switch (Type(Akar(P)))
        {
            case 'h':
            case 'H':
            {
                printf("HP ");
                break;
            }
            case 's':
            case 'S':
            {
                printf("STR ");
                break;
            }
            case 'd':
            case 'D':
            {
                printf("DEF ");
            }
            default:
                break;
        }
        printf("%c%d\n", Opr(Akar(P)), Rate(Akar(P)));
    }
    else
    {
        if(!(IsTreeOneElmt(P)))
        {
            if(IsBiner(P))
            {
                PrintAvailableSkill(Left(P));
                PrintAvailableSkill(Right(P));
            }
            else
            {
                if (IsUnerLeft(P))
                {
                    PrintAvailableSkill(Left(P));
                }
                else
                {
                    PrintAvailableSkill(Right(P));
                }
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

BinTree SearchAdrIdx (BinTree P, int X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if ((IsTreeEmpty(P)) || (!SearchTreeIdx(P, X)))
    {
        return Nil;
        
    }
    else
    {
        if (Idx(Akar(P)) == X)
        {
            return P;
        }
        else
        {
            
            if (IsTreeOneElmt(P))
            {
                return Nil;
            }
            else
            {
                if (SearchTreeIdx(Left(P), X))
                {
                    return SearchAdrIdx(Left(P), X);
                }
                else
                {
                    return SearchAdrIdx(Right(P),X);
                }
            }
        }
    }
}

/* *** Operasi lain *** */

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
            *P= Tree(X, Nil, Nil);
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











































