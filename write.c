#include "sis.c"
#include "write.h"
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "unistd.h"
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
	}
}