#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define   pause system("pause")

//struct pour stocker les first
struct First{
	char Fir[20];
	int k;
};
//struct pour stocker les Follow
struct Follow{
	char Fol[20];
	int k;
};

struct First F[26];
struct Follow Fo[26];
int i,j,p,k,nbnt,nbt,nbou;
char Vn[26],Vt[40],Production[20][40];


void Lire_grammaire()
{
	printf("Donner le nombre de symbole non terminaux : ");
	scanf("%d",&nbnt);
	for(i=0 ; i < nbnt ; i++)
	{
		fflush(stdin);
		printf("Donner le %d symbole Nt : ",i+1);
		scanf("%c",&Vn[i]);
		Vn[i]=toupper(Vn[i]);
		printf("%c",Vn[i]);
	}
	printf("Donner le nombre de terminaux : ");
	scanf("%d",&nbt);
	for(i=0 ; i < nbt ; i++)
	{
		fflush(stdin);
		printf("Donner le %d symbole Term (0) pour epsi: ",i+1);
		scanf("%c",&Vt[i]);
		Vt[i]=tolower(Vt[i]);
		printf("%c",Vt[i]);
	}
	printf("Remplire les production\n");
	for(i=0 ; i < nbnt ; i++)
	{
		fflush(stdin);
		printf("Donner la %c :=> ",Vn[i]);
		scanf("%s",*(Production+i));
		F[i].k=0;
	}
	for(i=0 ; i < nbnt ; i++)
	{
		printf("%c :=> ",Vn[i]);
		for(j=0 ; j < strlen(*(Production+i)) ; j++)
			printf("%c",Production[i][j]);
		printf("\n");
	}
}

int cmp(int i,int *t,int r)
{
	for(k=0 ; k < nbt ; k++)
	{
		if(Vt[k] == Production[i][t[r]+1])
			return (1);
	}
	return (0);
}

int VT(int i)
{
	int k, j, r, exite, e, t, m;
	int ou[10], o = 1, p;

	ou[0] = 0;
	r = 0;
	F[i].k = 0;
	//pour compter les OU dans une regle de production
	for(e=0 ; e < strlen(*(Production+i)) ; e++)
	{
		if(Production[i][e] == '|')
		{
			ou[o]=e;
			ou[o]++;
			o++;
		}
	}
	//pour traiter les ou
	for(r=0 ; r<o ; r++)
	{
		deb:
		exite = 0;
		for(k=0;k<nbt;k++)
		{
			if(Vt[k]==Production[i][ou[r]])
			{
				exite=1;//il existe un first dans la  1er (a)  A>aB
				F[i].Fir[F[i].k]=Production[i][ou[r]];
				F[i].k++;
			}
		}
		//si le first est n"est pas 1er A>Ba  (A>BA et f(B) contient epsi) A>Ab
		if(!exite)
		{
			//condition qui traite cette cas : A>Ab
			if(Vn[i] == Production[i][ou[r]]) 
			{
				ou[r]=ou[r]+1;
				goto deb;
			}
			else if((isupper(Vn[i]) == 1) && (Vn[i] != Production[i][ou[r]]))
			{
				//pour A>Ba  (A>BA et f(B) contient epsi) A>Ab
				for(j=0 ; j < nbnt ; j++)
				{
					if(Production[i][ou[r]] == Vn[j])
					{
						if(F[j].k == 0)
							VT(j);
						for(k=0 ; k < F[j].k ; k++)
						{
							F[i].Fir[F[i].k]=F[j].Fir[k];
							F[i].k++;
						}
						for(p=0 ; p < F[i].k ; p++)
						{
							if((F[i].Fir[p]=='0') \
									&& (isupper(Production[i][ou[r]+1]) == 1) \
									&& (ou[r] <= strlen(*(Production+i))) \
									&& (Vn[i] != Production[i][ou[r]]))
							{
								for(t=p ; t < F[i].k-1 ; t++)
									F[i].Fir[t] = F[i].Fir[t+1];
								F[i].k--;
								ou[r]++;
								goto  deb;
							}
							if ((F[i].Fir[p] == '0') && (cmp(i, ou, r)))
							{
								for(t=p ; t < F[i].k - 1 ; t++)
									F[i].Fir[t] = F[i].Fir[t+1];
								F[i].k--;
								ou[r]++;
								goto deb;
							}
						}
					}
				}
			}
		}
	}
	return (0);
}

void First(){
	int r,n,p;

	//une boule inverse
	for(i = nbnt - 1 ; i >= 0 ; i--)
	{
		r=0;
		p=i;
		VT(i); //la fonction qui va calculer les first de Vn
		printf("First(%c)={", Vn[i]);
		//une boucle pour afficher les first
		for(j=0 ; j < F[i].k ; j++)
			printf("%c",F[i].Fir[j]);
		printf("}\n");
	}


}
void firFol(int p,int i,int r )
{
	int k;

	r++;
	for(k=0 ; k < nbt ; k++)
	{
		if(Vt[k] == Production[i][r])
		{
			Fo[p].Fol[Fo[p].k] = Production[i][r];
			Fo[p].k++;
		}
	}

}

void Follow(int i)
{
	int c,r,m;
	int exite;

	Fo[i].k=0;
	if(i == 0)
		printf("%c",'$');
	for(k=0 ; k<nbnt ; k++)
	{
		for(j=0 ; j < strlen(*(Production+k)) ; j++)
		{
			if((Vn[i] == Production[k][j]) \
					&& ((Production[k][j+1] != '|') && ( Production[k][j+1] != '\0')))
			{
				t:
				exite = 0;
			 	for(p=0 ; p < nbt ; p++)
				{
					if (Vt[p] == Production[k][j + 1])
					 	exite=1;
				}
				if(exite)
					printf("%c",Production[k][j + 1]);
				if(isupper(Production[k][j + 1]))
				{
					for(p=0 ; p < nbnt ; p++)
					{
						if(Vn[p] == Production[k][j + 1])
						{
			 				for(c=0 ; c < F[p].k ; c++)
							{
								if(F[p].Fir[c] != '0')
									printf("%c", F[p].Fir[c]);
							}
							for(r=0 ; r < F[p].k ; r++)
							{
								if(F[p].Fir[r] == '0')
								{
									if((Production[k][j + 2] == '|') || (Production[k][j + 2] == '\0'))
										Follow(k);
								}
				 				else
								{ 
									j++;
									goto t;
				 				}
							}
						}
					}
	 			}
			}
		}
		if((Vn[i] == Production[k][j]) \
				&& ((Production[k][j + 1] == '|') || (Production[k][j + 1] == '\0')) \
				&& (Vn[k] != Production[k][j]))
			Follow(k);
	}
}

int main(){
	Lire_grammaire();
	First();
	printf("________________\n");
	for(i = 0 ; i < nbnt ; i++)
	{
		printf("Follow(%c)={", Vn[i]);
		Follow(i);
		printf("}\n");
	}
	pause;
	return 0;
}
