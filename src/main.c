#include <stdio.h>
#include <stdlib.h>
#include "../include/automate.h"
#include "../include/util.h"


int main(int argc, char **argv)
{
    // DECLARATION DE VARIABLES
    // TYPE INT
    // [int] N* = V* ; N = [a-z], N = [0-9]
    char expr_declare_int[] = "int N=V;";
  
  
    Automate a = newAutomate(expr_declare_int);
   // printAutomate(a);
    //char *expr = format_string(argv[1]);
    //printf("%s\n", expr);
    //int result = checkSyntax(expr, a);
    //printf("%d\n", result);
    equilibre();



    free(a->node);
    free(a);
        

	return 0;
}

