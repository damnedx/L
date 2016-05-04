#include "../include/util.h"

char special_char[] = {';', '=', '(', ')', '+', '-', '*'};

char* format_string(char *expr)
{
	char *str = expr;
	for(int i = 0; i < strlen(special_char); i++)
	{
		str = remove_spaces(str, special_char[i]);
	}
	return str;
	
}
int occurences(char *expr, char pattern)
{
	int len = strlen(expr);
	int occur = 0;
	for(int i = 0; i < len; i++)
	{
		if(expr[i] == pattern)
			occur++;
	}
	return occur;
}

int pos_pattern(char *expr, char pattern, char offset)
{
	int k = 0;
	int pos = offset;
	int len = strlen(expr);
	if(offset > 0)
		k++;
	while(expr[offset + k] != pattern && pos < len)
	{
		k++;
		pos++;
	}
	return k + offset;
}
// retire les espaces non significatif
// exemple : int b  =        150;
// renvoie : int b=150;
char* remove_spaces(char * expr, char pattern)
{
	int pos = 0;
	int len = strlen(expr);
	char *str_cpy = expr;
	int occur = occurences(expr, pattern);
	for(int j = 0; j < occur; j++)
	{
		// recupere la position du pattern
		pos = pos_pattern(expr, pattern, pos);
		if(pos == len)
			return expr;
		
		int stop = 0;
		int count = 0;
		// recupere le nombre d'espace avant le pattern
		for(int i = pos - 1; i > 0 && !stop ; i--)
		{
			if(expr[i] == ' ')
				count++;
			else
				stop = 1;
		}

		int j = 0;
		for(int i = 0; i < pos; i++)
		{
			if(i < (pos - count))
				str_cpy[j++] = expr[i];
				
		}
		str_cpy[j++] = pattern;
		count = 0;
		stop = 0;
		// recupere le nombre d'espace apres le pattern
		for(int i = pos + 1; i < len && !stop ; i++)
		{
			if(expr[i] == ' ')
				count++;
			else
				stop = 1;
		}
		for(int i = pos + 1; i < len; i++)
		{
			if(i > (pos + count))
				str_cpy[j++] = expr[i];
				
		}
		str_cpy[j] = '\0';
		
		
	}
	return str_cpy;
}
