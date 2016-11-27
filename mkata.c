/* NIM				: 13515019 */
/* Nama				: Candra Hesen Parera */
/* Topik praktikum	: ADT */
/* Deskripsi		: MAIN ADT MESINKATA */
/* File: mainkata.c */

#include "mesinkata.h"
#include "mesinkar.h"
#include <stdio.h>

int main() {
	int i;
	STARTKATA("isicobakata.txt");
	if (EndKata) {
		printf("Ekspresi kosong\n");
	}
	while (!EndKata) {
		IgnoreBlank();
		for (i=1;i<=CKata.Length;i++) {
			printf("%c",CKata.TabKata[i]);
		}
		printf("\n");
		printf("%d\n",CKata.Length);
		ADVKATA(); 
	}
	return 0;
}
