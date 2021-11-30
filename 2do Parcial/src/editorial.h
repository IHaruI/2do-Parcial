#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
    int idEditorial;
    char nombre[128];
}eEditorial;

eEditorial* editorials_new();

eEditorial* editorials_newParametros(char *idStr, char *nombreStr);

int editorials_setId(eEditorial* this, int id);

int editorials_setNombre(eEditorial* this, char* nombre);

int editorials_getId(eEditorial* this, int* idEditorial);

int editorials_getNombre(eEditorial* this, char* nombre);

#endif
