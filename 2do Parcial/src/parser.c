#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"

int parser_BooxsFromText(FILE* pFile, LinkedList* listaLibros)
{
	eLibro* pLibro;
	int retorno = -1;
	int cantidad;
	char id[70];
	char titulo[70];
	char autor[70];
	char precio[70];
	char idEditorial[70];

	if(pFile != NULL && listaLibros != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);

		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);

			if(cantidad == 5)
			{
				pLibro = boox_newParametros(id, titulo, autor, precio, idEditorial);

				if(pLibro != NULL)
				{
					retorno = ll_add(listaLibros, pLibro);
				}
			}
			else
			{
				printf("\nError.");
			}
		}while(!feof(pFile));
	}
	return retorno;
}

int parser_EditorialsFromText(FILE* pFile, LinkedList* listaEditoriales)
{
	eEditorial* pEditoral;
	int retorno = -1;
	int cantidad;
	char nombre[70];
	char idEditorial[70];

	if(pFile != NULL && listaEditoriales != NULL)
	{
		fscanf(pFile,"%[^,],%[^\n]\n", idEditorial, nombre);

		do
		{
			cantidad = fscanf(pFile,"%[^,],%[^\n]\n", idEditorial, nombre);

			if(cantidad == 2)
			{
				pEditoral = editorials_newParametros(idEditorial, nombre);

				if(pEditoral != NULL)
				{
					retorno = ll_add(listaEditoriales, pEditoral);
				}
				else
				{
					printf("\nError.");
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}
