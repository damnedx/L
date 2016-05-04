#include "../include/automate.h"


/*
* Retourne l'automate correspondant a l'expression donnée
*/
Automate newAutomate(char *expr)
{
    Automate a = (Automate)malloc(sizeof(s_automate));

    int size = strlen(expr);
  
    // Création des etats
    Node *elem = (Node *)malloc(size * sizeof(Node));
    int i;
    for(i = 0; i < size; i++)
    {
    	elem[i].id = i;
    	elem[i].value = expr[i];
    }
    a->nodeStart = elem[0].id;
    a->nodeEnd = elem[size - 1].id;


    // Creation des successeurs
   for(i = 0; i < size; i++)
   {
   		if(elem[i].id != a->nodeEnd)
   		{
	   		// Verifications des cycles
	   		if(elem[i].value == LETTERS || elem[i].value == NUMBERS )
	   		{
	   			elem[i].next[LEFT] = &(elem[i]);
	   			elem[i].next[RIGHT] = &(elem[i + 1]);
	   		}
	   		else
	   		{
	   			elem[i].next[LEFT] = &(elem[i + 1]); 
	   			elem[i].next[RIGHT] = NULL;	
	   		}
   		}
   		else
		{
			// L'etat final n'as pas de successeurs
			elem[i].next[LEFT] = NULL;
			elem[i].next[RIGHT] = NULL;

		}
   }

   a->node = elem;
   a->len = size;
   return a;
}


/*
* Affiche les transitions de l'automate
*/
void printAutomate(Automate a)
{
    int i,j;

    for(i  = 0; i < a->len; i++)
    {
    	printf("%c", a->node[i].value);
    	if(a->node[i].id != a->nodeEnd)
    	{
    		printf("->%c", a->node[i].next[LEFT]->value);
			if(a->node[i].next[RIGHT] != NULL)
				printf(",%c", a->node[i].next[RIGHT]->value);
    	}
    	printf("\n");

    }

}

int checkSyntax(char *expr, Automate a)
{
	int token = 0;// position dans l'automate
	int size = strlen(expr);
	int stop = 0;
	int index = (a->nodeStart == a->nodeEnd) ? 0 : 1;

	int j;
	for(int i = a->nodeStart , j = i; i < a->nodeEnd && !stop; i++)
	{
		if(expr[j] == a->node[i].value)
		{
			token++;
			j++;
		}
		else
		{
			switch(a->node[i].value)
			{
				case LETTERS:
					while(expr[j] != a->node[i + index].value && !stop)
					{
						if(expr[j] >= 'a' && expr[j] <= 'z')
							j++;
						else
							stop = 1;
					}
					token++;
					break;
				case NUMBERS:
					while(expr[j] != a->node[i + index].value && !stop)
					{
						if(expr[j] >= '0' && expr[j] <= '9')
							j++;
						else
							stop = 1;
					}
					token++;
					break;
			}
		}
	}
	
	if(stop)
		return 0;

	return (token == a->nodeEnd) ? 1 : 0 ;
}