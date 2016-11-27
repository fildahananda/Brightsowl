#include <stdio.h>
#include "graph.h"

int main () {
	Graph G;
	infograf X, Y, Z;
	addrGraf P, Q, R, S;

	scanf("%d", &X);
	scanf("%d", &Y);
	scanf("%d", &Z);

	CreateEmptyGraph(&G);

	if(IsEmptyGraph)
	{
		printf("Graf Kosong\n");
	} else {
		printf("Graf Tidak Kosong\n");
	}

	P=AlokasiGraph(X);
	printf("%d\n",P);
	if(P!=Nil)
	{
		InsertKiri(&G,Y);
	
		InsertKanan(&G,Z);
	}
		printf("%d\n", InfoGraf(P));


		S=SearchGraf(G,Y);
		printf("%d\n",S);

	DealokasiGraph(P);


	return 0;
}