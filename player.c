//
//  player.c
//  player
//
//  Created by Richard Matthew on 11/14/16.
//  Copyright © 2016 MatthewRichard20. All rights reserved.
//

#include "player.h"
#include <stdlib.h>
#include "mesinkata.h"
void CreateEmptyPlayer (Player *P)
{
    *P = *(Player *) malloc ((1) * sizeof(Player));
    lengthName(*P)=0;
    maxHp(*P) =0;
    exp(*P) = 0;
    lvl(*P) = 0;
    str(*P) = 0;
    def(*P) = 0;
    strRate(*P) =0;
    defRate(*P) = 0;
    hpRate(*P) =0;
    cHp(*P) = 0;
    credit(*P) = 0;
    
}
void LoadNewPlayer(Player *P)
{
    char C;
    
    ReadPlayer(P,"infoplayer.txt");
    printf("Masukkan username: ");
    int i=0;
    scanf("%c",&C);
    while(C!='\n')
    {
        i++;
        tabName(*P)[i]=C;
        scanf("%c",&C);
    }
    lengthName(*P)=i;
    printf("Username telah disimpan!\n");
}

void LoadSavedPlayer (Player *P)
{
    
    ReadPlayer(P,"savedplayer.txt");
    
}
void ReadPlayer (Player *P, char namaFile[])
{
    int i,j,k;
    
    STARTKATA(namaFile);
	CreateEmptyPlayer(P);
    for (i=0;i<=6 ; i++)
    {
        switch (i)
        {
            case 0:
            {   for(j=1; j<= CKata.Length;j++)
                {
                    tabName(*P)[j] = CKata.TabKata[j];
                    lengthName(*P) = CKata.Length;
                }
                ADVKATA();
                break;
            }
            case 1:
            {

				for(j=1; j<= CKata.Length;j++)
                {
                    exp(*P) =  exp(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
				ADVKATA();
                break;
            }
            case 2:
            {
				for(j=1; j<= CKata.Length;j++)
                {
                    lvl(*P) = lvl(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
					
				}
                ADVKATA();
                break;
            }
            case 3:
            {
                for(j=1; j<=CKata.Length;j++)
                {
                    cHp(*P) = cHp(*P)*10 + ((int)CKata.TabKata[j] -((int) '0'));
                }
                ADVKATA();
                for(j=1; j<=CKata.Length;j++)
                {
                    hpRate(*P) = hpRate(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 4:
            {
                for(j=1; j<=CKata.Length;j++)
                {
                    strRate(*P) = strRate(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 5:
            {
                for(j=1; j<=CKata.Length;j++)
                {
                    defRate(*P) = defRate(*P)*10 + ((int) (CKata.TabKata[j]-'0'));
                }
                ADVKATA();
                break;
            }
            case 6:
            {
                infotype X;
                X.rate=0;
                X.idx=0;
                for (k=1; k<=15; k++)
                {
                    Rate(X)=0;
                    Idx(X)=k;
                    ADVKATA();
                    Type(X) = CKata.TabKata[1];
                    
                    ADVKATA();
                    Opr(X) =  CKata.TabKata[1];
                    for(j=2; j<= CKata.Length;j++)
                    {
                        Rate(X) =  Rate(X)*10 + ((int) (CKata.TabKata[j]-'0'));
                    }
                    ADVKATA();
                    Unlock(X)= (CKata.TabKata[1] == 'u');
                    ConstructTree(&skill(*P), X);
                    ADVKATA();
                }
                break;
            }
                
            default:
                break;
        }
    }
}

void SimpanPlayer(Player *P, char filename[])
{
    int i;
    addrNode Adr;
    static FILE * pita;
    pita=fopen(filename,"w");
    rewind(pita);
    for(i=1;i<=lengthName(*P);i++)
    {
        fprintf(pita,"%c",tabName(*P)[i]);
    }
    fprintf(pita,"\n");
    fprintf(pita,"%d\n",exp(*P));
    fprintf(pita,"%d\n",lvl(*P));
    fprintf(pita,"%d ",cHp(*P));
    fprintf(pita,"%d\n",hpRate(*P));
    fprintf(pita,"%d\n",strRate(*P));
    fprintf(pita,"%d\n",defRate(*P));
    for(i=1;i<=15;i++)
    {
        Adr=SearchAdrIdx(skill(*P),i);
        fprintf(pita,"%d %c %c%d ",i,Type(Akar(Adr)),Opr(Akar(Adr)),Rate(Akar(Adr)));
        if(Unlock(Akar(Adr)))
        {
            fprintf(pita,"u\n");
        }else
        {
            fprintf(pita,"l\n");
        }
    }
    fprintf(pita," .");
    fclose(pita);
}

void AddExp(Player *P, int round, int max)
{
    int x;
    exp(*P) = (50*(max - round +1)) + exp(*P) ;
    
    while ((exp(*P)>maxExp)&&(lvl(*P)<maxLvl))
    {
        exp(*P)-= maxExp;
        LevelUp(P);
        
    }
    GetStat(P);
    cHp(*P)     = maxHp(*P);


}

void LevelUp (Player *P)
{
            if (lvl(*P)< maxLvl)
        {
            lvl(*P)++;
            hpRate(*P)   += lvl(*P)*100;
            strRate(*P)    += 20*((lvl(*P)%10)+1);
            defRate(*P)    += 20*((lvl(*P)%10)+1);
            if (((lvl(*P) % 3)== 0) &&(lvl(*P)<48))
            {
                credit(*P)++;
            }
        }
        else
        {
            printf("Kamu sudah mencapai level maksimum\n");
        }
}

void UnlockSkill(Player *P,int X)
{
    BinTree T;
    if (IsAvailable(skill(*P), X))
    {
        T = SearchAdrIdx(skill(*P), X);
        Unlock(Akar(T)) = true;
        credit(*P)--;
        
    }
	else
	{
		printf("Input salah\n");
	}
    
}
void GetStat(Player *P)
{
    BinTree T;
    int i;
    T = Nil;
    maxHp(*P) = hpRate(*P);
    str(*P) = strRate(*P);
    def(*P) = defRate(*P);
    for(i=1; i<=15; i++)
    {
        T = SearchAdrIdx(skill(*P), i);
        if (Unlock(Akar(T)))
        {
            switch (Type(Akar(T)))
                {
                    case 'h':
                    case 'H':
                    {
                       if(Opr(Akar(T))=='*')
                       {
                           maxHp(*P)= (maxHp(*P)* Rate(Akar(T)))/10;
                       }
                       else
                       {
                           if(Opr(Akar(T))=='+')
                           {
                               maxHp(*P)+= Rate(Akar(T));
                           }
                       }
                     break;
                    }
                    case 's':
                    case 'S':
                    {
                        if(Opr(Akar(T))=='*')
                        {
                            str(*P)=(str(*P)* Rate(Akar(T)))/10;
                        }
                        else
                        {
                            if(Opr(Akar(T))=='+')
                            {
                                str(*P)+= Rate(Akar(T));
                            }
                        }
                        break;
                    }
                    case 'd':
                    case 'D':
                    {
                        if(Opr(Akar(T))=='*')
                        {
                            def(*P)=(def(*P)* Rate(Akar(T)))/10;
                        }
                        else
                        {
                            if(Opr(Akar(T))=='+')
                            {
                                def(*P)+= Rate(Akar(T));
                            }
                        }
                    }
                    default:
                        break;
                }
        }
        
    }
}
void PrintInfoPlayer(Player *P)
{
    printf("USERNAME: ");
    PrintNama((*P).stat.name);
    GetStat(P);
    printf("\nStat:\n\n");
    printf("LEVEL : %d\n",lvl(*P));
    if (Unlock(Akar(skill(*P))))
    {    printf ("Before skill:\n");
    printf ("HP : %d/%d\n", cHp(*P), hpRate(*P));
    printf ("STR: %d\n", strRate(*P));
    printf ("DEF: %d\n", defRate(*P));
    
    PrintUnlock(skill(*P));
    
    printf ("After skill:\n");
    printf ("HP : %d/%d\n", cHp(*P), maxHp(*P));
    printf ("STR: %d\n", str(*P));
    printf ("DEF: %d\n", def(*P));
    }
    else
    {
        printf ("HP : %d/%d\n", cHp(*P), hpRate(*P));
        printf ("STR: %d\n", strRate(*P));
        printf ("DEF: %d\n", defRate(*P));
        
        PrintUnlock(skill(*P));
    }
    
}

void PrintNama(Name K)
{
    int i;
    for(i=1;i<=K.Length;i++)
    {
        printf("%c",K.TabKata[i]);
    }
}
