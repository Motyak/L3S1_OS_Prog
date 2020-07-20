#include "../include/Liste.h"

#include <stdlib.h>
#include <stdio.h>

Maillon* movToSucc(const Maillon* m)
{
	return m->succ;
}

Maillon* del(Maillon* tete)
{
	if(tete!=NULL)
	{
		if(tete->succ==tete)
		{
			free(tete);
			return NULL;
		}
		else
		{
			tete->pred->succ=tete->succ;
			tete->succ->pred=tete->pred;
			Maillon* newTete=tete->succ;
			free(tete);
			return newTete;
		}
	}
	return NULL;
}

Maillon* addPred(int val,Maillon* m)
{
	Maillon* newM;

	if(m==NULL)
	{
		newM=(Maillon*)malloc(sizeof(Maillon));
		newM->val=val;
		newM->pred=newM;
		newM->succ=newM;
		return newM;
	}
	else
	{
		newM=(Maillon*)malloc(sizeof(Maillon));
		newM->val=val;
		newM->pred=m->pred;
		newM->succ=m;
		newM->succ->pred=newM;
		newM->pred->succ=newM;
		
		return m;
	}
}
