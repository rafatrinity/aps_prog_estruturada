#include "menus.h"
#include "functions.h"

//==================================main menu=================================

int menu(){
	cab();
	int op;
	printf("  [1] - ADD ALUNO\n");
	printf("  [2] - REMOVER ALUNO\n");
	printf("  [3] - LISTAR ALUNOS\n");
	printf("  [4] - PESQUISAR\n");
	printf("  [0] - SAIR\n");
	scanf("%d",&op);
	return op;
}

//================================menu pesquisar==============================

void pesquisar(){
	int op;
	do
	{
		cab();
		printf("  [1] - PESQUISAR POR NOME\n");
		printf("  [2] - PESQUISAR POR MATRICULA\n");
		printf("  [0] - VOLTAR\n");
		scanf("%d",&op);
		switch(op){
			case 1:
			pesquisarnome();
			break;
			case 2:
			pesquisarmatricula();
			break;
			case 0:
			break;
			default:
			escreva(2);
			break;
		} 
	}while (op!=0);
}

//==================================excluir===================================