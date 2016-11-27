#include "enemy.h"
#include "stat.h"
#include "stdlib.h"
#include "mesinkata.h"
#include <stdio.h>
#include "queue.h"

int main () {
	Enemy M;
	
	//printf("Ini sudah CreateEmptyEnemy M\n");
	//CreateEmptyEnemy(&M);
	
	printf("\n");
	
	printf("Ini LoadEnemy\n");
	LoadEnemy();
	
	printf("\n");
	
	printf("\n");
	printf("Misalkan berikut status enemy sekarang\n");

	printf("strRate(M) = 20\n");
	printf("defRate(M) = 20\n");
	printf("hpRate(M) = 10\n");
	printf("maxHp(M) = 200\n");
	printf("cHp(M) = 200\n");
	printf("str(M) = 30\n");
	printf("def(M) = 30\n");

	strRate(M) = 20;
	defRate(M) = 20;
	hpRate(M) = 10;
	maxHp(M) = 200;
	cHp(M) = 200;
	str(M) = 30;
	def(M) = 30;
	
	GetStatEnemy(&M, 3);

	printf("\n");
	printf("%d\n",maxHp(M));
	printf("%d\n",str(M));
	printf("%d\n",def(M));
	
	GetEnemy(&M,9,20);
	
	printf("\n");
	printf("%d\n",maxHp(M));
	printf("%d\n",str(M));
	printf("%d\n",def(M));
    
//    srand((unsigned) rand() );
//    
//    a();
//    a();
//    a();
//    a();
//    


    
	return 0;
}
