#include "bibliotecaUTN-validaciones.h"
#include "eContribuyente.h"
#include "eRecaudacion.h"

// PRINTF ARRAY SPACE
int w[MAX_COL] = {15, 15, 15, 15, 15};

// ID
int idContribuyente = 1000;
void setIdContribuyente(int* id)
{
	*id = idContribuyente++;
}

// INIT ESTRUCTURA
int initContribuyente(eContribuyente* eArr, int largoArr)
{
	int exitoFuncion = -1;
	eContribuyente contribuyenteNuevo;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = contribuyenteNuevo;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// ADD CONTRIBUYENTE
int searchEmptyContribuyente(eContribuyente* eArr, int largoArr, int* posLibre)
{
	int exitoFuncion = -1;

	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			if(eArr[i].isEmpty == 1)
			{
				*posLibre = i;
				exitoFuncion = 0;
				break;
			}
		}

		if(exitoFuncion == -1)
		{
			*posLibre = -1;
		}
	}
	return exitoFuncion;
}

int addContribuyente(eContribuyente* eArr, int largoArr, int id, char* nombre, char* apellido, int cuil, int posLibre)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		eArr[posLibre].id = id;
		strcpy(eArr[posLibre].nombre, nombre);
		strcpy(eArr[posLibre].apellido, apellido);
		eArr[posLibre].cuil = cuil;
		eArr[posLibre].isEmpty = 0;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}

int altaContribuyente(eContribuyente* eArr, int largoArr, int* existenciaProxLibre)
{
	int exitoFuncion = -1;
	int posLibre;
	int auxProxLibre = *existenciaProxLibre;
	int exito = searchEmptyContribuyente(eArr, largoArr, &posLibre);

	if(exito == 0)
	{
		// Variable datos
		char nombre[MAX_CHAR];
		char apellido[MAX_CHAR];
		int cuil;

		if(utn_getStringLimited(nombre, "\nIngrese el nombre del contribuyente: ", "-- Error de carga. ", MAX_CHAR, MAX_ERRORES) == 0 &&
		utn_getStringLimited(apellido, "Ingrese el apellido del contribuyente: ", "-- Error de carga. ", MAX_CHAR, MAX_ERRORES) == 0 &&
		utn_getNumber(&cuil, "Ingrese el cuil del contribuyente: ", "-- Error de carga. ", MAX_ERRORES) == 0)
		{
			int id;
			setIdContribuyente(&id);
			exito = addContribuyente(eArr, largoArr, id, nombre, apellido, cuil, posLibre);
			exitoFuncion = 0;
		}
		else
		{
			exito = -1;
		}

		searchEmptyContribuyente(eArr, largoArr, &auxProxLibre);
		if(auxProxLibre == -1)
		{
			*existenciaProxLibre = auxProxLibre;
		}
	}

	if(exito != 0)
	{
		printf("---- ERROR AL INGRESAR CONTRIBUYENTE ----");
	}

	return exitoFuncion;
}

// MODIFICAR
int modificarContribuyente(eContribuyente* eArr, int largoArr)
{
	int exitoFuncion = -1;
	int id;
	int i;
	char nombre[MAX_CHAR];
	char apellido[MAX_CHAR];
	int cuil;

	if(eArr != NULL && largoArr > 0)
	{
		int exito = getIdContribuyente(eArr, largoArr, &id);

		if(exito == 0)
		{
			for(i = 0; i < largoArr; i++)
			{
				if(eArr[i].id == id)
				{
					if(utn_getStringLimited(nombre, "\nIngrese el nombre del contribuyente: ", "-- Error de carga. ", MAX_CHAR, MAX_ERRORES) == 0 &&
							utn_getStringLimited(apellido, "Ingrese el apellido del contribuyente: ", "-- Error de carga. ", MAX_CHAR, MAX_ERRORES) == 0 &&
							utn_getNumber(&cuil, "Ingrese el cuil del contribuyente: ", "-- Error de carga. ", MAX_ERRORES) == 0)
					{

						strcpy(eArr[i].nombre, nombre);
						strcpy(eArr[i].apellido, apellido);
						eArr[i].cuil = cuil;
						exitoFuncion = 0;
					}
					else
					{
						exito = -1;
					}
				}
			}
		}

		if(exito != 0)
		{
			printf("\n---- NO SE PUDO MODIFICAR. INTENTE DE NUEVO ----\n");
		}

	}

	return exitoFuncion;
}

