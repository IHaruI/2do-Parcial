#ifndef CONTROLLER_H_
#define CONTROLLER_H_

///
/// @fn int controller_LoadFromTextBooxs(char*, LinkedList*)
/// @brief Se carga los datos de Libros.csv
/// @param path Puntero al archivo a cargar
/// @param listaLibros Puntero a linkedList
/// @return 0 si esta ok.
int controller_LoadFromTextBooxs(char* path, LinkedList* listaLibros);

/// @fn int controller_LoadFromTextEditorials(char*, LinkedList*)
/// @brief Se carga los datos de Editoriales.csv
/// @param path Puntero al archivo a cargar
/// @param listaEditoriales LinkedList*
/// @return 0 si esta ok
int controller_LoadFromTextEditorials(char* path, LinkedList* listaEditoriales);

/// @fn int controller_sortBooxs(LinkedList*)
/// @brief Ordena los libros por autor
/// @param listaLibros LinkedList*
/// @return 0 si esta ok
int controller_sortBooxs(LinkedList* listaLibros);

/// @fn int controller_ListBooxs(LinkedList*, LinkedList*)
/// @brief Listar libros
/// @param listaLibros Linkedlist*
/// @param listaEditoriales LinkedList*
/// @return 0 si esta ok
int controller_ListBooxs(LinkedList* listaLibros, LinkedList* listaEditoriales);

/// @fn int controller_nombreEditorial(int, char*, LinkedList*)
/// @brief Recibe un ID y obtiene el nombre correspondiente al ID pasado por parametro
/// @param id El cual sirve para encontrar en nombre de la editorial
/// @param nombreEditorial Nombre de la editorial
/// @param listaEditoriales Linkdelist*
/// @return 0 si esta ok
int controller_nombreEditorial(int id, char* nombreEditorial, LinkedList* listaEditoriales);

/// @fn int controller_saveAsText(char*, LinkedList*, LinkedList*)
/// @brief Se guarda los datos en Minotauro.csv
/// @param path Puntero al archivo a guardar
/// @param listaLibros Linkedlist*
/// @param listaEditoriales Linkedlist*
/// @return 0 si esta ok
int controller_saveAsText(char* path, LinkedList* listaLibros, LinkedList* listaEditoriales);

int controller_mapeado (LinkedList* listaLibros);

int controller_saveAsTextDiscount(LinkedList* listaLibros, char* listaMapeado);

#endif /* CONTROLLER_H_ */
