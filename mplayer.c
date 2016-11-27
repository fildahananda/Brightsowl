#include <stdio.h>
#include "skilltree.h"
#include "player.h"
#include <stdlib.h>

/*
#include "stat.h"
#include "mesinkata.h"
*/

int main () {
	Player P;
	
	printf("Ini sudah CreateEmptyPlayer P\n");
	CreateEmptyPlayer(&P);
	
	printf("\n");
	
	printf("Ini LoadNewPlayer P\n");
	LoadNewPlayer(&P);
	
	printf("\n");
	
	printf("Ini PrintNama\n");
	PrintNama(name(P));
	
	printf("\n");
	
	printf("Ini PrintInfoPlayer\n");
	PrintInfoPlayer(&P);
	printf("\n");
		
	AddExp(&P, 1, 22);
	printf("Ini sudah penambahan EXP. Dengan bertambahnya EXP mencapai maks maka level naik\n");
	printf("\n");
	PrintInfoPlayer(&P);
	printf("\n");
	
	printf("SUdah disimpan di file eks\n");
	SimpanPlayer(&P,"infoplayer.txt");
	printf("\n");

	return 0;
}
