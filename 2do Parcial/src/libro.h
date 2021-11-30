#ifndef LIBRO_H_
#define LIBRO_H_

#include "Linkedlist.h"

typedef struct
{
	int id;
	char titulo[70];
	char autor[70];
	int precio;
	int idEditorial;
}eLibro;

eLibro* boox_new();
eLibro* boox_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);

int boox_setId(eLibro* this, int id);
int boox_getId(eLibro* this, int* id);

int boox_setTitulo(eLibro* this, char* titulo);
int boox_getTitulo(eLibro* this, char* titulo);

int boox_setAutor(eLibro* this, char* autor);
int boox_getAutor(eLibro* this, char* autor);

int boox_setPrecio(eLibro* this, int precio);
int boox_getPrecio(eLibro* this, int* precio);

int boox_setIdEditorial(eLibro* this, int idEditorial);
int boox_getIdEditorial(eLibro* this, int* idEditorial);

int boox_sortByAutor(void* boox1, void* boox2);
int boox_minotauro(void* element);

#endif /* LIBRO_H_ */
