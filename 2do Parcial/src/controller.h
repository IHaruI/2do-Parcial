#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_LoadFromTextBooxs(char* path, LinkedList* listaLibros);

int controller_LoadFromTextEditorials(char* path, LinkedList* listaEditoriales);

int controller_sortBooxs(LinkedList* listaLibros);

int controller_ListBooxs(LinkedList* listaLibros, LinkedList* listaEditoriales);

int controller_nombreEditorial(int id, char* nombreEditorial, LinkedList* listaEditoriales);

int controller_saveAsText(char* path, LinkedList* listaLibros, LinkedList* listaEditoriales);

#endif /* CONTROLLER_H_ */
