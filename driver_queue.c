//DRIVER TO TEST QUEUE

#include "queue.h"
#include <stdio.h>

int main()
{
	Queue Q,Qs;
	char c,temp;
	
	CreateEmptyQue(&Q,4);
	while (!IsFullQue(Q))
	{
		scanf(" %c",&c);
		if (c=='E')
		{
			if (!IsEmptyQue(Q))
			{
				Del(&Q,&temp);
			}
		}
		else if (c=='A' || c=='B' || c=='F')
		{
			Add(&Q,c);
		}
		Qs=Q;
		printf("inputed: ");
		while (!IsEmptyQue(Qs))
		{
			Del(&Qs,&c);
			printf("%c",c);
		}
		printf("\n");
	}
	printf("number: %d\n",NBElmtQue(Q));
	while (!IsEmptyQue(Q))
		{
			Del(&Q,&c);
			printf("%c",c);
		}
	DeAlokasiQue(&Q);
	DeAlokasiQue(&Qs);
}
