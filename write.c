#include "sis.h"
#include "write.h"
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "unistd.h"
#include "ctype.h"
#include "string.h"
#define NM 25

/*
 * veja mais em 
 * https://github.com/rafatrinity
 */

void escreva(int a){
	setlocale(LC_ALL,"portuguesse");
	cab();
	switch(a){
		case 1:
		printf("\to arquivo não pode ser aberto\n");
		sleep(2);
		break;
		case 2:
		printf("\tOPÇÃO INVALIDA\n");
		sleep(2);
		break;
		case 3:
		printf("\tVOLTE SEMPRE :)\n");
		sleep(2);
		break;
		case 4:
		printf("\tVERIFIQUE O NOME DIGITADO E TENTE NOVAMENTE!\n");
		linha();
		break;
		case 5:
		printf("a matricula gerada ja foi cadastrada anteriormente, tente novamente\n");
		break;
		case 6:
		printf("\tnão temos aniversariantes esse mês :(\n");
		break;
		case 7:
		printf("CR INVALIDO\n");
		break;
	}
}
