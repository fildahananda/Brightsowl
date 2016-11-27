//DRIVER TO TEST STACKT

#include "stackt.h"
#include "queue.h"
#include <stdio.h>
int main ()
{
	int p,l,j;
	Stack S;
	Queue Qu[10+1],Qt;
	char n;
	
	CreateEmptyStack(&S);
	printf("input the number of stack: ");
	scanf ("%d",&p); //input the number of stack
	for (l=1;l<=p;l++)
	{
		CreateEmptyQue(&(Qu[l]),4);
		for (j=1;j<=4;j++)
		{
			scanf(" %c",&n);
			Add(&(Qu[l]),n);
		}
	}
	ReadFileM(&S,Qu,p);
	printf("randomized: \n");
	while (!IsEmptyStack(S))
	{
		CreateEmptyQue(&Qt,4);
		Pop(&S,&Qt);
		while (!IsEmptyQue(Qt))
		{
			Del(&Qt,&n);
			printf("%c ",n); /*Prosesnya*/
		}
		printf("\n");
	}
	return 0;
}
