#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "locale.h"
#include "unistd.h"
#define X 20
#define Y 80
typedef struct p
{
	char nome[X], desc[Y];
	int id;
	float valor;
} produto;