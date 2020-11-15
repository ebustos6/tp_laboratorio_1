#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
	LinkedList* this= NULL;
	    this = (LinkedList*)malloc(sizeof(LinkedList));
	    if(this != NULL){
	    	this->pFirstNode = NULL;
	    	this->size = 0;
	    }
	    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this -> size;
    }

    return returnAux;
}


static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		pNode = this-> pFirstNode;
		for(i = 0; i < nodeIndex; i++){
			pNode = pNode -> pNextNode;
		}
	}
    return pNode;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
    	nuevoNodo = (Node*)malloc(sizeof(Node));
    	if(nuevoNodo != NULL){

    		nuevoNodo -> pElement = pElement;
    		if(nodeIndex == 0){

    			nuevoNodo -> pNextNode = this-> pFirstNode;
    			this-> pFirstNode = nuevoNodo;
    		}
    		else{
    			nuevoNodo-> pNextNode = getNode(this, nodeIndex);
    			(getNode(this, nodeIndex-1))->pNextNode = nuevoNodo;
    		}
    		this-> size++;
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	addNode(this,ll_len(this),pElement);
    	returnAux = 0;
    }

    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	returnAux = (getNode(this,index))->pElement;
    }
    return returnAux;
}


int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;
	Node* pNode;

	if(this != NULL && index >= 0 && index < ll_len(this)){
	    	pNode = getNode(this, index);
	    	if(pNode != NULL){
	    		pNode->pElement = pElement;
	    		returnAux = 0;
	    	}
	    }
	    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
		Node *pAuxNode;
		Node *pPrevNode;

		if (this != NULL && index < ll_len(this) && index >= 0)
			{
				pAuxNode = getNode(this, index);
				if (pAuxNode != NULL )
				{
					if (index == 0)
					{
						this->pFirstNode = pAuxNode->pNextNode;
					} else {
						pPrevNode = getNode(this, index - 1);
						if (pPrevNode != NULL)
						{
							pPrevNode->pNextNode = pAuxNode->pNextNode;
						}
					}
					this->size--;
					free(pAuxNode);
					returnAux = 0;
				}
			}
			return returnAux;
}


int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	while (ll_len( this)){
    		ll_remove(this, 0);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        	if(!ll_clear(this))
        	{
        		free(this);
        		returnAux = 0;
        	}
        }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux = -1;

	    if (this != NULL)
	    {
	    	for (int i = 0; i < ll_len(this); i++)
	    	{
	    		if (ll_get(this, i) == pElement)
	    		{
	    				returnAux = i;
	    				break;
	    		}
	    	}
	    }
	    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 0;
    	if(!ll_len(this)){
    		returnAux = 1;
    	}
    }
    return returnAux;

    // se puede reemplazar el segundo if por un condicional lineal
    // returnAux = ll_len(this)? 0 : 1;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(index >= 0 && index <= ll_len(this)){
    		returnAux = addNode(this,index,pElement);
    	}
    }
    return returnAux;

    // return addNode(this,index,pElement);
}


void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	returnAux = (void*)ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(ll_indexOf(this,pElement)>= 0){
    		returnAux = 1;
    	}
    	else{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;

    if(this != NULL && this2 != NULL){

    	returnAux = 1;
    	for(i=0;i<ll_len(this2);i++){
    		if(!ll_contains(this,ll_get(this2,i))){
    		    returnAux = 0;
    		    break;
    		}
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

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
    int returnAux =-1;

    return returnAux;

}

