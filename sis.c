#include "sis.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
char apresenta(){
	/*
	.::::.  ::      .::::.  ||
	::  ::  ::      ::  ::  ||
	::  ::  ::      ::::::  ||
	*::::*  ::::::  ::  ::  ::
    */
    char SISTEMA;
	printf("\t.::::.  ::      .::::.  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::  ::  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::::::  ||\n");
	usleep(200000);
	printf("\t*::::*  ::::::  ::  ::  ::\n\n");
	printf("\tPOR GENTILEZA, INFORME QUAL SISTEMA OPERACIONAL VC UTILIZA:\nD=DOS\nU=UNIX\n\n");
	printf("\tDUVIDAS? DIGITE (i) PARA MAIS INFORMAÇÕES\n");
	pergunta:
	fflush(stdin);
	scanf("%c",&SISTEMA);
	SISTEMA=toupper(SISTEMA);
	switch(SISTEMA){
		case 'D':
		system("cls");
		fflush(stdin);
		break;
		case 'U':
		system("clear");
		fflush(stdin);
		break;
		case 'I':
		printf("\nDOS = Window\nUNIX = Mac e Linux(há exeções)");
		getchar();
		goto pergunta;
		break;
		default:
		printf("\nENTRADA INVALIDA, FAVOR DIGITAR SOMENTE AS LETRAS INDICADAS\n");
		goto pergunta;
	}
	return SISTEMA;
}