// BAJA
int bajaContribuyente(eContribuyente* eArr, eRecaudacion* eArrRecauda, int largoArr)
{
	int exitoFuncion = -1;
	int idContribuyente;
	char mes[MAX_CHAR];
	char tipo[MAX_CHAR];
	char afirmaEliminar;
	if(eArr != NULL && largoArr > 0)
	{
		int exito = getIdContribuyente(eArr, largoArr, &idContribuyente);
		if(exito == 0)
		{
			printf("\nTABLA RECAUDACIONES");
			printf("\n|%-*s|%-*s|%-*s|%-*s|\n", w[0],"MES", w[1],"TIPO", w[2],"ESTADO", w[3],"IMPORTE");
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eArrRecauda[i].idContribuyente == idContribuyente)
				{
					switch(eArrRecauda[i].tipo)
					{
						case 1:
							strcpy(tipo, "ARBA");
							break;
						case 2:
							strcpy(tipo, "IIBB");
							break;
						case 3:
							strcpy(tipo, "GANANCIAS");
							break;
					}

					switch(eArrRecauda[i].tipo)
					{
						case 1:
							strcpy(mes, "Enero");
							break;
						case 2:
							strcpy(mes, "Febrero");
							break;
						case 3:
							strcpy(mes, "Marzo");
							break;
						case 4:
							strcpy(mes, "Abril");
							break;
						case 5:
							strcpy(mes, "Mayo");
							break;
						case 6:
							strcpy(mes, "Junio");
							break;
						case 7:
							strcpy(mes, "Julio");
							break;
						case 8:
							strcpy(mes, "Agosto");
							break;
						case 9:
							strcpy(mes, "Septiembre");
							break;
						case 10:
							strcpy(mes, "Octubre");
							break;
						case 11:
							strcpy(mes, "Noviembre");
							break;
						case 12:
							strcpy(mes, "Diciembre");
							break;
					}

					printf("\n|%-*s|%-*s|%-*d|%-*f|\n", w[0], mes, w[1], tipo, w[2], eArrRecauda[i].estado, w[3],eArrRecauda[i].importe);

					exito = utn_getCharDosOpciones(&afirmaEliminar, "\n?Desea eliminar al contribuyente? (S / N): ", "Error.", 's', 'n', 3);
					if(exito == 0)
					{
						switch(afirmaEliminar)
						{
							case 's':
								eliminarContribuyente(eArr,largoArr,idContribuyente);
								eliminarRecauda(eArrRecauda[i]);
								exitoFuncion = 0;
								break;
							case 'n':
								exitoFuncion = 0;
								break;
						}

					}
				}
			}
		}

	}
	return exitoFuncion;
}

int eliminarContribuyente(eContribuyente* eContriArr, int largoArr, int idContri)
{
	int exitoFuncion = -1;
	eContribuyente vacio;

	if(eContriArr != NULL && largoArr > 0)
	{
		int i;
		for (i = 0; i < largoArr; i++)
		{
			if(eContriArr[i].id == idContri)
			{
				eContriArr[i] = vacio;
				eContriArr[i].isEmpty = 1;
				exitoFuncion = 0;
			}
		}
	}
	return exitoFuncion;
}

// GET ID
int getIdContribuyente(eContribuyente* eContriArr, int largoArr, int* idContri)
{
	int exitoFuncion = -1;
	int auxId = -1;

	if(eContriArr != NULL && largoArr > 0)
	{
		int exito = utn_getNumber(&auxId, "Ingrese ID del contribuyente: ", "-- Error de carga. ", MAX_ERRORES);

		if(exito == 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eContriArr[i].id == auxId)
				{
					*idContri = auxId;
					exitoFuncion = 0;
					break;
				}
			}

			if(auxId == -1)
			{
				printf("--- ?NO SE ENCONTRO CONTRIBUYENTE! ---");
			}
		}
		else
		{
			printf("--- ?MUCHOS ERRORES! ---");
		}
	}

	return exitoFuncion;
}














