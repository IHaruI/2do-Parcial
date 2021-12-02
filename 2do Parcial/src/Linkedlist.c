#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "libro.h"
#include "editorial.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));  //Recerva espacio en memoria.

    if(this != NULL)
    {
    	this->size = 0; //Tamaño de esta lista es 0
    	this->pFirstNode = NULL;  //La lista esta vacia.
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
    	pNode = this->pFirstNode;

        for(int i = 0; i < nodeIndex; i++)
        {
        	pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
	Node *nuevoNodo;
	Node *anterior;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	nuevoNodo = (Node*) malloc(sizeof(Node));

		if(nuevoNodo != NULL)
		{
			if(nodeIndex == 0)
			{
				nuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nuevoNodo;
			}
			else
			{
				anterior = getNode(this, nodeIndex - 1);

				if(anterior != NULL)
				{
					nuevoNodo->pNextNode = anterior->pNextNode;
					anterior->pNextNode = nuevoNodo;
				}
			}
			this->size++;
			nuevoNodo->pElement = pElement;
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    return addNode(this, nodeIndex, pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	returnAux = addNode(this, len, pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodo = getNode(this, index);
    	returnAux = pNodo->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	pNode->pElement = pElement;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux = -1;
    Node* anterior;
    Node* siguiente;
    Node* actual;

    if(this != NULL && index >= 0 && index < ll_len(this) && (actual = getNode(this, index)) != NULL)
    {
    	siguiente = actual->pNextNode;
    	actual->pNextNode = NULL;

    	if(index == 0)
    	{
    		this->pFirstNode = siguiente;
    	}
    	else if((anterior = getNode(this, index - 1)) != NULL)
    	{
    		anterior->pNextNode = siguiente;
    	}
    	free(actual);
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;

    if(this != NULL)
    {
    	if((len = ll_len(this) > 0))
    	{
    		for(i = len - 1; i >= 0; i--)
    		{
    			if(ll_remove(this, i) == 0)
    			{
    				returnAux = 0;
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
		{
			free(this);
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	if((len = ll_len(this)) > 0)
    	{
    		for(int i = 0; i < len; i++)
    		{
    			if(ll_get(this, i) == pElement)
    			{
    				returnAux = i;
    				break;
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 1;

    	if(ll_len(this))
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	if((len = ll_len(this)) >= 0 && index <= len && index >= 0)
    	{
    		if(addNode(this, index, pElement) == 0)
    		{
    			returnAux = 0;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len;

    if(this != NULL)
    {
    	if((len = ll_len(this)) > 0 && index < len && index >= 0)
		{
			returnAux = ll_get(this, index);
			ll_remove(this, index);
		}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void* Auxthis2;

    if(this != NULL && this2 != NULL)
    {
    	if((len = ll_len(this2)) > 0)
    	{
    		for(int i = 0; i < len; i++)
    		{
    			Auxthis2 = ll_get(this2, i);
    			returnAux = ll_contains(this, Auxthis2);

    			if(returnAux == 0)
    			{
    				break;
    			}
    		}
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* AuxLinkedList;
    void* pElement;

    AuxLinkedList = ll_newLinkedList();

    if(this != NULL && AuxLinkedList != NULL && from >= 0 && from < ll_len(this) && to > 0 && to <= ll_len(this))
    {
    	for(int i = from; i < to; i++)
    	{
    		pElement = ll_get(this, i);
    		ll_add(AuxLinkedList, pElement);
    	}
    	cloneArray = AuxLinkedList;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int len;
    void* pElement1;
    void* pElement2;
    int estado = 1;
    int aux;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	len = ll_len(this) - 1;

    	while(estado)
    	{
    		estado = 0;

    		for(int i = 0; i < len; i++)
    		{
    			pElement1 = ll_get(this, i);
    			pElement2 = ll_get(this, i + 1);
    			aux = pFunc(pElement1, pElement2);

    			if((order == 0 && aux < 0) || (order == 1 && aux > 0))
    			{
    				ll_set(this, i, pElement2);
    				ll_set(this, i + 1, pElement1);
    				estado = 1;
    			}
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief  Generará la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá.
 * \param pList Puntero a la lista
 * \param fn (*fn) Recibirá una lista y una función criterio
 * \param element void
 * \return int Retorna Puntero

 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	eLibro* pLibro;
	LinkedList* minotauro = NULL;
	int len;

	if(this != NULL && (len = ll_len(this)) > 0)
	{
		minotauro = ll_newLinkedList();

		if(minotauro != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				pLibro = ll_get(this, i);

				if(!fn(pLibro))
				{
					ll_add(minotauro, pLibro);
				}
			}
		}
	}
	return minotauro;
}

/// @fn int ll_map(LinkedList*, int(*)(void*))
/// @brief Mapea los elementos de la lista mediante la funcion criterio pasada por parametro
/// @param lista Puntero a la lista
/// @param fn Puntero a la funcion criterio
/// @return 0 si esta ok
int ll_map(LinkedList* lista, int (*fn) (void*))
{
	int retorno = -1;

	void* pElement = NULL;

	if(lista != NULL)
	{
		for(int i = 0; i < ll_len(lista); i++)
		{
			pElement = ll_get(lista, i);

			fn(pElement);
		}
		retorno = 0;
	}
	return retorno;
}
