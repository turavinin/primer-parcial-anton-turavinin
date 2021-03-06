#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef ERECAUDACION_H_
#define ERECAUDACION_H_

// DEFINE
#define MAX_CHAR 100
#define MAX_ERRORES 3
#define MAX_COL 5

// STRUCT
typedef struct
{
	int id;
	int idContribuyente;
	int mes;
	int tipo;
	int estado;
	float importe;
	int isEmpty;
} eRecaudacion;

// ID
void setIdRecaudacion(int* id);
int getIdRecauda(eRecaudacion* eRecaudaArr, int largoArr, int* idRecauda);

// INIT
int initRecaudacion(eRecaudacion* eArr, int largoArr);

// ADD
int searchEmptyRecaudacion(eRecaudacion* eArr, int largoArr, int* posLibre);
int addRecaudacion(eRecaudacion* eArr, int largoArr, int id, int idContribuyente, int mes, int tipo, int posLibre);
int getMes(int* tipoMes);
int altaRecaudacion(eRecaudacion* eRecaudaArr, int largoArr, int* existenciaProxLibre, int idContri);

// ELIMINAR
int eliminarRecauda(eRecaudacion recauda);












#endif /* ERECAUDACION_H_ */
