#include "write.c"
#include "menus.c"
#include "functions.c"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "locale.h"
#include "time.h"

/*
 * veja mais em 
 * https://github.com/rafatrinity
 */

int main(){
	int men;
	SISTEMA = apresenta();
	do{
		men = menu();
		switch(men){
			case 1:
			ADD();
			break;
			case 2:
			excluir();
			break;
			case 3:
			exibir();
			break;
			case 4:
			pesquisar();
			break;
			case 0:
			escreva(3);
			break;
			default:
			escreva(2);
			break;
		}
	} while (men!=0);
	return 0;
}