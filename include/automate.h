#ifndef __AUTOMATE_H__
#define __AUTOMATE_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_SUCCESSOR 2
#define LETTERS 'N'
#define NUMBERS 'V'

enum {LEFT, RIGHT} ;


typedef struct s_node Node;
struct s_node
{
    int id;
    int type;
    Node *next[SIZE_SUCCESSOR];
    char value;
};


typedef struct s_automate
{
	int nodeStart;
	int nodeEnd;
    Node *node;
    int len;
} *Automate, s_automate;



Automate newAutomate(char *expr);
void printAutomate(Automate a);
int checkSyntax(char *expr, Automate a);
#endif
