#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MakeNewSmall(int in, int Baris, int Kolom, int P, Map *M, indeks ordinat, indeks absis)
{
	int i,j,x;
	indeks b,k,b1,k1;
	MakeMATRIKS(Baris, Kolom, &SmallMap(*M,in));
	if(P==1)
	{
		Pintu(*M,in)=1;
		b=ordinat;
		k=absis;
		if(k==1)
		{
			Absis(P1(*M,in))=k;
			Ordinat(P1(*M,in))=b;
		}
		else
		{
			Absis(P2(*M,in))=k;
			Ordinat(P2(*M,in))=b;
		}
		Elmt(SmallMap(*M,in),b,k)='-';
		i=1;
		while(i<(Baris*Kolom*5/16))
		{
			RandomNext(SmallMap(*M,in),b,k,&b1,&k1);
			b=b1; k=k1;
			if (Elmt(SmallMap(*M,in),b,k)!='-')
			{
				Elmt(SmallMap(*M,in),b,k)='-';
				i++;
			}
		}	
		
	}else
	{
		Pintu(*M,in)=2;
		b=ordinat;
		k=absis;
		Absis(P1(*M,in))=k;
		Ordinat(P1(*M,in))=b;
		b1=rand()%Baris+1;
		k1=Kolom;
		Absis(P2(*M,in))=k1;
		Ordinat(P2(*M,in))=b1;
		for(i=k;i<=(Kolom/2);i++)
		{
			Elmt(SmallMap(*M,in),b,i)='-';
		}
		for(i=k1;i>=(Kolom/2);i--)
		{
			Elmt(SmallMap(*M,in),b1,i)='-';
		}	
		if(b<b1)
		{
			for(i=b;i<=b1;i++)
			{
				Elmt(SmallMap(*M,in),i,(Kolom/2))='-';
			}
		}else
		{
			for(i=b1;i<=b;i++)
			{
				Elmt(SmallMap(*M,in),i,(Kolom/2))='-';
			}
		}
		i=1;
		b=b1;
		while(i<(Baris*Kolom*5/16))
		{
			RandomNext(SmallMap(*M,in),b,k,&b1,&k1);
			b=b1; k=k1;
			if(Elmt(SmallMap(*M,in),b,k)!='-'){
				Elmt(SmallMap(*M,in),b,k)='-';
			i++;}
		}
	}
	for(i=1;i<=Baris;i++)
	{
		for(j=1;j<=Kolom;j++)
		{
			if(Elmt(SmallMap(*M,in),i,j)!='-')
			{
				Elmt(SmallMap(*M,in),i,j)='#';
			}
		}
	}
}

void RandomNext(MATRIKS M,indeks b, indeks k, indeks *b1, indeks *k1)
{
	int x=0;
	if(b==BrsMin)
	{
		if(k==KolMin)
		{
			x=3;
		}
		else if(k==NKolEff(M))
		{
			x=(rand()%2)*3;
		}
		else
		{
			x=(rand()%3+2);
		}
	}else if(b==NBrsEff(M))
	{
		if(k==KolMin)
		{
			x=rand()%2+1;
		}
		else if(k==NKolEff(M))
		{
			x=rand()%2;
		}
		else
		{
			x=rand()%3;
		}
	}
	else if(k==KolMin)
	{
		x=2;
	}
	else if(k==NKolEff(M))
	{
		x=0;
	}
	else
	{
		if(b==BrsMin+1)
		{
			if(k==BrsMin+1)
			{
				x=rand()%2+2;
			}else if(k==NKolEff(M)-1)
			{
				x=rand()%2*3;
			}else
			{
				x=rand()%3+2;
			}
		}else if (b==NBrsEff(M)-1)
		{
			if(k==BrsMin+1)
			{
				x=rand()%2+1;
			}else if(k==NKolEff(M)-1)
			{
				x=rand()%2;
			}else
			{
				x=rand()%3;
			}
		}else if(k==KolMin+1)
		{
			x=rand()%3+1;
		}else if(k==NKolEff(M)-1)
		{
			x=rand()%2;
		}else
		{
			x=rand()%4;
		}
	}
	switch (x)
	{
		case 1: *b1=b-1;*k1=k; break;
		case 2: *k1=k+1;*b1=b; break;
		case 3: *b1=b+1;*k1=k; break;
		default: *k1=k-1; *b1=b;
	}
}

