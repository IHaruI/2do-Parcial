#ifndef PARSER_H_
#define PARSER_H_

/// @fn int parser_BooxsFromText(FILE*, LinkedList*)
/// @brief Parsea los datos de los libros desde el archivo Libros.csv (modo texto).
/// @param pFile Puntero del archivo Libros.csv
/// @param pArrayBooxs Puntero a Linkedlist
/// @return 0 si esta ok
int parser_BooxsFromText(FILE* pFile, LinkedList* pArrayBooxs);

/// @fn int parser_EditorialsFromText(FILE*, LinkedList*)
/// @brief Parsea los datos de los editoriales desde el archivo Editoriales.csv (modo binario).
/// @param pFile Puntero del archivo Editoriales.csv
/// @param listaEditoriales Puntero a Linkedlist
/// @return 0 si esta ok
int parser_EditorialsFromText(FILE* pFile, LinkedList* listaEditoriales);

#endif
