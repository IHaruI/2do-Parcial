#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"

int controller_LoadFromTextBooxs(char* path, LinkedList* listaLibros)
{
	FILE* pFile;
	int retorno = -1;

	if(path != NULL && listaLibros != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL && ll_isEmpty(listaLibros) == 1)
		{
			if(parser_BooxsFromText(pFile, listaLibros) == 0)
			{
				printf("\nSe ha cargado correctamente el archivo.");
				retorno = 0;
			}
			else
			{
				printf("\nError, no se ha podido cargar el archivo\n");
			}
		}
		fclose(pFile);
	}
    return retorno;
}

int controller_LoadFromTextEditorials(char* path, LinkedList* listaEditoriales)
{
	FILE* pFile;
	int retorno = -1;

	if(path != NULL && listaEditoriales != NULL)
	{
		pFile = fopen(path, "r");

		if(pFile != NULL && ll_isEmpty(listaEditoriales) == 1)
		{
			if(parser_EditorialsFromText(pFile, listaEditoriales) == 0)
			{
				printf("\nSe ha cargado correctamente el archivo.");
				retorno = 0;
			}
			else
			{
				printf("\nError, no se ha podido cargar el archivo\n");
			}
		}
		fclose(pFile);
	}
    return retorno;
}

int controller_sortBooxs(LinkedList* listaLibros)
{
	int retorno = -1;

	if(listaLibros != NULL)
	{
		if(ll_sort(listaLibros, boox_sortByAutor, 1) == 0)
		{
			printf("\nSe ha ordenado correctamente\n");
			retorno = 0;
		}
	}
	return retorno;
}

int controller_ListBooxs(LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	eLibro* pLibro = NULL;
	int retorno = -1;
	int auxid;
	char auxTitulo[70];
	char auxAutor[70];
	int auxPrecio;
	int auxIdEditorial;
	char nombreEditorial[70];
	int len;

	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		len = ll_len(listaLibros);

		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|  ID  |                       TITULO                       |             AUTOR              |   PRECIO   |  ID EDIT.  |     EDITORIALES      |\n");
		printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

		for(int i = 0; i < len; i++)
		{
			pLibro = ll_get(listaLibros, i);

			if(!boox_getId(pLibro, &auxid) && !boox_getTitulo(pLibro, auxTitulo) && !boox_getAutor(pLibro, auxAutor) && !boox_getPrecio(pLibro, &auxPrecio) && !boox_getIdEditorial(pLibro, &auxIdEditorial) && !controller_nombreEditorial(auxIdEditorial, nombreEditorial, listaEditoriales))
			{
				printf("|%5d | %50s | %30s | %10d | %10d | %20s |\n", auxid, auxTitulo, auxAutor, auxPrecio, auxIdEditorial, nombreEditorial);
				printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_nombreEditorial(int id, char* nombreEditorial, LinkedList* listaEditoriales)
{
	int retorno = -1;
	eEditorial* editorial = NULL;
	int auxidEditorial;
	int len;

	if(listaEditoriales != NULL && nombreEditorial != NULL)
	{
		len = ll_len(listaEditoriales);

		for(int i = 0; i < len; i++)
		{
			editorial = ll_get(listaEditoriales, i);
			editorials_getId(editorial, &auxidEditorial);

			if(id == auxidEditorial)
			{
				editorials_getNombre(editorial, nombreEditorial);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_saveAsText(char* path, LinkedList* listaLibros, LinkedList* listaEditoriales)
{
	eLibro* pLibro = NULL;
	int retorno = -1;
	int auxid;
	char auxTitulo[70];
	char auxAutor[70];
	int auxPrecio;
	int auxIdEditorial;
	char nombreEditorial[70];
	int len;

	if(path != NULL && listaLibros != NULL)
	{
		FILE* pFile = fopen(path, "w");

		if(pFile != NULL)
		{
			len = ll_len(listaLibros);

			fprintf(pFile, "id,titulo,autor,precio,idEditorial,editoriales\n");

			for(int i = 0; i < len; i++)
			{
				pLibro = ll_get(listaLibros, i);

				if(boox_getId(pLibro, &auxid) == 0 && boox_getPrecio(pLibro, &auxPrecio) == 0 && boox_getIdEditorial(pLibro, &auxIdEditorial) == 0 && boox_getTitulo(pLibro, auxTitulo) == 0 && boox_getAutor(pLibro, auxAutor) == 0 && controller_nombreEditorial(auxIdEditorial, nombreEditorial, listaEditoriales) == 0)
				{
					fprintf(pFile, "%d,%s,%s,%d,%d,%s\n", auxid, auxTitulo, auxAutor, auxPrecio, auxIdEditorial, nombreEditorial);
					retorno = 0;
				}
			}
			if(retorno == 0)
			{
				printf("\nSe ha guardado correctamente los archivo.\n");
			}
		}
		fclose(pFile);
	}
	return retorno;
}

int controller_mapeado(LinkedList* listaLibros)
{
	int retorno = -1;

	ll_map(listaLibros, boox_descuento);

	if(!controller_saveAsTextDiscount(listaLibros, "Mapeado.csv"))
	{
		printf("\nSe ha guardado correctamente los archivo.\n");
		retorno = 0;
	}
	return retorno;

}

int controller_saveAsTextDiscount(LinkedList* listaLibros, char* listaMapeado)
{
	FILE* pFile;
	int retorno = -1;
	int idLibro;
	char titulo[70];
	char autor [70];
	int precio;
	int idEditorial;
	int len;

	eLibro* pLibro = NULL;

	if(listaLibros != NULL && listaMapeado != NULL)
	{
		pFile = fopen(listaMapeado, "w");

		if(pFile != NULL)
		{
			len = ll_len(listaLibros);

			fprintf(pFile, "id,titulo,autor,precio,idEditorial\n");

			for(int i = 0; i < len; i++)
			{
				pLibro = (eLibro*) ll_get(listaLibros, i);

				if(	pLibro != NULL && getBooxs(pLibro, &idLibro, titulo, autor, &precio, &idEditorial) == 0)
				{
					fprintf(pFile, "%d,%s,%s,%d,%d\n", idLibro, titulo, autor, precio, idEditorial);
					retorno = 0;
				}
			}
			fclose(pFile);
		}
	}
	return retorno;
}
