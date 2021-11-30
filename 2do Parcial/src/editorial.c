#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"

eEditorial* editorials_new()
{
	eEditorial* pEditorial = (eEditorial*) malloc(sizeof(eEditorial));

	if(pEditorial != NULL)
	{
		pEditorial->idEditorial = 0;
		strcpy(pEditorial->nombre, "");
	}
	return pEditorial;
}

eEditorial* editorials_newParametros(char *idStr, char *nombreStr)
{
	eEditorial* pEditorial = editorials_new();

	if(pEditorial != NULL && idStr != NULL && nombreStr != NULL)
	{
		editorials_setId(pEditorial, atoi(idStr));
		editorials_setNombre(pEditorial, nombreStr);
	}
	return pEditorial;
}

int editorials_setId(eEditorial* this, int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->idEditorial = id;
		retorno = 0;
	}
	return retorno;
}

int editorials_setNombre(eEditorial* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int editorials_getId(eEditorial* this, int* idEditorial)
{
	int retorno = -1;

	if(this != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

int editorials_getNombre(eEditorial* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
