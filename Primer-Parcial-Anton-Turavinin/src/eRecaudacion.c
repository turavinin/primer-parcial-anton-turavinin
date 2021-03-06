#include "bibliotecaUTN-validaciones.h"
#include "eRecaudacion.h"


// ID
int idRecaudacion = 100;
void setIdRecaudacion(int* id)
{
	*id = idRecaudacion++;
}

// INIT ESTRUCTURA
int initRecaudacion(eRecaudacion* eArr, int largoArr)
{
	int exitoFuncion = -1;
	eRecaudacion recaudacionNueva;
	if(eArr != NULL && largoArr > 0)
	{
		int i;
		for(i = 0; i < largoArr; i++)
		{
			eArr[i] = recaudacionNueva;
			eArr[i].isEmpty = 1;
		}
		exitoFuncion = 0;
	}
	return exitoFuncion;
}

// ADD
int searchEmptyRecaudacion(eRecaudacion* eArr, int largoArr, int* posLibre)
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

int addRecaudacion(eRecaudacion* eArr, int largoArr, int id, int idContribuyente, int mes, int tipo, int posLibre)
{
	int exitoFuncion = -1;
	if(eArr != NULL && largoArr > 0)
	{
		eArr[posLibre].id = id;
		eArr[posLibre].idContribuyente = idContribuyente;
		eArr[posLibre].mes = mes;
		eArr[posLibre].tipo = tipo;
		eArr[posLibre].isEmpty = 0;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}

int getMes(int* tipoMes)
{
	int exitoFuncion = -1;
	int auxMes;

	int exito = utn_getNumberLimited(&auxMes,
			"\n 1. Enero"
			"\n 2. Febrero"
			"\n 3. Marzo"
			"\n 4. Abril"
			"\n 5. Mayo"
			"\n 6. Junio"
			"\n 7. Julio"
			"\n 8. Agosto"
			"\n 9. Septiembre"
			"\n 10. Octubre"
			"\n 11. Noviembre"
			"\n 12. Diciembre"
			"\nSeleccione una opci?n (Ingrese su numero): ",
			"\n--- ?LA OPCION INGRESADA ES INCORRECTA! --- \n",
			1, 12, 3);

	if(exito == 0)
	{
		*tipoMes = auxMes;
		exitoFuncion = 0;
	}

	return exitoFuncion;
}

int altaRecaudacion(eRecaudacion* eRecaudaArr, int largoArr, int* existenciaProxLibre, int idContri)
{
	int exitoFuncion = -1;
	int posLibre;
	int auxProxLibre = *existenciaProxLibre;
	int exito = searchEmptyRecaudacion(eRecaudaArr, largoArr, &posLibre);

	if(exito == 0)
	{
		// Variable datos
		int mes;
		int tipo;
		float importe;

		if(getMes(&mes) == 0 &&
		   utn_getNumberLimited(&tipo, "\n 1. ARBA\n 2. IIBB\n 3. GANANCIAS\nSeleccione una opci?n (Ingrese su numero): ",
	       "\n--- ?LA OPCION INGRESADA ES INCORRECTA! --- \n", 1, 3, 3) == 0 &&
           utn_getFloat(&importe, "Ingrese importe: ", "-- Error de carga. ", MAX_ERRORES) == 0)
		  {
			int id;
			setIdRecaudacion(&id);
			exito = addRecaudacion(eRecaudaArr, largoArr, id, idContri, mes, tipo, posLibre);
			exitoFuncion = 0;
		}
		else
		{
			exito = -1;
		}

		searchEmptyRecaudacion(eRecaudaArr, largoArr, &auxProxLibre);
		if(auxProxLibre == -1)
		{
			*existenciaProxLibre = auxProxLibre;
		}
	}

	if(exito != 0)
	{
		printf("---- ERROR EN AGREGAR LA RECAUDACION ----");
	}

	return exitoFuncion;
}



// BAJA

int eliminarRecauda(eRecaudacion recauda)
{
	int exitoFuncion = 0;
	recauda.isEmpty = 1;
	return exitoFuncion;
}


// GET ID
int getIdRecauda(eRecaudacion* eRecaudaArr, int largoArr, int* idRecauda)
{
	int exitoFuncion = -1;
	int auxId = -1;

	if(eRecaudaArr != NULL && largoArr > 0)
	{
		int exito = utn_getNumber(&auxId, "Ingrese ID de la recaudacion: ", "-- Error de carga. ", MAX_ERRORES);

		if(exito == 0)
		{
			int i;
			for(i = 0; i < largoArr; i++)
			{
				if(eRecaudaArr[i].id == auxId)
				{
					*idRecauda = auxId;
					exitoFuncion = 0;
					break;
				}
			}

			if(auxId == -1)
			{
				printf("--- ?NO SE ENCONTRO RECAUDACION! ---");
			}
		}
		else
		{
			printf("--- ?MUCHOS ERRORES! ---");
		}
	}

	return exitoFuncion;
}









