//
//  main.c
//  player
//
//  Created by Richard Matthew on 11/14/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#include <stdio.h>
#include "skilltree.h"
#include "stdlib.h"
#include "player.h"
void a ()
{
    int x;
    x = (rand() %16)+1;
    printf("%d\n",x);
    x = (rand() %16)+1;
    printf("%d\n",x);
    x = (rand() %16)+1;
    printf("%d\n",x);
    x = (rand() %16)+1;
    printf("%d\n",x);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    BinTree T;
    infotype S;
    int i, x;
    Player *P;
    Idx(S) = 1;
    Type(S)[0] = 'i';
    Unlock(S) = true;
    Rate(S) = 10;

    
    for (i=1; i<=15; i++)
    {
        ConstructTree(&T, S);
        Idx(S)++;
    }
    PrintTree(T, 1);

    
//    srand((unsigned) rand() );
//    
//    a();
//    a();
//    a();
//    a();
//    
    LoadNewPlayer(P);
    
    printf("%d",hpRate(*P));
    return 0;
}
