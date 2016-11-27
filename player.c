//
//  player.c
//  player
//
//  Created by Richard Matthew on 11/14/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#include "player.h"

void LoadNewPlayer (Player *P)
{
    char namaFile[1000];
    namaFile[0] = '"';
    namaFile[1] = 'I';
    namaFile[2] = 'P';
    namaFile[3] = '"';
    
    ReadPlayer(P,namaFile);
    
}
void ReadPlayer (Player *P, char namaFile[1000])
{
    int i,j;
    STARTKATA(&namaFile[1000]);
    for (i=0;i<=6 ; i++)
    {
        switch (i)
        {
            case 0:
            {   for(j=0; j< CKata.Length;j++)
                {
                    tabName(*P)[j] = CKata.TabKata[j];
                    lengthName(*P);
                }
                ADVKATA();
                break;
            }
            case 1:
            {
                for(j=0; j< CKata.Length;j++)
                {
                    exp(*P) = exp(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 2:
            {
                for(j=0; j< CKata.Length;j++)
                {
                    lvl(*P) = lvl(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 3:
            {
                for(j=0; j< CKata.Length;j++)
                {
                    cHp(*P) = cHp(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                for(j=0; j< CKata.Length;j++)
                {
                    hpRate(*P) = hpRate(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 4:
            {
                for(j=0; j< CKata.Length;j++)
                {
                    strRate(*P) = strRate(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 5:
            {
                for(j=0; j< CKata.Length;j++)
                {
                    defRate(*P) = defRate(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 6:
            {
                infotype *X;
                for (j=1; j<=15; j++)
                {
                    Idx(*X);
                    ADVKATA();
                    for(j=0; j< CKata.Length;j++)
                    {
                        Type(*X)[j] = CKata.TabKata[j];
                    }
                    ADVKATA();
                    Opr(*X) =  CKata.TabKata[0];
                    for(j=1; j< CKata.Length;j++)
                    {
                        Rate(*X) =  Rate(*X)*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    if (CKata.TabKata[0] == 'l')
                    {
                        Unlock(*X) = false;
                    }
                    else
                    {
                        Unlock(*X) = true;
                    }
                    ConstructTree(&skill(*P), *X);
                    ADVKATA();
                }
                break;
            }
                
            default:
                break;
        }
    }
}

void AddExp(Player *P, int round)
{
    int temp;
    temp = (50*(maxRound - round)) + exp(*P) ;
    if (temp >= maxExp)
    {
        LevelUp(P);
    }
}

void LevelUp (Player *P)
{
    char X;
    if (lvl(*P)< maxLvl)
    {
        lvl(*P)    += exp(*P)/maxExp;
        exp(*P)     = exp(*P) % maxExp ;
        maxHp(*P)   = lvl(*P)*1000;
        str(*P)    += 20*((lvl(*P)%10)+1);
        def(*P)    += 20*((lvl(*P)%10)+1);
        cHp(*P)     = maxHp(*P);
        if ((lvl(*P) % 3)== 0)
        {
            //PrintAvailableSkill(skill(*P));
            printf("Pilih skill yang anda inginkan\n");
            scanf("%c",&X);
            //UnlockSkill(P, X);
        }
    }
    else
    {
        printf("Kamu sudah mencapai level maksimum\n");
    }
}
void UnlockSkill(Player *P,char X);

void PrintStat(Player *P);

void PrintSkill(Player *P);

