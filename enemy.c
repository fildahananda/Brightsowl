//
//  enemy.c
//  player
//
//  Created by Richard Matthew on 11/22/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#include "enemy.h"
#include "stat.h"
#include "stdlib.h"
#include "mesinkata.h"

Enemy ListEnemy[5];
Enemy Boss[10];

void LoadEnemy ()
{
    char namaFile[1000];
    namaFile[0] = '"';
    namaFile[1] = 'L';
    namaFile[2] = 'E';
    namaFile[3] = '"';
    
    ReadEnemy(&namaFile[1000]);
    
}
void ReadEnemy (char namaFile[1000])
{
    int i,j,k;
    STARTKATA(namaFile);
    for(k=0;k<5; k++)
    {
        for (i=0;i<=6 ; i++)
        {
            switch (i)
            {
                case 0:
                {   for(j=0; j< CKata.Length;j++)
                {
                    tabName(ListEnemy[k])[j] = CKata.TabKata[j];
                    lengthName(ListEnemy[k]);
                }
                    ADVKATA();
                    break;
                }
                case 1:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        hpRate(ListEnemy[k]) = hpRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 2:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        strRate(ListEnemy[k]) = strRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 3:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        defRate(ListEnemy[k]) = defRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 4:
                {
                    ListEnemy[k].maxMoves = 10;
                    int idx;
                    for (idx=0; idx <ListEnemy[k].maxMoves; idx++)
                    {
                        for(j=0; j< CKata.Length;j++)
                        {
                            Add(&ListEnemy[k].moves[j], CKata.TabKata[j]);
                        }
                        ADVKATA();
                    }
                    ADVKATA();
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    //Load boss
    
    for(k=0;k<5; k++)
    {
        for (i=0;i<=6 ; i++)
        {
            switch (i)
            {
                case 0:
                {   for(j=0; j< CKata.Length;j++)
                {
                    tabName(ListEnemy[k])[j] = CKata.TabKata[j];
                    lengthName(ListEnemy[k]);
                }
                    ADVKATA();
                    break;
                }
                case 1:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        hpRate(ListEnemy[k]) = hpRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 2:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        strRate(ListEnemy[k]) = strRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 3:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        defRate(ListEnemy[k]) = defRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 4:
                {
                    ListEnemy[k].maxMoves = 10;
                    int idx;
                    for (idx=0; idx <ListEnemy[k].maxMoves; idx++)
                    {
                        for(j=0; j< CKata.Length;j++)
                        {
                            Add(&ListEnemy[k].moves[j], CKata.TabKata[j]);
                        }
                        ADVKATA();
                    }
                    ADVKATA();
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void GetStat(Enemy *E, int level)
{
    maxHp(*E)= level*(hpRate(*E));
    str(*E)  = level*(strRate(*E));
    def(*E)  = level*(defRate(*E));
}

void GetEnemy(Enemy *E, int level, int exp)
{
    int x;
    srand((unsigned) level*exp);
    
    x = (rand() %5);
    *E = ListEnemy[x];
    
    GetStat(E,level);
    cHp(*E) = maxHp(*E);
    
}
