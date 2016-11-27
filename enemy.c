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
#define maxEnemy 5
#define maxBoss 5
Enemy ListEnemy[maxEnemy+1];
Enemy Boss[maxBoss+1];

void CreateEmptyEnemy (Enemy *P)
{
    *P = *(Enemy *) malloc ((1) * sizeof(Enemy));
	tabName(*P)[0] = ' ';
    lengthName(*P)=0;
    maxHp(*P) =0;
    str(*P) = 0;
    def(*P) = 0;
    strRate(*P) =0;
    defRate(*P) = 0;
	hpRate(*P) = 0;
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
        for (i=0;i<=4 ; i++)
        {	
            switch (i)
            {
                case 0:
                {   for(j=1; j<= CKata.Length;j++)
                {
                    tabName(ListEnemy[k])[j] = CKata.TabKata[j];
                    lengthName(ListEnemy[k])= CKata.Length;
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
						IgnoreBlank();
                        ADVKATA();
                    }

                    break;
                }
                default:
                    break;
            }
        }
    }
    
    //Load boss
    
    for(k=1;k<=maxBoss; k++)
    {
        CreateEmptyEnemy(&Boss[k]);
        for (i=0;i<=6 ; i++)
        {
            switch (i)
            {
                case 0:
                {   
				for(j=1; j<= CKata.Length;j++)
					{
						tabName(Boss[k])[j] = CKata.TabKata[j];
						lengthName(Boss[k])= CKata.Length;
					}
                    ADVKATA();
                    break;
                }
                case 1:
                {
                    for(j=1; j<= CKata.Length;j++)
                    {
                        hpRate(Boss[k]) = hpRate(Boss[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 2:
                {
                    for(j=1; j<= CKata.Length;j++)
                    {
                        strRate(Boss[k]) = strRate(Boss[k])*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    break;
                }
                case 3:
                {
                    for(j=1; j<= CKata.Length;j++)
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
                    for (idx=1; idx<=maxM(Boss[k]); idx++)
                    {
                        CreateEmptyQue(&move(Boss[k] )[idx], 4);
                        for(j=1; j<= CKata.Length;j++)
                        {
                            Add(&Boss[k].moves[idx], CKata.TabKata[j]);
                        }
						IgnoreBlank();
                        ADVKATA();
                    }
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
    maxHp(*E)= level*(hpRate(*E)/4) + (level/6)*(hpRate(*E));
    str(*E)  = level*(strRate(*E)/4)+ (level/6)*(strRate(*E));
    def(*E)  = level*(defRate(*E)/4)+ (level/6)*(defRate(*E));
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
    
    x = (rand() %(maxBoss-1))+1;
    *E = Boss[x];
    
    GetStatEnemy(E,level*2);
    cHp(*E) = maxHp(*E);
    
}

void GetBigBoss(Enemy *E, int level)
{
    *E = Boss[5];
    GetStatEnemy(E,10 + (level)*0.9);
    cHp(*E) = maxHp(*E);
    
}