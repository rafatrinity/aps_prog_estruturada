#include "sis.h"
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "locale.h"
char SISTEMA;
char apresenta(){
	/*
	.::::.  ::      .::::.  ||
	::  ::  ::      ::  ::  ||
	::  ::  ::      ::::::  ||
	*::::*  ::::::  ::  ::  ::
    */
	printf("\n\n");
	printf("\t\t\t.::::.  ::      .::::.  ||\n");
	usleep(200000);
	printf("\t\t\t::  ::  ::      ::  ::  ||\n");
	usleep(200000);
	printf("\t\t\t::  ::  ::      ::::::  ||\n");
	usleep(200000);
	printf("\t\t\t*::::*  ::::::  ::  ::  ::\n\n");
	printf("\n\n");
	printf("\tPOR GENTILEZA, INFORME QUAL SISTEMA OPERACIONAL VC UTILIZA:\n\n\tD=DOS\n\tU=UNIX\n\n");
	printf("\t\tDUVIDAS? DIGITE (i) PARA MAIS INFORMAÇÕES\n");
	printf("\t"); 
	linha();
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

//============================escreve uma linha na tela=========================

int linha(){
	usleep(100000);
	for (int i = 0; i < 60; ++i)
		printf("=");
	usleep(100000);
	printf("\n");
	return 0;
}

//==================================cabeçalho=================================

void cab(){
	if (SISTEMA == 'D')
		system("cls");
	else
		system("clear");
	printf("============================================================\n");
	printf("                  UNICARIOCA - AGENDA\n");
	printf("============================================================\n\n");
}
