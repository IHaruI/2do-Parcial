#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"

eLibro* boox_new()
{
	eLibro* pLibro = (eLibro*) malloc(sizeof(eLibro));

	if(pLibro != NULL)
	{
		pLibro->id = 0;
		strcpy(pLibro->titulo, "");
		strcpy(pLibro->autor, "");
		pLibro->precio = 0;
		pLibro->idEditorial = 0;
	}
	return pLibro;
}

eLibro* boox_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro* pLibro = boox_new();

	if(pLibro != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL)
	{
		boox_setId(pLibro, atoi(idStr));
		boox_setTitulo(pLibro, tituloStr);
		boox_setAutor(pLibro, autorStr);
		boox_setPrecio(pLibro, atof(precioStr));
		boox_setIdEditorial(pLibro, atoi(idEditorialStr));
	}
	return pLibro;
}

int boox_setId(eLibro* this, int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int boox_getId(eLibro* this, int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int boox_setTitulo(eLibro* this, char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}
	return retorno;
}
int boox_getTitulo(eLibro* this, char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo, this->titulo);
		retorno = 0;
	}
	return retorno;
}

int boox_setAutor(eLibro* this, char* autor)
{
	int retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}
	return retorno;
}
int boox_getAutor(eLibro* this, char* autor)
{
	int retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(autor, this->autor);
		retorno = 0;
	}
	return retorno;
}

int boox_setPrecio(eLibro* this, float precio)
{
	int retorno = -1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
int boox_getPrecio(eLibro* this, float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int boox_setIdEditorial(eLibro* this, int idEditorial)
{
	int retorno = -1;

	if(this != NULL && idEditorial >= 0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}
int boox_getIdEditorial(eLibro* this, int* idEditorial)
{
	int retorno = -1;

	if(this != NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

int boox_sortByAutor(void* boox1, void* boox2)
{
	int retorno = -1;
	char nombre1[70];
	char nombre2[70];

	if(boox1 != NULL && boox2 != NULL)
	{
		if(!boox_getAutor(boox1, nombre1) && !boox_getAutor(boox2, nombre2))
		{
			if(stricmp(nombre1, nombre2) > 0)
			{
				retorno = 1;
			}
			if(stricmp(nombre1, nombre2) < 0)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int boox_minotauro(void* element)
{
	int retorno = -1;
	eLibro* pLibro;

	pLibro = (eLibro*) element;

	if(pLibro->idEditorial == 4)
	{
		retorno = 0;
	}
	return retorno;
}

int boox_descuento(void* element)
{
	eLibro* libro = NULL;
	int retorno = -1;
	int idEditorial;
	float precio;
	int descuento;

	if (element != NULL)
	{
		libro = (eLibro*) element;

		if(boox_getIdEditorial(libro, &idEditorial) == 0 && boox_getPrecio(libro, &precio) == 0)
		{
			if(idEditorial == 1 && precio >= 300)
			{
				descuento = precio * 0.8;

				boox_setPrecio(libro, descuento);
			}
			else if(idEditorial == 2 && precio <= 200)
			{
				descuento = precio * 0.9;

				boox_setPrecio(libro, descuento);
			}
			retorno = 0;
		}
	}
	return retorno;
}
