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

/// @fn eLibro boox_new*()
/// @brief Recerva espacio en memoria y se inicializa las variables
/// @return Puntero
eLibro* boox_new();

/// @fn eLibro boox_newParametros*(char*, char*, char*, char*, char*)
/// @brief Coloca libros con parametros
/// @param idStr Recibe id del libro
/// @param tituloStr Recibe el titulo del libro
/// @param autorStr Recibe el auto del libro
/// @param precioStr Recibe el precio del libro
/// @param idEditorialStr Recibe id del editorial
/// @return Puntero
eLibro* boox_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);

/// @fn int boox_setId(eLibro*, int)
/// @brief Coloca el id al libro
/// @param this Puntero al libro
/// @param id Pasado por el libro
/// @return 0 si esta ok
int boox_setId(eLibro* this, int id);

/// @fn int boox_getId(eLibro*, int*)
/// @brief Obtiene el ID del libro
/// @param this eLibro*
/// @param id La cual obtiene el ID
/// @return 0 si esta ok
int boox_getId(eLibro* this, int* id);

/// @fn int boox_setTitulo(eLibro*, char*)
/// @brief Coloca el titulo al libro
/// @param this eLibro*
/// @param titulo Pasado por el libro
/// @return 0 si esta ok
int boox_setTitulo(eLibro* this, char* titulo);

/// @fn int boox_getTitulo(eLibro*, char*)
/// @brief Obtiene el titutlo del libro
/// @param this eLibro*
/// @param titulo La cual obtiene el titulo
/// @return 0 si esta ok
int boox_getTitulo(eLibro* this, char* titulo);

/// @fn int boox_setAutor(eLibro*, char*)
/// @brief Coloca el autor al libro
/// @param this eLibro*
/// @param autor Pasado por el libro
/// @return 0 si esta ok
int boox_setAutor(eLibro* this, char* autor);

/// @fn int boox_getAutor(eLibro*, char*)
/// @brief Obtiene el autor del libro
/// @param this eLibro*
/// @param autor La cual obtiene el autor
/// @return 0 si esta ok
int boox_getAutor(eLibro* this, char* autor);

/// @fn int boox_setPrecio(eLibro*, int)
/// @brief Coloca el precio al libro
/// @param this eLibro*
/// @param precio Pasado por el libro
/// @return 0 si esta ok
int boox_setPrecio(eLibro* this, int precio);

/// @fn int boox_getPrecio(eLibro*, int*)
/// @brief Obtiene el precio del libro
/// @param this eLibro*
/// @param precio La cual obtiene el precio
/// @return 0 si esta ok
int boox_getPrecio(eLibro* this, int* precio);

/// @fn int boox_setIdEditorial(eLibro*, int)
/// @brief Coloca el Id de Editorial al libro
/// @param this eLibro*
/// @param idEditorial Pasado por el libro
/// @return 0 si esta ok
int boox_setIdEditorial(eLibro* this, int idEditorial);

/// @fn int boox_getIdEditorial(eLibro*, int*)
/// @brief Obtiene el Id de Editorial del libro
/// @param this eLibro*
/// @param idEditorial La cual obtiene el Id de editorial
/// @return 0 si esta ok
int boox_getIdEditorial(eLibro* this, int* idEditorial);

/// @fn int boox_sortByAutor(void*, void*)
/// @brief Compara los autores de los libros
/// @param boox1 El primer libro (autor) a comparar
/// @param boox2 El segundo libro (autor) a comparar
/// @return 1 si el primero es mayor que el segundo, -1 si es viseversa
int boox_sortByAutor(void* boox1, void* boox2);

/// @fn int boox_minotauro(void*)
/// @brief Se busca a los que tengan editoriales Minotauro
/// @param element Recibe pLibro a travez de parametro
/// @return 0 si esta ok
int boox_minotauro(void* element);

#endif
