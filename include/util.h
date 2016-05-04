#ifndef __UTIL_H__
#define __UTIL_H__
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
  formate la chaine de caractères
*/

char* format_string(char *expr);
char* remove_spaces(char * expr, char special_char);
int occurences(char *expr, char pattern);
int pos_pattern(char *expr, char pattern, char offset);

#endif
