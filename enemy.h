//
//  enemy.h
//  player
//
//  Created by Richard Matthew on 11/22/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#ifndef enemy_h
#define enemy_h

#include <stdio.h>
#include "stat.h"
#include "queue.h"

typedef struct {
    Stat stat;
    int maxMoves;
    Queue moves[20];
    
} Enemy;

#define move(E) (E).moves
#define maxM(E) (E).maxMoves

void CreateEmptyEnemy (Enemy *P);

void LoadEnemy();

void GetStatEnemy(Enemy *E, int level);

void GetEnemy(Enemy *E, int level, int exp);

void GetBoss(Enemy *E, int level, int exp);

#endif /* enemy_h */
