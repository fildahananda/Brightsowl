/* NIM				: 13515019 */
/* Nama				: Candra Hesen Parera */
/* Tanggal			: 31 Agustus 2016 */
/* Topik praktikum	: ADT */
/* Deskripsi		: MAIN ADT POINT */
/* File: mpoint.c */

#include "point.h"
#include <stdio.h>
#include "boolean.h"

int main() {
	/* KAMUS */
	POINT EP, P, P1, P2, CP, Pa;
	float deltaX, deltaY;
	
	/* ALGORITMA */
	printf("Ini contoh MakePOINT\n");
	EP = MakePOINT(2,5);
	printf("<%d,%d>\n",EP);
	
	printf("\n");
	/* Test Baca dan Tulis */
	printf("Ini BacaPOINT\n");
	printf("Masukkan nilai absis dan ordinat (contoh: 2 5) : \n");
	BacaPOINT(&P);
	printf("\nIni TulisPOINT\n");
	printf("Titik yang dibaca ");
	TulisPOINT(P);
	
	printf("\n");
	printf("\n");
		
	/* Test keberadaan POINT */
	printf("Ini cek keberadaan POINT (IsOrigin,IsOnSbx,IsOnSby,Kuadran)\n");
	int a;
	/*printf("Masukkan POINT yang akan dicek : \n");
	BacaPOINT(&CP);*/
	a = Kuadran(P);

	if (IsOrigin(P)) {
		printf("POINT terletak di titik origin \n");
	}
	else if (IsOnSbX(P)) {
			printf("POINT terletak pada sumbu X \n");
	}
	else if (IsOnSbY(P)) {
			printf("POINT terletak pada sumbu Y \n");
	}
	else {
		printf("POINT berada di kuadran = %d ", a);
	}
	
	printf("\n");
	printf("\n");
	
	/* Test operasi lain terhadap type */
	/* test next point x*/
	printf("Ini NextX, NextY\n");
	POINT i, j;
	printf("Masukkan POINT (Pa) \n");
	BacaPOINT(&Pa);
	i = NextX(Pa);
	j = NextY(Pa);
	printf("nilai POINT baru setelah absisnya(x) ditambah 1 : (%d,%d) \n", Absis(i), Ordinat(i));
	printf("nilai POINT baru setelah ordinatnya(y) ditambah 1 : (%d,%d) \n", Absis(j), Ordinat(j));
	printf("nilai POINT baru setelah absisnya(X) dan ordinatnya(y) ditambah 1 : (%d,%d) \n", Absis(i), Ordinat(j));
	
	printf("\n");
	
	POINT tot;
	printf("Ini PlusDelta\n");
	printf("Masukkan penambahan deltaX dan deltaY (dalam float) \n");
	scanf("%f %f", &deltaX, &deltaY);
	tot = PlusDelta ( Pa, deltaX, deltaY);
	printf("nilai POINT baru setelah penambahan absis dan ordinat (nilai penambahan dibulatkan) : (%d,%d) \n", Absis(tot), Ordinat(tot));
	
	printf("\n");

	/*test mirror  */
	printf("Ini MirrorOf\n");
	boolean bol;
	POINT Pb, cermin;
	bol = true;
	printf("Masukkan POINT (Pb) \n");
	BacaPOINT(&Pb);
	cermin = MirrorOf (Pb, bol);
	printf("nilai POINT baru setelah pencerminan (ini true) : (%d,%d) \n",Absis(cermin), Ordinat(cermin));
	
	printf("\n");
	
	/* test jarak */
	printf("Ini tes jarak\n");
	POINT Pc;
	float jar;
	printf("Masukkan POINT (Pc) \n");
	BacaPOINT(&Pc);
	jar = Jarak0 (Pc);
	printf("Jarak POINT ke titik (0,0) : %0.0f \n", jar);
	
	printf("\n");
	
	/* test panjang 8 */
	printf("Ini tes panjang\n");
	float panjang1;
	// point diambil dari P dan P1
	printf("Nilai POINT diambil dari Pb dan Pc\n");
	panjang1 = Panjang(P, Pc);
	printf("Panjangnya = %.2f\n", panjang1);
	
	printf("\n");
	
	printf("Ini tes GeserKeSbY\n");
	GeserKeSbY(&Pc);
	printf("Nilai POINT diambil dari Pc\n");
	printf("Pc setelah digeser ke SbY = "); TulisPOINT(Pc);
	
	printf("\n");	
	printf("\n");
	
	printf("Ini tes GeserKeSbX\n");
	GeserKeSbY(&Pb);
	printf("Nilai POINT diambil dari Pb\n");
	printf("Pb setelah digeser ke SbY = "); TulisPOINT(Pb);
	
	printf("\n");	
	printf("\n");
	
	/* test geser point absis sebesar delta x dan ordinat sebesar delta y*/
	printf("Ini tes Geser\n");
	POINT Pd ;
	printf("Masukkan POINT (Pd) \n");
	BacaPOINT(&Pd);
	printf("Masukkan penambahan deltaX dan deltaY dalam float \n");
	scanf("%f %f", &deltaX, &deltaY);
	Geser(&Pd, deltaX, deltaY);
	printf("nilai POINT setelah digeser sebesar deltaX dan deltaY : ");
	TulisPOINT(Pd);
	
	printf("\n");
	
	/* test putar */
	printf("\nIni tes Putar\n"); 
	POINT Pe ;
	printf("Masukkan POINT (Pe) \n");
	BacaPOINT(&Pe);
	float angle;
	printf("nilai POINT diambil dari Pe, angle = 30.0\n");
	Putar (&Pe, 30.0);
	printf("Setelah digeser = "); TulisPOINT(Pe);
	printf("\n");

	
	return 0;
	
}
