#include "sis.h"
#include "write.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#include "functions.h"
#define NM 25

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

//===========================gerador de matriculas============================
	
	do{
		fp = fopen("cadastro.bin", "rb");
		if (fp==NULL)
			escreva(1);
		while(fread(&al, sizeof(aluno),1,fp)==1){
			if (mat+2017000<=al.matricula)
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
		printf("\nDIGITE A DATA DE NASCIMENTO DO ALUNO: ");
		fflush(stdin);
		scanf("%d %d %d",&al.niver.dia,&al.niver.mes,&al.niver.ano);
		printf("\nDIGITE CR DO ALUNO: ");
		fflush(stdin);
		scanf("%f",&al.cr);
		al.matricula = (2017000+mat);
		fwrite(&al,sizeof(aluno),1,fp);
		getchar();
		printf("\ndeseja add outro aluno?(s/n)\n");
		scanf("%c",&op);
		fclose(fp);
	} while (op=='s');
}

//================================exibir==================================

void exibir(){
	FILE *fp;
	char op;
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

void pesquisarnome(){
	FILE *fp;
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

void pesquisarmatricula(){
	FILE *fp;
	char op;
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

//=================================remover================================

int deleteRecordByName(char *fname, char *searchname){
	FILE *fp;
	FILE *fp_tmp;
	int found=0;
	aluno myrecord;

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

	while (fread(&myrecord,sizeof(aluno),1,fp) == 1) {
		if (strcmp (searchname, myrecord.nome) == 0) {
			printf("A record with requested name found and deleted.\n\n");
			found=1;
		} else {
			fwrite(&myrecord, sizeof(aluno), 1, fp_tmp);
		}
	}
	if (! found) {
		printf("No record(s) found with the requested name: %s\n\n", searchname);
	}

	fclose(fp);
	fclose(fp_tmp);

	remove(fname);
	rename("tmp.bin", fname);

	return 0;
}
aluno Employee;

void DeleteEmployee(){

	FILE *fd;
	char EmployeeID[8];

	printf("\n>>Delete Employee<<\n");

    //Ask user for ID of employee they wish to delete.
	printf("Employee ID:");
	fgets(EmployeeID, 6, stdin);

	if ((fd = fopen("cadastro.bin", "rb")) == NULL) {
		printf("Error, Cannot Open File.\n");
	} else {
		fseek(fd, 0, SEEK_SET);
		fread(&Employee, sizeof(aluno), 1, fd);

		if (strcmp(EmployeeID, Employee.nome) == 0) {

            //Employee Found

		} else {
			printf("Employe Not Found!\n");
		}
	}
	fclose(fd);
}
