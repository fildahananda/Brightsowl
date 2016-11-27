#include "boolean.h"
#include <stdio.h>
#include "skilltree.h"
#include <stdlib.h>

int main () {
	BinTree T;
    infotype S;
    int i, x;

    
    Idx(S) = 1;
    Type(S)= 'h';
    Opr(S)= '+';
    Unlock(S) = true;
    
    Rate(S) = 10;

    
    for (i=1; i<=3; i++)
    {
        ConstructTree(&T, S);
        Idx(S)++;
    }
    boolean cek = Unlock(S);
    PrintSkill (T, cek);
    printf("\n");
    
    PrintUnlock (T);
    printf("Skill sudah diaktifkan (unlock true)\n");
    printf("\n");

	printf("\n");
	PrintAvailableSkill (T);
 //   PrintTree(T, 1);

	
	return 0;
}
