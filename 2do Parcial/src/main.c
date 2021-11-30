/*
 ============================================================================
 Name        : 2do.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int banderaLibros = 0;
	int banderaEditorial = 0;
	char nombre[70];
	LinkedList* listaLibros = ll_newLinkedList();
	LinkedList* listaEditoriales = ll_newLinkedList();
	LinkedList* listaMinotauro = NULL;

	do
	{
		utn_getNumero(&opcion, "\n1. Cargar archivos de libros\n2. Cargar archivos de editoriales\n3. Listar libros por autor\n4. Mostrar todos los datos mas el nombre de la editorial\n5. Listado de los libros Minotauro\n6. Salir\n\nIngrese unas de las opciones dadas: ", "\nError, Ingrese una de las opciones mostradas.", 1, 7, 3);

		switch(opcion)
		{
			case 1:
				printf("\nIngrese el nombre del archivos a cargar (Libros.cvs): ");
				gets(nombre);

				if(stricmp(nombre, "Libros.csv") == 0)
				{
					if(controller_LoadFromTextBooxs(nombre, listaLibros) == 0)
					{
						banderaLibros = 1;
					}
				}
				else
				{
					printf("\nError, nombre del archivo incorrecto.");
				}
				break;

			case 2:
				printf("\nIngrese el nombre del archivos a cargar (Editoriales.cvs): ");
				gets(nombre);

				if(stricmp(nombre, "Editoriales.csv") == 0)
				{
					if(controller_LoadFromTextEditorials(nombre, listaEditoriales) == 0)
					{
						banderaEditorial = 1;
					}
				}
				else
				{
					printf("\nError, nombre del archivo incorrecto.");
				}
				break;

			case 3:
				if(banderaLibros == 1)
				{
					controller_sortBooxs(listaLibros);
				}
				else
				{
					printf("\nError, cargar datos de la opcion 1\n");
				}
				break;

			case 4:
				if(banderaLibros == 1 && banderaEditorial == 1)
				{
					controller_ListBooxs(listaLibros, listaEditoriales);
				}
				else
				{
					printf("\nError, cargar datos de la opcion 1 y 2\n");
				}
				break;

			case 5:
				if(banderaLibros == 1 && banderaEditorial == 1)
				{
					listaMinotauro = ll_filter(listaLibros, boox_minotauro);

					controller_saveAsText("Minotauro.csv", listaMinotauro, listaEditoriales);
				}
				else
				{
					printf("\nError, cargar datos de la opcion 1 y 2\n");
				}
				break;
		}
	}while(opcion != 6);
}
