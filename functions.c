#include "sis.h"
#include "time.h"
#include "write.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#define NM 25

/*
 * veja mais em 
 * https://github.com/rafatrinity
 */

//=================================estruturas==============================

typedef struct data{
	int dia;
	int mes;
	int ano;
} data;

typedef struct aluno{
	char nome[NM];
	int matricula;
	float cr;
	data niver;
} aluno;
aluno al;

//===================================ADD======================================

void ADD(){
	FILE *fp;
	char op;
	int mat=0;
	float cr;

//===========================gerador de matriculas============================
	
	do{
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		fp = fopen("cadastro.bin", "rb");
		if (fp==NULL)
			escreva(1);
		while(fread(&al, sizeof(aluno),1,fp)==1){
			if (mat+((tm.tm_year+1900)*1000)<=al.matricula)
				mat++;
		}
		fclose(fp);

//============================================================================

		fp = fopen("cadastro.bin", "ab");
		if (fp==NULL)
			escreva(1);
		cab();
		getchar();
		printf("DIGITE O NOME DO ALUNO: ");
		fgets(al.nome, NM, stdin);
		for (int i = 0; i < strlen(al.nome); i++)
			al.nome[i]=tolower(al.nome[i]);
		al.nome[0]=toupper(al.nome[0]);
		for (int i = 0; i < strlen(al.nome); i++){
			if (al.nome[i]==' ')
				al.nome[i+1]=toupper(al.nome[i+1]);
		}
		printf("\nDIGITE A DATA DE NASCIMENTO DO ALUNO: ");
		fflush(stdin);
		scanf("%d %d %d",&al.niver.dia,&al.niver.mes,&al.niver.ano);
		pcr:
		printf("\nDIGITE CR DO ALUNO: ");
		fflush(stdin);
		scanf("%f",&cr);
		if((cr>=0)&&(cr<=10))
			al.cr=cr;
		else{
			escreva(7);
			goto pcr;
		}
		al.matricula = (2017000+mat);
		fwrite(&al,sizeof(aluno),1,fp);
		getchar();
		printf("\ndeseja add outro aluno?(s/n)\n");
		scanf("%c",&op);
		fclose(fp);
	} while (op=='s');
}

//================================exibir======================================

void exibir(){
	FILE *fp;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	while(fread(&al, sizeof(aluno),1,fp)==1){
		printf("Nome: %s",al.nome);
		printf("MATRICULA: %d\n",al.matricula);
		printf("CR: %.2f\n",al.cr);
		printf("Data de nasc: %2.d/%2.d/%4.d\n",al.niver.dia,al.niver.mes,al.niver.ano);
		linha();
	}
	getchar();
	fclose(fp);
	getchar();
}

//===================================pesquisar================================

void PesquisarNome(){
	FILE *fp;
	char nome[NM];
	int tot =0;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	getchar();
	printf("Digite o nome a ser pesquisado: ");
	fgets(nome, NM, stdin);
	for (int i = 0; i < strlen(nome); i++)
		nome[i]=tolower(nome[i]);
	nome[0]=toupper(nome[0]);
	for (int i = 0; i < strlen(nome); i++){
		if (nome[i]==' ')
			nome[i+1]=toupper(nome[i+1]);
	}
	while(fread(&al, sizeof(aluno),1,fp)==1){
		if (strcmp(nome, al.nome)==0){
			printf("Nome: %s",al.nome);
			printf("Matricula: %d\n",al.matricula);
			printf("CR: %.2f\n",al.cr);
			printf("Data de nasc: %2.d/%2.d/%4.d\n",al.niver.dia,al.niver.mes,al.niver.ano);
			linha();
			tot++;
		}
	}
	if (tot==0)
		escreva(4);
	fclose(fp);
	getchar();
}

//============================================================================

void PesquisarMatricula(){
	FILE *fp;
	int tot =0, mat;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	getchar();
	printf("Digite a matricula do aluno: ");
	scanf("%d",&mat);
	while(fread(&al, sizeof(aluno),1,fp)==1){
		if (mat==al.matricula){
			printf("Nome: %s",al.nome);
			printf("Matricula: %d\n",al.matricula);
			printf("CR: %.2f\n",al.cr);
			printf("Data de nasc: %2.d/%2.d/%4.d\n",al.niver.dia,al.niver.mes,al.niver.ano);
			linha();
			tot++;
		}
	}
	if (tot==0)
		escreva(4);
	getchar();
	fclose(fp);
	getchar();
}

