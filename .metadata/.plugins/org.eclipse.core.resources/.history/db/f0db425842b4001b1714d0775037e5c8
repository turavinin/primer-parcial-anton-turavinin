#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "bibliotecaUTN-validaciones.h"
#include "eContribuyente.h"
#include "eRecaudacion.h"
#define LARGO_ARR 50

int main(void) {
	setbuf(stdout, NULL);

	// Variables
	int exitoFuncion;
	int opcionMenu;
	int existeProximoLibre;
	char salida;

	// Banderas
	int exiteProxContri;
	int exiteProxRecauda;
	int banderaAltaContri = 0;

	// Declara array
	eContribuyente arrContri[LARGO_ARR];
	eRecaudacion arrRecauda[LARGO_ARR];

	// INIT
	initContribuyente(arrContri, LARGO_ARR);
	initRecaudacion(arrRecauda, LARGO_ARR);

	// MENU
	do
	{
		exitoFuncion = utn_getNumberLimited(&opcionMenu,
						"\n--------------- MENU --------------- "
						"\n 1. ALTA CONTRIBUYENTE"
						"\n 2. MODIFICAR DATOS CONTRIBUYENTE"
						"\n 3. BAJA DE CONTRIBUYENTE"
						"\n 4. RECAUDACION"
						"\n 5. REFINANCIAR RECAUDACION"
						"\n 6. SALDAR RECAUDACION"
						"\n 7. IMPRIMIR CONTRIBUYENTE"
						"\n 8. IMPRIMIR RECAUDACION"
						"\n 0. SALIR"
						"\nSeleccione una opción (Ingrese su numero): ",
						"\n--- ¡LA OPCION INGRESADA ES INCORRECTA! --- \n",
						1, 9, 3);


		if(exitoFuncion == 0)
		{
			switch(opcionMenu)
			{
				case 1:
					exitoFuncion = altaContribuyente(arrContri, LARGO_ARR, &exiteProxContri);


					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 0:
					break;
			}
		}





	} while(opcionMenu != 0);

	return EXIT_SUCCESS;
}
