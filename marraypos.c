#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

int main () {
	TabInt T;
	IdxType a,b;
	ElType1 X;
	
	printf("Ini sudah MakeEmptyi\n");
	MakeEmptyi(&T);
	
	printf("\n");
	
	printf("Asumsi isi array 10 (inputkan 10), lalu masukkan elemen2nya\n");
	BacaIsi(&T);
	printf("\nIni isi array T\n");
	TulisIsiTab(T);
	
	printf("\n");
	printf("\n");
	
	a=GetFirstIdxi (T);
	b=GetLastIdxi (T);
	printf("GetFirstIdxi : %d \n",a);
	printf("GetLastIdxi : %d \n",b);
	
	printf("\n");
	printf("Ini Searching (elemen = 3)\n");
	if (SearchB (T, 3)) {
		printf("Ada elemen %d didalam Array T\n",3);
	} else {
		printf("Tidak ada elemen %d didalam Array T\n",3);
	}
	
	printf("\n");
	
	printf("Ini AddAsLastEli\n");
	AddAsLastEli (&T,4);
	printf("Menambahkan elemen terakhir array T dengan angka 4\n");
	TulisIsiTab(T);
	return 0;
}
