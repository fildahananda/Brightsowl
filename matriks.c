/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */
/* NIM  : 13515109 */
/* Nama : Harum Lokawati */
#include "matriks.h"
#include "boolean.h"
#include <stdio.h>

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) //pake
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M)=NB;
    NKolEff(*M)=NK;
}
/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return (BrsMin+NBrsEff(M)-1);
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return (KolMin+NKolEff(M)-1);
}

void SearchElmt(MATRIKS M, char X, indeks *Brs, indeks *Kol)
{
	int i=GetFirstIdxBrs(M);
	int j=GetFirstIdxKol(M);
	boolean found;
	found=false;
	*Brs=0; *Kol=0;
	while((i<=GetLastIdxBrs(M))&&(!found))
	{
			while((j<=GetLastIdxKol(M))&&(!found))
			{
				if(Elmt(M,i,j)==X)
				{
					found=true;
					*Brs=i;
					*Kol=j;
				}
				j++;
			}
			i++;
	}
}
/* *** Selektor "DUNIA MATRIKS" *** */
void TulisMATRIKS (MATRIKS M, int n) //pake
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks i,j,k;
    for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
    {
		for(k=1;k<=n;k++)
		{
			printf(" ");
		}
        for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
        {
            if (i==GetLastIdxBrs(M))
            {
                if (j==GetLastIdxKol(M))
                {
					if(Elmt(M,i,j)=='B')
					{
						printf("E\n");
					}else
					{
					    printf("%c\n",Elmt(M,i,j));	
					}
                }
                else
                {
                    if(Elmt(M,i,j)=='B')
					{
						printf("E");
					}else
					{
					    printf("%c",Elmt(M,i,j));	
					}
                }
            }
            else
            {
                if (j==GetLastIdxKol(M))
                {
                    if(Elmt(M,i,j)=='B')
					{
						printf("E\n");
					}else
					{
					    printf("%c\n",Elmt(M,i,j));	
					}
                }
                else
                {
                    if(Elmt(M,i,j)=='B')
					{
						printf("E");
					}else
					{
					    printf("%c",Elmt(M,i,j));	
					}
                }
            }

        }
    }
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    int tot;
    tot=(NBrsEff(M))*(NKolEff(M));
    return tot;
}
