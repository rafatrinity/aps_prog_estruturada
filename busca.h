#ifndef busca
#define busca
#include "busca.h"
#include "stdio.h"
#include "stdlib.h"
int kmp(int tam_str, int tam_substr, char* str, char* substr){
	if (tam_substr<=tam_str)
	{
		int i=0, j=0;
		//indice str e substr
		while(i<tam_str){
			if (*(substr+j)==*(str+i))
			{
				j++;
				i++;
			}
			else{
				i++;
				j=0;
			}
			if (j==(tam_substr-1))
				return 1;
		}
	}
	return 0;
}
#endif