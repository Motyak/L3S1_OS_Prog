typedef struct maillon
{
	int val;
	struct maillon* succ;
	struct maillon* pred;	
}Maillon;

Maillon* movToSucc(const Maillon*);
Maillon* del(Maillon*);
Maillon* addPred(int,Maillon*);