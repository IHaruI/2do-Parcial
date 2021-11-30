#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"

int validarEntero(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[0] == '+' || cadena[0] == '-')
			{
				i++;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

int myGets (char* cadena, int longitud)
{
	int retorno = -1;

	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		do
		{
			printf("%s", mensaje);

			if(getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferInt[500];

	if(pResultado != NULL)
	{
		if(myGets(bufferInt, sizeof(bufferInt)) == 0 && validarEntero(bufferInt) == 1)
		{
			*pResultado = atoi(bufferInt);
			retorno = 0;
		}
	}
	return retorno;
}
