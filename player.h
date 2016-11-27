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

typedef struct {
    Stat stat;
    BinTree skill;
    int cHp;
    int exp;
    int lvl;
    int credit;
} Player;

#define exp(P) (P).exp
#define lvl(P) (P).lvl
#define skill(P) (P).skill
#define credit(P) (P).credit
void CreateEmptyPlayer (Player *P);

void LoadSavedPlayer (Player *P);

void LoadPlayer (Player *P);

void LoadNewPlayer (Player *P);

void SimpanPlayer(Player *P, char filename[]);

void ReadPlayer (Player *P, char namaFile[]);

void AddExp(Player *P, int round, int max);

void AddHp(Player *P);

void AddStr(Player *P);

void AddDef(Player *P);

void LevelUp(Player *P);

void UnlockSkill(Player *P,int X);

void PrintStat(Player *P);

void GetStat(Player *P);

void PrintInfoPlayer(Player *P);

void PrintNama(Name K);



#endif /* player_h */
