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
#define maxEnemy 1
#define maxBoss 1
Enemy ListEnemy[maxEnemy+1];
Enemy Boss[maxBoss+1];

void CreateEmptyEnemy (Enemy *P)
{
    *P = *(Enemy *) malloc ((1) * sizeof(Enemy));
    lengthName(*P)=0;
    maxHp(*P) =0;
    str(*P) = 0;
    def(*P) = 0;
    strRate(*P) =0;
    defRate(*P) = 0;
    cHp(*P) = 0;
    CreateEmptyQue(&move(*P)[1], 4);
    
}

void LoadEnemy ()
{
    int i,j,k;
    STARTKATA("InfoEnemy.txt");
    for(k=1;k<=maxEnemy; k++)
    {
        CreateEmptyEnemy(&ListEnemy[k]);
        for (i=0;i<=6 ; i++)
        {
            switch (i)
            {
                case 0:
                {   for(j=1; j<= CKata.Length;j++)
                {
                    tabName(ListEnemy[k])[j] = CKata.TabKata[j];
                    lengthName(ListEnemy[k]);
                }
                    ADVKATA();
                    break;
                }
                case 1:
                {
                    for(j=1; j<= CKata.Length;j++)
                    {
                        hpRate(ListEnemy[k]) = hpRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 2:
                {
                    for(j=1; j<= CKata.Length;j++)
                    {
                        strRate(ListEnemy[k]) = strRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 3:
                {
                    for(j=1; j<= CKata.Length;j++)
                    {
                        defRate(ListEnemy[k]) = defRate(ListEnemy[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 4:
                {
                    maxM(ListEnemy[k]) = 10;
                    int idx;
                    for (idx=1; idx <=maxM(ListEnemy[k]); idx++)
                    {
                        CreateEmptyQue(&move(ListEnemy[k] )[idx], 4);
                        for(j=1; j<= CKata.Length;j++)
                        {
                            Add(&ListEnemy[k].moves[idx], CKata.TabKata[j]);
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
    
    for(k=0;k<maxBoss; k++)
    {
        CreateEmptyEnemy(&ListEnemy[k]);
        for (i=0;i<=6 ; i++)
        {
            switch (i)
            {
                case 0:
                {   for(j=0; j< CKata.Length;j++)
                {
                    tabName(Boss[k])[j] = CKata.TabKata[j];
                    lengthName(Boss[k]);
                }
                    ADVKATA();
                    break;
                }
                case 1:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        hpRate(Boss[k]) = hpRate(Boss[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 2:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        strRate(Boss[k]) = strRate(Boss[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 3:
                {
                    for(j=0; j< CKata.Length;j++)
                    {
                        defRate(Boss[k]) = defRate(Boss[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 4:
                {
                    maxM(Boss[k]) = 20;
                    int idx;
                    for (idx=0; idx<maxM(Boss[k]); idx++)
                    {
                        CreateEmptyQue(&move(Boss[k] )[idx], 4);
                        for(j=0; j< CKata.Length;j++)
                        {
                            Add(&Boss[k].moves[idx], CKata.TabKata[j]);
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

void GetStatEnemy(Enemy *E, int level)
{
    maxHp(*E)= level*level*(hpRate(*E)/10) + (level/6)*(hpRate(*E));
    str(*E)  = level*level*(strRate(*E)/10)+ (level/6)*(strRate(*E));
    def(*E)  = level*level*(defRate(*E)/10)+ (level/6)*(defRate(*E));
}

void GetEnemy(Enemy *E, int level, int exp)
{
    int x;
    srand((unsigned) level*exp);
    
    x = (rand() %maxEnemy)+1;
    *E = ListEnemy[x];
    
    GetStatEnemy(E,level);
    cHp(*E) = maxHp(*E);
    
}

void GetBoss(Enemy *E, int level, int exp)
{
    int x;
    srand((unsigned) level*exp);
    
    x = (rand() %5);
    *E = Boss[x];
    
    GetStatEnemy(E,level*2);
    cHp(*E) = maxHp(*E);
    
}
