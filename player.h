//
//  player.h
//  player
//
//  Created by Richard Matthew on 11/14/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include "skilltree.h"
#include "stat.h"
#include "mesinkata.h"

#define minLvl 1
#define maxLvl 50
#define minExp 0
#define maxExp 1000
#define maxRound 20

typedef struct {
    Stat stat;
    BinTree skill;
    int cHp;
    int exp;
    int lvl;
} Player;

#define exp(P) (P).exp
#define lvl(P) (P).lvl
#define skill(P) (P).skill

void LoadPlayer (Player *P);

void LoadNewPlayer (Player *P);

void ReadPlayer (Player *P, char namaFile[1000]);

void AddExp(Player *P, int round);

void AddHp(Player *P);

void AddStr(Player *P);

void AddDef(Player *P);

void LevelUp(Player *P);

void UnlockSkill(Player *P,char X);

void PrintStat(Player *P);

void PrintSkill(Player *P);



#endif /* player_h */
