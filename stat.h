//
//  stat.h
//  player
//
//  Created by Richard Matthew on 11/22/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#ifndef stat_h
#define stat_h
typedef struct {
    char tabName[100];
    int length;
}Name;
typedef struct {
    Name name;
    int strRate;
    int defRate;
    int hpRate;
    int maxHp;
    int cHp;
    int str;
    int def;
} Stat;

#define tabName(P) (P).stat.name.tabName
#define lengthName(P) (P).stat.name.length
#define strRate(P) (P).stat.strRate
#define defRate(P) (P).stat.defRate
#define hpRate(P) (P).stat.hpRate
#define maxHp(P) (P).stat.maxHp
#define cHp(P) (P).stat.cHp
#define str(P) (P).stat.str
#define def(P) (P).stat.def
#endif /* stat_h */
