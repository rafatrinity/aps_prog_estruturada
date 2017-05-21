#include "sis.h"
#include "write.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#define NM 25
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

//=================================estruturas==============================

typedef struct data{
	int dia;
	int mes;
	int ano;
} data;

typedef struct aluno{
	char nome[NM];
	//int matricula;
	float cr;
	data niver;
} aluno;

//===================================ADD====================================

void ADD(){
	FILE *fp;
	aluno al;
	char op;
	fp = fopen("cadastro.bin", "ab");
	if (fp==NULL)
		escreva(1);
	do
	{
		cab();
		getchar();
		printf("DIGITE O NOME DO ALUNO: ");
		fgets(al.nome, NM, stdin);
		printf("\nDIGITE A DATA DE NASCIMENTO DO ALUNO: ");
		fflush(stdin);
		scanf("%d %d %d",&al.niver.dia,&al.niver.mes,&al.niver.ano);
		printf("\nDIGITE CR DO ALUNO: ");
		fflush(stdin);
		scanf("%f",&al.cr);
		fwrite(&al,sizeof(aluno),1,fp);
		getchar();
		printf("\ndeseja add outro aluno?(s/n)\n");
		scanf("%c",&op);
	} while (op=='s');
	fclose(fp);
}

//================================exibir==================================

void exibir(){
	FILE *fp;
	aluno al;
	char op;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	while(fread(&al, sizeof(aluno),1,fp)==1){
		printf("Nome: %s\n",al.nome);
		printf("CR: %.2f\n",al.cr);
		printf("Data de nasc: %2.d/%2.d/%4.d/\n",al.niver.dia,al.niver.mes,al.niver.ano);
		linha();
	}
	getchar();
	fclose(fp);
	getchar();
}

//===================================pesquisar================================
void pesquisar(){
	cab();
	int op;
	printf("  [1] - PESQUISAR POR NOME\n");
	printf("  [2] - PESQUISAR POR MATRICULA\n");
	printf("  [0] - VOLTAR\n");
	scanf("%d",&op);
	switch(op){
		case 1:
		pesquisarnome();
		break;
		case 2:
		break;
		default:
		escreva(2);
		break;
	}
}


void pesquisarnome(){
	FILE *fp;
	aluno al;
	char op, nome[NM];
	int tot =0;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	getchar();
	printf("Digite o nome a ser pesquisado: ");
	fgets(nome, NM, stdin);
	while(fread(&al, sizeof(aluno),1,fp)==1){
		if (strcmp(nome, al.nome)==0){
			printf("Nome: %s\n",al.nome);
			printf("CR: %.2f\n",al.cr);
			printf("Data de nasc: %2.d/%2.d/%4.d/\n",al.niver.dia,al.niver.mes,al.niver.ano);
			linha();
			tot++;
		}
	}
	if (tot==0)
		escreva(4);
	fclose(fp);
	getchar();
}
