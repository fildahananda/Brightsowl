#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	/*KAMUS*/
	IdxType i;
	TabInt TTemp;
	/*ALGORITMA*/
	for (i=IdxMin;i<=IdxMax;i++)
	{
		Elmti(TTemp,i)=ValUndef;
	}
	*T=TTemp;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmti (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	/*KAMUS*/
	int N;
	IdxType i;
	/*ALGORITMA*/
	N=0;
	i=IdxMin;
	while (Elmti(T,i)==ValUndef && i<=IdxMax)
		i++;
	while (Elmti(T,i)!=ValUndef && i<=IdxMax)
	{
		N++;
		i++;
	}
	return N;
}
/* *** Daya tampung container *** */
int MaxNbEli (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return (IdxMax-IdxMin+1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdxi (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	i=IdxMin;
	while (Elmti(T,i)==ValUndef && i<=IdxMax)
		i++;
	return i;
}
IdxType GetLastIdxi (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	i=GetFirstIdxi(T);
	while (Elmti(T,i)!=ValUndef && i<=IdxMax)
		i++;
	i--;
	return i;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidi (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return (i>=IdxMin && i<=IdxMax);
}

boolean IsIdxEffi (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return (i>=GetFirstIdxi(T) && i<=GetLastIdxi(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyi (TabInt T) 
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	i = IdxMin;
	while (i<IdxMax && Elmti(T,i)==ValUndef)
	{
		i++;
	}
	return (Elmti(T,i)==ValUndef);
}
/* *** Test tabel penuh *** */
boolean IsFulli (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	i = IdxMin;
	while (i<IdxMax && Elmti(T,i)!=ValUndef)
	{
		i++;
	}
	return (Elmti(T,i)!=ValUndef);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEli(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEli(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	/*KAMUS*/
	int N,i,j;
	TabInt Temp;
	/*ALGORITMA*/
	MakeEmptyi(T);
	do
		scanf("%d",&N);
	while(N<0 || N>MaxNbEli(Temp));
	if (N>0)
	{
		i=GetFirstIdxi(Temp);
		for (j=1;j<=N;j++)
		{
			
			scanf("%d",&(Elmti(Temp,i)));
			i++;
		}
	}
	*T=Temp;
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	i=GetFirstIdxi(T);
	printf("[");
	while (i<=GetLastIdxi(T))
	{
		if (i==GetLastIdxi(T))
		{
			printf("%d",Elmti(T,i));
		}
		else
		{
			printf("%d,",Elmti(T,i));
		}
		i++;
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	/*KAMUS*/
	TabInt T3;
	IdxType i;
	/*ALGORITMA*/
	i=GetFirstIdxi(T1);
	while (i<=GetLastIdxi(T1))
	{
		if (plus)
		{
			Elmti(T3,i)=Elmti(T1,i)+Elmti(T2,i);
		}
		else
		{
			Elmti(T3,i)=Elmti(T1,i)-Elmti(T2,i);
		}
		i++;
	}
	return T3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	/*KAMUS*/
	IdxType i;
	boolean EQ;
	/*ALGORITMA*/
	if (NbElmti(T1) == NbElmti(T2))
	{
		EQ=true;
		i=GetFirstIdxi(T1);
		while (EQ && i<=GetLastIdxi(T1))
		{
			if (Elmti(T1,i) != Elmti(T2,i))
				EQ=false;
			i++;
		}
	}
	return EQ;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType1 X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	/*KAMUS*/
	boolean found;
	IdxType i;
	/*ALGORITMA*/
	i = GetFirstIdxi(T);
	found = false;
	do
	{
		if (Elmti(T,i)==X)
		{
			found=true;
		}
		else
			i++;
	}
	while (!found && i<=GetLastIdxi(T));
	if (found)
	{
		return i;
	}
	else
	{
		return IdxUndef;
	}
}
boolean SearchB (TabInt T, ElType1 X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
	/*KAMUS*/
	boolean found;
	IdxType i;
	/*ALGORITMA*/
	i=GetFirstIdxi(T);
	found = false;
	while (i<=GetLastIdxi(T) && !(found))
	{
		if (Elmti(T,i) == X)
		{
			found=true;
		}
		i++;
	}
	return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType1 * Max, ElType1 * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	/*KAMUS*/
	ElType1 tmax,tmin;
	IdxType i;
	/*ALGORITMA*/
	tmax = Elmti(T,GetFirstIdxi(T));
	tmin = Elmti(T,GetFirstIdxi(T));
	i=GetFirstIdxi(T);
	while (i<=GetLastIdxi(T))
	{
		if (Elmti(T,i) > tmax)
		{
			tmax = Elmti(T,i);
		}
		if (Elmti(T,i) < tmin)
		{
			tmin = Elmti(T,i);
		}
		i++;
	}
	*Max = tmax;
	*Min = tmin;
}

/* ********** OPERASI LAIN ********** */
ElType1 SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	/*KAMUS*/
	IdxType i;
	ElType1 sum;
	/*ALGORITMA*/
	if (NbElmti(T)==0)
		return 0;
	else
	{
		i=GetFirstIdxi(T);
		sum=0;
		do
		{
			sum+=Elmti(T,i);
			i++;
		}
		while (i<=GetLastIdxi(T));
		return sum;
	}
}
int CountX (TabInt T, ElType1 X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	/*KAMUS*/
	IdxType i;
	int count;
	/*ALGORITMA*/
	if (NbElmti(T)==0)
		return 0;
	else
	{
		i=GetFirstIdxi(T);
		count=0;
		do
		{
			if (Elmti(T,i)==X)
				count++;
			i++;
		}
		while (i<=GetLastIdxi(T));
		return count;
	}
}
	
boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	/*KAMUS*/
	IdxType i;
	boolean genap;
	/*ALGORITMA*/
	i=GetFirstIdxi(T);
	genap = true;
	while (i<=GetLastIdxi(T) && genap)
	{
		if ((Elmti(T,i)%2) != 0)
			genap=false;
		i++;
	}
	return genap;
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc) 
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	/*KAMUS*/
	TabInt Tout;
	IdxType i,imax,pass;
	ElType1 temp;
	/*ALGORITMA*/
	if (asc)
	{
		Tout = *T;
		if (NbElmti(Tout)>1)
		{
			for (pass = (GetFirstIdxi(Tout)); pass<=(GetLastIdxi(Tout));pass++)
			{
				temp = Elmti(Tout,pass);
				i = pass-1;
				while ((temp < Elmti(Tout,i)) && (i>1))
				{
					Elmti(Tout,i+1)=Elmti(Tout,i);
					i--;
				}
				if (temp >= Elmti(Tout,i))
					Elmti(Tout,i+1)= temp;
				else
				{
					Elmti(Tout,i+1)=Elmti(Tout,i);
					Elmti(Tout,i)=temp;
				}
			}
		}
	}
	else
	{
		Tout = *T;
		if (NbElmti(Tout)>1)
		{
			for (pass = GetFirstIdxi(Tout); pass <= (GetLastIdxi(Tout)-1); pass++)
			{
				imax = pass;
				for (i=pass+1;i<=NbElmti(Tout);i++)
				{
					if (Elmti(Tout,imax)<Elmti(Tout,i))
						imax=i;
				}
				temp=Elmti(Tout,imax);
				Elmti(Tout,imax)=Elmti(Tout,pass);
				Elmti(Tout,pass)=temp;
			}
		}
	}
	*T = Tout;
	
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEli (TabInt * T, ElType1 X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	if (NbElmti(*T)==0)
		Elmti(*T,IdxMin)=X;
	else
	{
		i=GetLastIdxi(*T)+1;
		Elmti(*T,i)=X;
	}
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEli (TabInt * T, ElType1 * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	/*KAMUS*/
	IdxType i;
	/*ALGORITMA*/
	i=GetLastIdxi(*T);
	Elmti(*T,i)=ValUndef;
}