void MakeMap(int Baris, int Kolom, int N, Map *P)
{
	int i=1;
	indeks b;
	indeks k;
	NeffMap(*P)=N;
	CreateEmptyGraph(&Graf(*P));
	for(i=1;i<=N;i++)
	{
		if(i==1)
		{
			b=rand()%Baris+1;
			k=Kolom;
			MakeNewSmall(i,Baris,Kolom,1,P,b,k);
		}else if(i==N)
		{
			MakeNewSmall(i,Baris,Kolom,1,P,Ordinat(P2(*P,i-1)),1);
		}else
		{
			MakeNewSmall(i,Baris,Kolom,2,P,Ordinat(P2(*P,i-1)),1);
		}
		InsertKanan(&Graf(*P),i);
	}
	RandomEnemy(P);
}

void RandomEnemy (Map *M)
{
	int i,j,E;
	indeks b,k;
	for(i=1;i<=NeffMap(*M);i++)
	{
		E=NBrsEff(SmallMap(*M,i))*NKolEff(SmallMap(*M,i))/80;
		j=1;
		while(j<=E)
		{
			b=rand()%NBrsEff(SmallMap(*M,i))+1;
			k=rand()%NKolEff(SmallMap(*M,i))+1;
			if(Elmt(SmallMap(*M,i),b,k)=='-')
			{
				if(j==E)
				{
					Elmt(SmallMap(*M,i),b,k)='B';
				}else
				{
					Elmt(SmallMap(*M,i),b,k)='E';
				}
				j++;
			}
		}
	}
}

void SimpanMap(Map *M, char filename[])
{
	int i,j,k;
	static FILE * pita;
	pita=fopen(filename,"w");
	rewind(pita);
	i=1;
	while(i<=NeffMap(*M))
	{
		j=1;
		while(j<=NBrsEff(SmallMap(*M,i)))
		{
			k=1;
			while(k<=NKolEff(SmallMap(*M,i)))
			{
				fprintf(pita,"%c",Elmt(SmallMap(*M,i),j,k));
				k++;
			}
			fprintf(pita,"\n");
			j++;
		}
		fprintf(pita,"|\n");
		i++;
	}
	fprintf(pita,".");
	fclose(pita);
}
void BacaMap (Map *M,char filename[])
{
	int i,j,k;
	STARTKATA(filename);
	IgnoreBlank();
	i=0;
	if(!EndKata)
	{
		i=1;
		j=1;
		while((CKata.TabKata[1]!='|')&&(!EndKata))
		{
			k=1;
			while(k<=CKata.Length)
			{
				Elmt(SmallMap(*M,i),j,k)=CKata.TabKata[k];
				k++;
			}
			NKolEff(SmallMap(*M,i))=k-1;
			ADVKATA();
			j++;
			NBrsEff(SmallMap(*M,i))=j-1;
		}
		i++;
		if(!EOP)
		{
			for(;;)
			{
				ADVKATA();
				j=1;
				while((CKata.TabKata[1]!='|')&&(!EndKata))
				{
					k=1;
					while(k<=CKata.Length)
					{
						Elmt(SmallMap(*M,i),j,k)=CKata.TabKata[k];
						k++;
					}
					NKolEff(SmallMap(*M,i))=k-1;
					ADVKATA();
					j++;
					NBrsEff(SmallMap(*M,i))=j-1;
				}
				i++;
				if (EOP)
				{
					break;
				}
			}
		}
	}
	NeffMap(*M)=i-1;
}