//============================================================================

void PesquisarPosicao(){
	FILE *fp;
	int tot=0, val;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	printf("Digite a posição a ser pesquisada: ");
	scanf("%d",&val);
	fseek (fp ,sizeof(aluno)*val, SEEK_SET);
	if(fread(&al, sizeof(aluno),1,fp)==1){
		printf("Nome: %s",al.nome);
		printf("MATRICULA: %d\n",al.matricula);
		printf("CR: %.2f\n",al.cr);
		printf("Data de nasc: %2.d/%2.d/%4.d\n",al.niver.dia,al.niver.mes,al.niver.ano);
		linha();
		tot++;
	}
	if (tot==0)
		escreva(4);
	getchar();
	fclose(fp);
	getchar();
}

//==================pesquisar por aniversariantes do mes======================

void PesquisarNiv(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	FILE *fp;
	int tot=0;
	fp = fopen("cadastro.bin", "rb");
	if (fp==NULL)
		escreva(1);
	cab();
	while(fread(&al, sizeof(aluno),1,fp)==1){
		if (al.niver.mes==tm.tm_mon+1){
			printf("Nome: %s",al.nome);
			printf("Matricula: %d\n",al.matricula);
			printf("CR: %.2f\n",al.cr);
			printf("Data de nasc: %2.d/%2.d/%4.d\n",al.niver.dia,al.niver.mes,al.niver.ano);
			linha();
			tot++;
		}
	}
	if (tot==0)
		escreva(6);
	getchar();
	fclose(fp);
	getchar();
}

//=================================remover====================================

int deleteRecordByName(char *fname){
	FILE *fp;
	FILE *fp_tmp;
	int found=0;
	char nome[NM];
	fp=fopen(fname, "rb");
	if (!fp) {
		printf("Unable to open file %s", fname);
		return -1;
	}
	fp_tmp=fopen("tmp.bin", "wb");
	if (!fp_tmp) {
		printf("Unable to open file temp file.");
		return -1;
	}
	cab();
	getchar();
	printf("Digite o nome a ser removido: ");
	fgets(nome, NM, stdin);
	for (int i = 0; i < strlen(nome); i++)
		nome[i]=tolower(nome[i]);
	nome[0]=toupper(nome[0]);
	for (int i = 0; i < strlen(nome); i++){
		if (nome[i]==' ')
			nome[i+1]=toupper(nome[i+1]);
	}
	while (fread(&al,sizeof(aluno),1,fp) == 1) {
		if (strcmp (nome, al.nome) == 0) {
			printf("%s foi removido(a) com sucesso!\n", nome);
			found=1;
		} 
		else
			fwrite(&al, sizeof(aluno), 1, fp_tmp);
	}
	if (!found)
		escreva(4);

	fclose(fp);
	fclose(fp_tmp);

	remove(fname);
	rename("tmp.bin", fname);
	getchar();
	return 0;
}

//==============================deletar pela matricula========================

int deleteRecordByMatricula(char *fname){
	FILE *fp;
	FILE *fp_tmp;
	int found=0, mat;
	fp=fopen(fname, "rb");
	if (!fp) {
		printf("Unable to open file %s", fname);
		return -1;
	}
	fp_tmp=fopen("tmp.bin", "wb");
	if (!fp_tmp) {
		printf("Unable to open file temp file.");
		return -1;
	}
	cab();
	getchar();
	printf("Digite a matricula a ser removida: ");
	scanf("%d",&mat);
	while (fread(&al,sizeof(aluno),1,fp) == 1) {
		if (mat==al.matricula) {
			linha();
			printf("\n\t%s foi removido(a) com sucesso!\n", al.nome);
			found=1;
		} 
		else
			fwrite(&al, sizeof(aluno), 1, fp_tmp);
	}
	if (!found)
		escreva(4);
	
	fclose(fp);
	fclose(fp_tmp);

	remove(fname);
	rename("tmp.bin", fname);
	getchar();
	getchar();
	return 0;
}
