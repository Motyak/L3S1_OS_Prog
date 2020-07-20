#include "../../libListe/include/Liste.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h> //strcmp

int is_valid(char);

const int CMDES_SIZE = 7;
char CMDES[] = {'\n','a','A','s','S','x','X'};

int main()
{
// //TU
// 	{
// //Initialisation de la liste avec un maillon unique de valeur 1
// 		Maillon* tete=addPred(1,NULL);

// 		printf("tete = %p	;	pred = %p	;	succ = %p\n",
// 			tete,tete->pred,tete->succ);

// //Ajout du maillon 2
// 		addPred(2,tete);
// 		printf("tete = %p	;	pred = %p	;	succ = %p\n",
// 			tete,tete->pred,tete->succ);

// //On déplace la tete vers succ puis on y ajoute le maillon 3
// 		tete=movToSucc(tete);
// 		addPred(3,tete);
// 		printf("tete = %p	;	pred = %p	;	succ = %p\n",
// 			tete,tete->pred,tete->succ);

// //On supprime le maillon tete
// 		tete=del(tete);
// 		printf("tete = %p	;	pred = %p	;	succ = %p\n",
// 			tete,tete->pred,tete->succ);
// 	}

	Maillon* tete=NULL;	//cur
	char promptCmd[50];
	promptCmd[0]=0;
	char promptVal[50];
	promptVal[0]=0;

	while(1)
	{
	//Affichage du maillon courant
		if(tete==NULL)
			printf("Liste vide\n");
		else
			printf("Maillon courant : %d\n",tete->val);

		
	//Controle de saisie
		while(is_valid(promptCmd[0])!=1)
		{
			printf("Commandes : [A]jouter un maillon / [S]upprimer le maillon courant / \
[Entrée](Passer au maillon suivant) / e[X]it\n");
			fgets(promptCmd,50, stdin);
		}
		
	//if else if en fonction de la commande saisie
		if(promptCmd[0]=='a' || promptCmd[0]=='A')
		{
			printf("Entrez la valeur du maillon à ajouter : \n");
			// scanf("%d",&promptVal);	//utiliser fgets a la place mais forcer int
			fgets(promptVal,50, stdin);
			// printf("Ajout du maillon %d..\n",promptVal);
			printf("Ajout du maillon %s\n",promptVal);
			if(tete==NULL)
				tete=addPred(strtol(promptVal,NULL,10),tete);	//strtol
			else
				addPred(strtol(promptVal,NULL,10),tete);	//strtol
		}
		else if(promptCmd[0]=='s' || promptCmd[0]=='S')
		{
			printf("Suppression du maillon courant..\n");
			tete=del(tete);
		}
		else if(promptCmd[0]=='\n')
		{
			if(tete!=NULL)
				tete=movToSucc(tete);
		}
		else if(promptCmd[0]=='x' || promptCmd[0]=='X')
		{
			printf("Fermeture du programme..\n");
			exit(0);
		}
		promptCmd[0]=0;
		printf("-------------------------------------\n");
	}

	return 0;
}

int is_valid(char c)
{
	for(int i=0;i<CMDES_SIZE;++i)
	{
		if(c==CMDES[i])
			return 1;
	}
	return 0;
}
