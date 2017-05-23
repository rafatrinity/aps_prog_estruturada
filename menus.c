#include "menus.h"
#include "functions.h"

/*
 * veja mais em 
 * https://github.com/rafatrinity
 */

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
		printf("  [3] - PESQUISAR POR POSIÇÃO\n");
		printf("  [4] - PESQUISAR POR ANIVERSARIANTES DO MÊS\n");
		printf("  [0] - VOLTAR\n");
		scanf("%d",&op);
		switch(op){
			case 1:
			PesquisarNome();
			break;
			case 2:
			PesquisarMatricula();
			break;
			case 3:
			PesquisarPosicao();
			break;
			case 4:
			PesquisarNiv();
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

void excluir(){
	int op;
	do
	{
		cab();
		printf("  [1] - DELETAR PELO NOME\n");
		printf("  [2] - DELETAR PELA MATRICULA\n");
		printf("  [0] - VOLTAR\n");
		scanf("%d",&op);
		switch(op){
			case 1:
			deleteRecordByName("cadastro.bin");
			break;
			case 2:
			deleteRecordByMatricula("cadastro.bin");
			break;
			case 0:
			break;
			default:
			escreva(2);
			break;
		} 
	}while (op!=0);
}