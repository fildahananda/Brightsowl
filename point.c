/* NIM		: 13515109 */
/* Nama		: Harum Lokawati */

#include "point.h"
#include "boolean.h"
#include <math.h>
#include <stdio.h>


/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	POINT P;
	Absis(P)=X;
	Ordinat(P)=Y;
	return P;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT *P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	int A,O;
	scanf("%d %d",&A,&O);
	*P=MakePOINT(A,O);
}
void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
{
	printf("(%d,%d)",Absis(P),Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
	return ((Absis(P)==0)&&(Ordinat(P)==0));
}
boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	return (Ordinat(P)==0);
}
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	return (Absis(P)==0);
}
int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
	int A,O;
	A=Absis(P);
	O=Ordinat(P);

	if ((A>0)&&(O>0))
	{
		return 1;
	}
	else if ((A<0)&&(O>0))
	{
		return 2;
	}
	else if ((A<0)&&(O<0))
	{
		return 3;
	}
	else return 4;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	POINT P1;
	Absis(P1)=Absis(P)+1;
	Ordinat(P1)=Ordinat(P);
	return P1;
}
POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	POINT P1;
	Absis(P1)=Absis(P);
	Ordinat(P1)=Ordinat(P)+1;
	return P1;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	POINT P1;
	Absis(P1)=Absis(P)+deltaX;
	Ordinat(P1)=Ordinat(P)+deltaY;
	return P1;
}
POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	POINT P1;
	if (SbX)
	{
		Absis(P1)=Absis(P);
        if (Ordinat(P)==0)
        {
            Ordinat(P1)=Ordinat(P);
        }
		else Ordinat(P1)=Ordinat(P)*(-1);
	}
	else
	{
        Ordinat(P1)=Ordinat(P);
	    if (Absis(P)==0)
        {
            Absis(P1)=Absis(P);
        }
		else Absis(P1)=Absis(P)*(-1);
	}
	return (P1);
}
float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
	int A,O;
	float jrk;
	A=Absis(P);
	O=Ordinat(P);
	jrk=pow( (pow(A,2) + pow(O,2)) , (0.5));
	return(jrk);
}
float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
{
	int A1,A2,O1,O2;
	float jrk;
	A1=Absis(P1); O1=Ordinat(P1);
	A2=Absis(P2); O2=Ordinat(P2);
	jrk=(pow( (pow((A2-A1),2) + pow((O2-O1),2)) , (0.5)) );
	return jrk;
}
/* Tuliskan spec fungsi yang lebih tepat. */
void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	POINT P1;
	P1=PlusDelta(*P,deltaX,deltaY);
	*P=P1;
}
void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
	POINT P1;
	Ordinat(P1)=0;
	Absis(P1)=Absis(*P);
	*P=P1;
}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
	POINT P1;
	Ordinat(P1)=Ordinat(*P);
	Absis(P1)=0;
	*P=P1;
}
void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
	POINT P1;
	P1=MirrorOf(*P,SbX);
	*P=P1;
}


void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
	float rad, s, c;
	POINT P1;
	rad=Sudut*(0.0174533);
	s=sin(rad); c=cos(rad);
	Absis(P1)=(Absis(*P)*c) - (Ordinat(*P)*s);
	Ordinat(P1)=(Ordinat(*P)*c) + (Absis(*P)*s);
	*P=P1;
}

