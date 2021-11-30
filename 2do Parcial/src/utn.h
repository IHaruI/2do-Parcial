#ifndef UTN_H_
#define UTN_H_

/// @fn int validarEntero(char*)
/// @brief Valida si lo que se ingreso es solo numeros
/// @param cadena A ser validada
/// @return 1 si esta ok
int validarEntero(char* cadena);

/// @fn int myGets(char*, int)
/// @brief Cambia el \n por el \0
/// @param cadena El cual copiara la cadena obtenida
/// @param longitud De la cadena
/// @return o si esta ok
int myGets(char* cadena, int longitud);

/// @fn int utn_getNumero(int*, char*, char*, int, int, int)
/// @brief Valida el numero ingresado por el usuario
/// @param pResultado Puntero que definira el resultado de la opcion tomada del usuario
/// @param mensaje Pasado por parametro
/// @param mensajeError Pasado por parametro
/// @param minimo Hasta donde se acepta
/// @param maximo Hasta donde se acepta
/// @param reintentos
/// @return o si esta ok
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @fn int getInt(int*)
/// @brief Obtiene un entero de una cadena
/// @param pResultado Resultado de la funcion
/// @return 1 si esta ok
int getInt(int* pResultado);

#endif
