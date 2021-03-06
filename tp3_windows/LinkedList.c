#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){

	//-----------------------------------------------------------------
	//Descripcion:
	//**1-Reservo espacio en memoria dinamica para una nueva linkedList
	//**2-Valido que el puntero no sea NULL e inicializo esa linkedList
	//-----------------------------------------------------------------
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
	int returnAux = -1;

	//------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la linkedList no sea NULL
	//**2-Retorno el 'size' de la linkedList
	//------------------------------------------------------
	if(this != NULL){
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
static Node* getNode(LinkedList* this, int nodeIndex){
    Node* pNode = NULL;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el nodeIndex sea mayor o igual a 0
    //**Valido que sea menor al 'size' de la linkedList. (Si el size es 10, entonces el ultimo index es 9. -indices de 0 a 9-)
	//**2-Retorno el 'size' de la linkedList
    //---------------------------------------------------------------------------------------------
    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
    	pNode = this->pFirstNode;

    	for(int i= 0; i<nodeIndex; i++){
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1;
    Node* pNuevoNodo = NULL;
    Node* pAuxNodo = NULL;


	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el nodeIndex sea mayor o igual a 0
    //**Valido que sea menor o igual al 'size' de la linkedList. (Si el size es 10, entonces el ultimo index es 9. Entonces puedo agregar un nodo con index 10)
	//**2-Reservo espacio en memoria dinamica para el nuevo nodo
    //**3-Valido que pNuevoNodo no sea NULL y lo inicializo.

    //**4-SI EL INDEX ES 0:
    //**** El contenido de this->pFirstNode (direccion del primer nodo), se asigna a pNuevoNodo->pNextNode (direccion del nodo que ahora sera el primero)
    //**** La direccion de memoria de pNuevoNodo se asigna a this->pFirstNode
    //**** Le asigno el elemento al nodo agregado. Aumento el 'size' de la LinkedList y retorno 0.

    //**5-SI EL INDEX NO ES 0:
    //**** En este caso utilizo un nodo auxiliar. Al cual le asigno la direccion de memoria del nodo anterior
    //**** A pNuevoNodo->pNextNode le asigno el valor de pNextNode del nodo anterior (pAuxNodo).
    //**** Al nodo anterior (pAuxNodo), le asigno en su campo pNextNode la direccion de memoria del nodo nuevo
    //**** Le asigno el elemento al nodo agregado. Aumento el 'size' de la LinkedList y retorno 0.
    //---------------------------------------------------------------------------------------------

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){

    	pNuevoNodo = (Node*) malloc(sizeof(Node));
    	if(pNuevoNodo != NULL){
    		pNuevoNodo->pNextNode = NULL;

    		if(nodeIndex == 0){
    			pNuevoNodo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNuevoNodo;
    			pNuevoNodo->pElement = pElement;
    			this->size++;
    			returnAux = 0;
    		}
    		else{
    			pAuxNodo = getNode(this, nodeIndex-1);
    			if(pAuxNodo != NULL){
    				pNuevoNodo->pNextNode = pAuxNodo->pNextNode; //En pAuxNodo->pNextNode hay NULL porque es el ultimo nodo de la LL
    				pAuxNodo->pNextNode = pNuevoNodo;

        			pNuevoNodo->pElement = pElement;
        			this->size++;
        			returnAux = 0;
    			}

    		}


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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL.
    //**2-Llamo a la funcion addNode para agregar un nodo al final de la LL
    //**3-En caso de exito, la funcion addNode retorna 0 y ll_add retorna 0
	//---------------------------------------------------------------------------------------------
    if(this != NULL) {
    		returnAux = addNode(this, ll_len(this), pElement); //Esta funcion retorna -1 en caso de error, 0 en caso contrario.
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
void* ll_get(LinkedList* this, int index){
    void* returnAux = NULL;
    Node* pNode = NULL;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el index sea mayor o igual a 0
    //**Valido que el index sea menor al 'size' de la LL. (Si el size es 10, el index mayor es 9)
    //**2-Obtengo el nodo seleccionado por el usuario a traves del parametro index
    //**3-Valido que el nodo no sea NULL y retorno el elemento que contiene.
	//---------------------------------------------------------------------------------------------
    if (this!=NULL && index>=0 && index < ll_len(this)){
    	pNode = getNode(this, index);

    	if (pNode != NULL){
    		returnAux = pNode->pElement;
    	}
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
int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    Node* pNodo = NULL;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el index sea mayor o igual a 0
    //**Valido que el index sea menor al 'size' de la LL. (Si el size es 10, el index mayor es 9)
    //**2-Obtengo el nodo seleccionado por el usuario a traves del parametro index
    //**3-Valido que el nodo no sea NULL y le asigno el pElement recibido por parametro al campo pNodo->pElement.
	//---------------------------------------------------------------------------------------------
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	pNodo = getNode(this, index);
    	if(pNodo != NULL){
    		pNodo->pElement = pElement;
    		returnAux = 0;
    	}
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
int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    Node* pNodoAux = NULL;
    Node* pNodoAuxDos = NULL;


	//---------------------------------------------------------------------------------------------
	//Descripcion: (Se hace un "puenteo" y se elimina (free) el nodo).
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el index sea mayor o igual a 0
    //**Valido que el index sea menor al 'size' de la LL. (Si el size es 10, el index mayor es 9)
    //**2-Obtengo el nodo que deseo remover a traves del parametro index y valido que no sea NULL
    //**
    //**3-SI EL INDEX ES 0:
    //**** La direcci?n de memoria del primer nodo (this->pFirstNode) pasa a ser la direccion de memoria a la que esta apuntando el nodo a eliminar
    //**** Achico el 'size' de la LL, elimino el nodo mediante la funcion 'free' y retorno 0.

    //**4-SI EL INDEX NO ES 0:
    //**** En este caso utilizo un nodo auxiliar. Al cual le asigno la direccion de memoria del nodo anterior y valido que no sea NULL
    //**** Al nodo anterior (pNodoAuxDos->pNextNode) le asigno el valor de 'pNextNode' del nodo a eliminar.
    //**** Achico el 'size' de la LL, elimino el nodo mediante la funcion 'free' y retorno 0.
	//---------------------------------------------------------------------------------------------
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	pNodoAux = getNode(this, index);

    	if(pNodoAux != NULL){
    		if(index == 0){
    			this->pFirstNode = pNodoAux->pNextNode;
    		}
    		else{
    			pNodoAuxDos = getNode(this, index-1);
    			if(pNodoAux != NULL){
    				pNodoAuxDos->pNextNode = pNodoAux->pNextNode;
    			}
    		}
			this->size --;
			free(pNodoAux);
			returnAux = 0;
    	}

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
int ll_clear(LinkedList* this){
	int returnAux = -1;
    int len;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL.
    //**2-Determino la longitud de la LL y si es mayor a 0 la recorro.
    //**3-En cada iteraci?n, elimino el primer nodo de la lista mediante la funcion 'll_remove' hasta que se hayan terminado todos los nodos
	//---------------------------------------------------------------------------------------------
    if(this != NULL){
    	returnAux = 0;
    	len =  ll_len(this);
    	if(len > 0){

        	for(int i=0; i<len; i++){
        		ll_remove(this, 0);
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
int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que todos los nodos de la lista hayan sido eliminados correctamente
    //**mediante la funcion 'll_clear'
    //**2-Si 'll_clear' retorna 0, significa que todos los nodos han sido eliminados. En ese caso, elimino la LinkedList mediante la funcion 'free' y retorno 0
	//---------------------------------------------------------------------------------------------
    if (this != NULL && ll_clear(this) == 0){
    	free(this);
    	returnAux = 0;
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
int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int len;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL.
    //**2-Determino la longitud de la LL y la recorro.
    //**3-Si hay coincidencia entre el 'pElement' pasado por parametro y el 'pElement' del nodo, guarda el index del nodo en 'returnAux' y hace un break.
    //**4-Retorna el index del nodo.
	//---------------------------------------------------------------------------------------------
    if(this != NULL){
    	len = ll_len(this);

    	for(int i=0; i<len; i++){


    		if(ll_get(this, i) == pElement){
    			returnAux = i;
    			break;
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
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. En caso de que sea NULL retorna -1.
    //**2-Si el 'size' de la LL es mayor a 0 (hay elementos), retorna 0.
    //**3-Si el 'size' de la LL es 0 (no hay elementos) retorna 1.
	//---------------------------------------------------------------------------------------------
    if(this != NULL){

    	if(ll_len(this) > 0){
    		returnAux = 0;
    	}
    	else{
    		returnAux = 1;
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
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el nodeIndex sea mayor o igual a 0
    //**Valido que sea menor o igual al 'size' de la linkedList. (Si el size es 10, entonces el ultimo index es 9. Entonces puedo agregar un nodo con index 10)
	//**2-Llamo a la funcion addNode que agregara un nuevo nodo en el index pasado por parametro con la direccion del elemento pasado por parametro
	//---------------------------------------------------------------------------------------------
    if(this != NULL && index >= 0 && index <= ll_len(this)){
    	returnAux = addNode(this, index, pElement); //la funcion addNode retorna -1 en caso de error. 0 en caso de exito
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
void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. Valido que el nodeIndex sea mayor o igual a 0
    //**Valido que sea menoral 'size' de la linkedList. (Si el size es 10, entonces el ultimo index es 9. No existe ningun nodo index 10 para eliminar)
	//**2-Recibo la direccion de memoria del nodo mediante la funcion ll_get y la almaceno en la variable 'returnAux' que sera el retorno de la funcion
    //**3-Elimino el nodo mediante la funcion 'll_remove'
	//---------------------------------------------------------------------------------------------
    if(this != NULL && index >= 0 && index < ll_len(this)){
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
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
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL. En caso de que no sea NULL, se le asigna 0 a 'returnAux'
    //**2-Si la funcion ''ll_indexOf' retorna algo distinto a -1, entonces el elemento se encuentra en la LL y la funcion retorna 1
	//---------------------------------------------------------------------------------------------
    if(this != NULL){

    	returnAux = 0;
    	if(ll_indexOf(this, pElement) != -1){
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
int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1;
    void* pElement = NULL;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que los punteros a las LLs no sean NULL.
    //**2-Recorro toda la LL2. En cada iteracion obtengo el elemento del nodo mediante la funcion 'll_get'
    //**3-Mediante la funcion 'll_contains' determino si el elemento se encuentra.
    //**4-Si en alguna iteracion la funcion 'll_contains' retorna 0, significa que hay al menos un elemento de la LL1 que no esta en la LL2
    //**En ese caso, retorno 0 y realizo un break;
	//---------------------------------------------------------------------------------------------
    if(this!=NULL && this2!=NULL){
    	returnAux = 1;

    	for(int i=0; i<ll_len(this2); i++){

    		pElement = ll_get(this2, i);
    		if(ll_contains(this, pElement) == 0){
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
LinkedList* ll_subList(LinkedList* this,int from,int to){
    LinkedList* sublist = NULL;
    void* elementoClonado = NULL;

	//---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que los punteros a las LLs no sean NULL.
    //** Validacion del from: que sea mayor o igual a 0, que sea menor que el 'size'
    //** Validacion del to: que sea mayor o igual al from. Que sea menor o igual al 'size'
    //**2-Declaro una nueva LL y valido que no sea NULL.
    //**3-Realizo un ciclo de iteracion desde el from (i=from) hasta el to(i<to)
    //**En cada iteracion obtengo el elemento que deseo clonar mediante 'll_get' y lo agrego a la nueva LL mediante 'll_add'
    //**3-Retorno la nueva lista
	//---------------------------------------------------------------------------------------------
    if(this != NULL && from >= 0 && from < ll_len(this) && to >= from && to <= ll_len(this)){
    	sublist = ll_newLinkedList();
    	if(sublist != NULL){

    		for(int i = from; i < to; i++){
    			elementoClonado = ll_get(this, i);
    			ll_add(sublist, elementoClonado);
    		}

    	}
    }

    return sublist;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){
    LinkedList* listaClonada = NULL;

    //---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que los punteros a las LLs no sean NULL.
    //**2-Declaro una nueva LL y le asigno el retorno de la funcion 'll_sublist'
    //****'ll_sublist' Recibe como parametros:
    //**** this (la lista a clonar)
    //**** to: 0 (se clona desde el inicio)
    //**** from el 'size' de la lista a clonar (hasta el final)
    //**3-Retorna la lista clonada
	//---------------------------------------------------------------------------------------------
    if(this != NULL){
    	listaClonada = ll_subList(this, 0, ll_len(this));
    }

    return listaClonada;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    int estaOrdenado;
    int len;
    void* auxElement = NULL;
    void* auxElementDos = NULL;
    int retornoPFunc;


    //---------------------------------------------------------------------------------------------
	//Descripcion:
	//**1-Valido que el puntero a la LL no sea NULL, que el puntero a la funcion no sea NULL, y que 'order' sea 0 o 1
    //**2-Obtengo el 'size' de la LL mediante la funcion 'll_len'
    //**3-Se ingresa a un ciclo do-while hasta que la variable 'estaOrdenado' no cambie su valor de 1
    //**4-Se ingresa a un ciclo for donde se recorreran los nodos de la LL.
    //**5-Se obtienen 2 nodos, uno en el index siguiente del otro y se determina cual es mayor mediante la funcion pasada por parametro.
    //**6-Se realiza un swap solo si:
    //****la funcion retorna mayor a 0 y el orden deseado es ascendente (1)
    //****la funcion retorna menor a y y el orden deseado es descendente (0)
    //****En caso de haber swap, la variable 'estaOrdenado' se le asigna 0 y vuelve a realizarse el ciclo do-while
	//---------------------------------------------------------------------------------------------
    if(this != NULL && pFunc!= NULL && (order == 0 || order == 1) ){
    	len = ll_len(this);


    	do{
    		estaOrdenado = 1;
    		len--;
    		for(int i=0; i<len; i++){
    			auxElement = ll_get(this, i);
    			auxElementDos = ll_get(this, i+1);
    			retornoPFunc = pFunc(auxElement, auxElementDos);

    			if( (retornoPFunc > 0 && order == 1)  || (retornoPFunc < 0 && order == 0)){
    				ll_set(this, i, auxElementDos);
    				ll_set(this, i+1, auxElement);
    				estaOrdenado = 0;
    			}

    		}

    	}while(estaOrdenado == 0);

    	returnAux = 0;
    }

    return returnAux;

}

//---------------------------------------------------------------------------------------------------------
//--------------------------------------------FUNCIONES SEGUNDO PARCIAL------------------------------------

int ll_count(LinkedList* this, int (*fn)(void* element)){
	int acumulador = -1;
	void* pElement;

	if(this != NULL && fn != NULL){
		acumulador = 0;

    	for(int i=0; i<ll_len(this); i++){

    		pElement = ll_get(this, i);
    		acumulador += fn(pElement);

    	}

	}

	return acumulador;
}

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element)){
	LinkedList* newLinkedList = NULL;
	void* pElement = NULL;


    if(this != NULL){
    	newLinkedList = ll_newLinkedList();

    	if(newLinkedList != NULL){

        	for(int i=0; i<ll_len(this); i++){

        		pElement = ll_get(this, i);
        		if(fn(pElement) == 1){
        			ll_add(newLinkedList, pElement);
        		}


        	}

    	}
    }

    return newLinkedList;
}

LinkedList* ll_map(LinkedList* this, void (*fn)(void* element)){
	LinkedList* newLinkedList = NULL;
	void* pPasajero = NULL;
	int tipoDePasajero_codigoInterno;
	char tipoDePasajeroStr[16];


	if(this != NULL){

		printf("\n---------------------------------------------------------------------------------------------------\n");
		printf("ID        NOMBRE         APELLIDO       PRECIO       CODIGO DE VUELO     TIPO             ESTADO          MILLAS ACUMULADAS\n    ");
		printf("---------------------------------------------------------------------------------------------------\n");

		for(int i=0; i<ll_len(this); i++){
			pPasajero = ll_get(this, i);


			if(pPasajero != NULL){

				fn(pPasajero); //modifico el campo de la lista

				//Obtengo el tipo de pasajero(char[]) y el codigo interno (int);
				tipoDePasajero_codigoInterno = Passenger_getTipoPasajero(pPasajero);
				decodificarTipoDePasajero(tipoDePasajeroStr, tipoDePasajero_codigoInterno);


				printf("%-10d",  Passenger_getId(pPasajero));
				printf("%-15s", Passenger_getNombre(pPasajero));
				printf("%-15s", Passenger_getApellido(pPasajero));
				printf("%-15.2f", Passenger_getPrecio(pPasajero));
				printf("%-15s", Passenger_getCodigoVuelo(pPasajero));
				printf("%-20s", tipoDePasajeroStr);
				printf("%-15s", Passenger_getEstadoDeVuelo(pPasajero));
				printf("%-15d\n", Passenger_getMillasAcumuladas(pPasajero));
			}


		}
	}




	return newLinkedList;
}
