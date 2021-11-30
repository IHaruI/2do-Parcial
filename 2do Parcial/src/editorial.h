#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
    int idEditorial;
    char nombre[100];
}eEditorial;

/// @fn eEditorial editorials_new*()
/// @brief Recerva espacio en memoria y se inicializa las variables
/// @return Puntero
eEditorial* editorials_new();

/// @fn eEditorial editorials_newParametros*(char*, char*)
/// @brief Coloca editoriales con parametros
/// @param idStr Recibe id de la editorial
/// @param nombreStr Recibe nombre de la editorial
/// @return Puntero
eEditorial* editorials_newParametros(char *idStr, char *nombreStr);

/// @fn int editorials_setId(eEditorial*, int)
/// @brief Coloca el id a la editorial
/// @param this Puntero a la editorial
/// @param id Pasado por la editorial
/// @return 0 si esta ok
int editorials_setId(eEditorial* this, int id);

/// @fn int editorials_setNombre(eEditorial*, char*)
/// @brief Coloca el nombre a la editorial
/// @param this Puntero a la editorial
/// @param nombre Pasado por la editorial
/// @return 0 si esta ok
int editorials_setNombre(eEditorial* this, char* nombre);

/// @fn int editorials_getId(eEditorial*, int*)
/// @brief Obtiene el ID de la editorial
/// @param this Puntero a la editorial
/// @param idEditorial La cual obtiene el ID
/// @return 0 si esta ok
int editorials_getId(eEditorial* this, int* idEditorial);

/// @fn int editorials_getNombre(eEditorial*, char*)
/// @brief Obtiene el nombre de la editorial
/// @param this Puntero a la editorial
/// @param nombre La cual obtiene el nombre
/// @return 0 si esta ok
int editorials_getNombre(eEditorial* this, char* nombre);

#endif
