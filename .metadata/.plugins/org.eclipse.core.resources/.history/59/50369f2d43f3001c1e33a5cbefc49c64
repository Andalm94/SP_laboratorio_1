#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "UTN.h"

//---------------------------------- LOAD --------------------------------------------------

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	int retorno = -1;
	FILE* file;
	//Descripcionn:
	//1- Valido los parametros recibidos
	//2- Abro el archivo y llamo a la funcion 'parser_PassengerFromText' que carga los pasajeros en la LinkedList.
	//3- Cierro el archivo. En caso de exito retorno 0.
	if(pArrayListPassenger != NULL){
		file = fopen(path, "r");
		if(file != NULL && parser_PassengerFromText(file, pArrayListPassenger) == 0){
			retorno = 0;
		}
		fclose(file);
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
    int retorno = -1;
    int len;
	FILE* file;
	//Descripcionn:
	//1- Valido los parametros recibidos
	//2- Abro el archivo y llamo a la funcion 'parser_PassengerFromBinary' que carga los pasajeros en la LinkedList.
	//3- Cierro el archivo. En caso de exito retorno 0.
	if(pArrayListPassenger != NULL){
		file = fopen(path, "rb");
		if(file != NULL && parser_PassengerFromBinary(file, pArrayListPassenger)==0 ){
			retorno = 0;
		}
	}

	fclose(file);

	len=ll_len(pArrayListPassenger);
	ll_remove(pArrayListPassenger, len-1);

	return retorno;
}




//---------------------------------- ALTA - MODIFICACION - BAJA-----------------------------------------------


/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	Passenger* pPasajero;
	int nextID;
	char id[32];
	char nombre[32];
	char apellido[32];
	char codigoDeVuelo[32];
	char tipoDePasajero[32];
	char precio[32];
	char estadoDeVuelo[32];

	//Descripcionn:
	//1- Declaro las variables locales y un puntero de tipo Passenger. Luego valido los parametros recibidos
	//2- Solicito al usuario que cargue los datos para crear el nuevo pasajero.
	//3- Genero una ID nueva pasa el usuario mediante la funcion 'controller_generadorID'
	//4- La funcion 'Passenger_newParametros' recibe como parametro los datos solicitados y retorna un puntero a Passenger
	//5- Se carga el nuevo pasajero en linkedList.
	//6- En caso de exito retorna 0. En caso contrario -1.
	if(pArrayListPassenger != NULL){
		if(getString ("Nombre: \n", "ERROR. Intente nuevamente.", nombre, 32, 3) == 0 &&
				getString ("Apellido: \n", "ERROR. Intente nuevamente.", apellido, 32, 3) == 0 &&
				getString ("Codigo de vuelo: \n", "ERROR. Intente nuevamente.", codigoDeVuelo, 32, 3) == 0 &&
				getString ("Tipo de pasajero: (1. EconomicClass || 2.ExecutiveClass || 3.FirstClass) \n", "ERROR. Intente nuevamente.", tipoDePasajero, 32, 3) == 0 &&
				getString ("Precio: \n", "ERROR. Intente nuevamente.", precio, 32, 3) == 0 &&
				getString ("Estado del vuelo: \n", "ERROR. Intente nuevamente.", estadoDeVuelo, 32, 3) == 0){

			nextID = controller_generadorID(pArrayListPassenger);
			sprintf(id,"%i", nextID); //Cargo el valor: id(char*) <-- nextID (int)
			pPasajero = Passenger_newParametros(id, nombre, apellido, codigoDeVuelo, tipoDePasajero, precio, estadoDeVuelo);
			ll_add(pArrayListPassenger, pPasajero);
			retorno = 0;
		}

	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int idPasajero;
	int indexPasajero = -1;
	int opcionIngresada;
	char nuevoDato[32];
	Passenger* pPasajero = NULL;


	//Descripcionn:
	//1- Declaro las variables locales y un puntero de tipo Passenger.
	//2- Muestro la lista de pasajeros y solicito al usuario un ID. Busco ese usuario con la funcion 'controller_BuscarPasajeroPorID'
	//Cargo el puntero a ese pasajero en la variable 'pPasajero'
	//3- Si el pasajero existe, lo muestro y se despliega un menu de modificaciones, donde el usuario elegira que campo modificar
	//4- Se solicita al usuario el dato nuevo y se guarda en la estructura. Luego se muestra el pasajero nuevamente.
	//5- Si los parametros son validos, retorna 0. Caso contrario -1.
	 if(controller_ListPassenger(pArrayListPassenger)==0 &&
			 getInt(&idPasajero, "Pasajero ID: \n", "ERROR. Intente nuevamente\n", 1, 9999, 3) == 0){

		 retorno = 0;
		 indexPasajero = controller_BuscarPasajeroPorID(pArrayListPassenger, idPasajero);
		 if(indexPasajero != -1){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, indexPasajero);
				mostrarPasajero(pPasajero);

				do{
					mostrarMenuModificaciones();
					if(getInt(&opcionIngresada, "\n", "No existe esa opcion\n", 1, 6, 3) == 0){

						switch(opcionIngresada){
							case 1: //---------------------------------------------------------> NOMBRE
								getString ("Nuevo nombre:\n", "ERROR\n", nuevoDato, 32, 3);
								Passenger_setNombre(pPasajero, nuevoDato);
								mostrarPasajero(pPasajero);
								break;
							case 2: //---------------------------------------------------------> APELLIDO
								getString ("Nuevo apellido:\n", "ERROR\n", nuevoDato, 32, 3);
								Passenger_setApellido(pPasajero, nuevoDato);
								mostrarPasajero(pPasajero);
								break;
							case 3: //---------------------------------------------------------> CODIGO DE VUELO
								getString ("Nuevo codigo de vuelo:\n", "ERROR\n", nuevoDato, 32, 3);
								Passenger_setCodigoVuelo(pPasajero, nuevoDato);
								mostrarPasajero(pPasajero);
								break;
							case 4: //---------------------------------------------------------> TIPO DE PASAJERO
								getString ("Nuevo tipo de pasajero: (1. EconomicClass || 2.ExecutiveClass || 3.FirstClass)\n", "ERROR\n", nuevoDato, 32, 3);
								Passenger_setTipoPasajero(pPasajero, atoi(nuevoDato));
								mostrarPasajero(pPasajero);
								break;
							case 5: //---------------------------------------------------------> PRECIO
								getString ("Nuevo precio:\n", "ERROR\n", nuevoDato, 32, 3);
								Passenger_setPrecio(pPasajero, atof(nuevoDato));
								mostrarPasajero(pPasajero);
								break;
							case 6: //---------------------------------------------------------> VOLVER AL MENU PRINCIPAL
								break;
						}

					}
				}while(opcionIngresada != 6);

		 }
	 }

	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int indexPasajero;
	int idPasajero;
	Passenger* pPasajero;
	char respuestaConfirmacion;
	//Descripcion:
	//1-Valido los parametros ingresados. La funcion retornara 0 si son validos y -1 en caso contrario
	if(pArrayListPassenger != NULL){
		retorno=0;

		//2-Listo los pasajeros
		//Solicito el ID del pasajero a eliminar
		if(controller_ListPassenger(pArrayListPassenger) == 0 &&
				getInt(&idPasajero, "Pasajero ID:\n", "ERROR. Intente nuevamente\n", 0, 9999, 3) == 0){


			//3-Si existe el pasajero, su puntero se almacena en la variable 'pPasajero' y se muestra.
			indexPasajero = controller_BuscarPasajeroPorID(pArrayListPassenger, idPasajero);
			if(indexPasajero != -1){
				pPasajero=(Passenger*)ll_get(pArrayListPassenger, indexPasajero);
				mostrarPasajero(pPasajero);

				//4-Se solicita confirmacion para eliminar. En caso de que el usuario confirme, el usuario se elimina.
				if (getCharSiNo ("Desea eliminar este pasajero?(S/N)\n", &respuestaConfirmacion, 3) == 0 && respuestaConfirmacion == 'S'){
		    		ll_remove(pArrayListPassenger, indexPasajero);
		    		Passenger_delete(pPasajero);
				}

			}

		}


	}


    return retorno;
}



//------------------------------LISTAR / BUSCAR / ORDENAR----------------------------------------
/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int len;
	Passenger* pPasajero;

	//Descripcion:
	//1-Creo una variable 'len' que almacenara la cantidad de pasajeros cargados.
	//Creo una variable 'pPasajero' que almacena un puntero a Passenger.
	//2-Valido los parametros. Muestro un header y con un ciclo for recorro todos los pasajeros y los muestro usando la funcion 'mostrarPasajero'
	if(pArrayListPassenger != NULL){
		len = ll_len(pArrayListPassenger);
		printf("\n---------------------------------------------------------------------------------------------------\n");
		printf("ID        NOMBRE         APELLIDO       PRECIO       CODIGO DE VUELO     TIPO             ESTADO\n");
		printf("---------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<len; i++){
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			mostrarPasajero(pPasajero);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Recibe un ID por parametro y busca el index del pasajero
 *
 * \param int id
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: index del pasajero // Error o parametros invalidos: -1
 *
 */
int controller_BuscarPasajeroPorID(LinkedList* pArrayListPassenger, int id){
	int retorno = -1;
	int len;
	Passenger* pPasajero = NULL;

	len=ll_len(pArrayListPassenger);
	//Descripcion:
	//1-Creo una variable 'len' que almacenara la cantidad de pasajeros cargados.
	//Creo una variable 'pPasajero' que almacena un puntero a Passenger.
	//2-Recibo por parametro un ID y busco el usuario que posea dicho ID. Busco su index y lo retorno.
	//En caso de recibir parametros invalidos o no encontrar el usuario, retorna -1.
	if(pArrayListPassenger != NULL){
		for (int i=0; i<len; i++){
			pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(pPasajero->id == id){
				retorno = ll_indexOf(pArrayListPassenger, pPasajero);
				break;
			}
		}
	}

	return retorno;
}

/** \brief Ordenar pasajeros. Ofrece ordenar segun cada campo de la estructura y en orden ascendente o descendente.
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int opcionIngresada;
	int opcionIngresadaOrdenamiento;
	//Descripcion:
	//1- Valido los parametros. La funcion retornara 0 en caso de haber parametros validos y -1 en caso contrario
	 if(pArrayListPassenger != NULL){
		 retorno = 0;

		 //2- Muestro el menu de ordenamiento y solicito al usuario una opcion.
		 //3- Para cada caso, se solicitara que elija entre criterio ascendente(1) o descendente(0)
		 //4- Los ordenamientos se realizan con la funcion 'll_sort'
		 mostrarMenuOrdenamientos();
		 if(getInt(&opcionIngresada, "\n", "No existe esa opcion\n", 1, 7, 3) == 0){
			 switch(opcionIngresada){
			 	case 1: //---------------------------------------------------------> ID
			 		if(getInt(&opcionIngresadaOrdenamiento, "Ordenar de manera:\n 0) Descendente\n 1) Ascendente\n", "ERROR. Intente nuevamente", 0, 1, 3) == 0){
			 			ll_sort(pArrayListPassenger, compararPasajerosPorID, opcionIngresadaOrdenamiento);
			 		}
			 		break;
			 	case 2: //---------------------------------------------------------> NOMBRE
			 		if(getInt(&opcionIngresadaOrdenamiento, "Ordenar de manera:\n 0) Descendente\n 1) Ascendente\n", "ERROR. Intente nuevamente", 0, 1, 3) == 0){
			 			ll_sort(pArrayListPassenger, compararPasajerosPorNombre, opcionIngresadaOrdenamiento);
			 		}
			 		break;
			 	case 3: //---------------------------------------------------------> APELLIDO
			 		if(getInt(&opcionIngresadaOrdenamiento, "Ordenar de manera:\n 0) Descendente\n 1) Ascendente\n", "ERROR. Intente nuevamente", 0, 1, 3) == 0){
			 			ll_sort(pArrayListPassenger, compararPasajerosPorApellido, opcionIngresadaOrdenamiento);
			 		}
			 		break;
			 	case 4: //---------------------------------------------------------> CODIGO DE VUELO
			 		if(getInt(&opcionIngresadaOrdenamiento, "Ordenar de manera:\n 0) Descendente\n 1) Ascendente\n", "ERROR. Intente nuevamente", 0, 1, 3) == 0){
			 			ll_sort(pArrayListPassenger, compararPasajerosPorCodigoVuelo, opcionIngresadaOrdenamiento);
			 		}
			 		break;
			 	case 5: //---------------------------------------------------------> TIPO DE PASAJERO
			 		if(getInt(&opcionIngresadaOrdenamiento, "Ordenar de manera:\n 0) Descendente\n 1) Ascendente\n", "ERROR. Intente nuevamente", 0, 1, 3) == 0){
			 			ll_sort(pArrayListPassenger, compararPasajerosPorTipoPasajero, opcionIngresadaOrdenamiento);
			 		}
			 		break;
			 	case 6: //---------------------------------------------------------> PRECIO
			 		if(getInt(&opcionIngresadaOrdenamiento, "Ordenar de manera:\n 0) Descendente\n 1) Ascendente\n", "ERROR. Intente nuevamente", 0, 1, 3) == 0){
			 			ll_sort(pArrayListPassenger, compararPasajerosPorPrecio, opcionIngresadaOrdenamiento);
			 		}
			 		break;
			 	case 7: //---------------------------------------------------------> VOLVER AL MENU ANTERIOR
			 		break;
			 }
		 }
	 }

	//5-Si el usuario realizo algun ordenamiento, muestra la lista reordenada.
	if(opcionIngresada >= 1 && opcionIngresada <= 6){
		controller_ListPassenger(pArrayListPassenger);
	}

	return retorno;
}



//------------------------------- MANEJO ID ------------------------------------------------

/** \brief Establece un ID para el pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: ID del pasajero // Error o parametros invalidos: -1
 *
 */
int controller_generadorID(LinkedList* pArrayListPassenger){
	int id = -1;
	//Descripcion:
	//1-Esta funcion busca el ultimo ID mediante la funcion 'controller_buscarUltimoID'. Luego le suma 1 y lo retorna.
	if(pArrayListPassenger != NULL){
		id = controller_buscarUltimoID(pArrayListPassenger);
		id++;
	}

	return id;
}

/** \brief Busca el ultimo ID establecido
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: ultimo ID establecido // Error o parametros invalidos: -1
 *
 */
int controller_buscarUltimoID(LinkedList* pArrayListPassenger){
	int id = 0;
	int len;
	Passenger* pPasajero;

	//Descripcion:
	//1-Esta funcion recorre los pasajeros, busca el ID maximo y lo retorna.
	len = ll_len(pArrayListPassenger);
	if(pArrayListPassenger != NULL){
		for(int i=0; i<len; i++){
			pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(pPasajero->id > id){
				id = pPasajero->id;
			}
		}
	}
	return id;
}


//---------------------------------- SAVE --------------------------------------------------

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){
	int retorno = -1;
    int len;
    int id;
    char nombre[32];
    char apellido[32];
    char codigoDeVuelo[32];
    int tipoDePasajero_codigoInterno;
    char tipoDePasajeroStr[32];
    char estadoDeVuelo[32];
    float precio;

    FILE* file;
    Passenger* pPasajero;



    len = ll_len(pArrayListPassenger);
    file = fopen(path, "w");

    if(path != NULL){
    	fprintf(file,"id,name,lastname,price,flycode,typePassenger,statusFlight\n"); //Imprimo el header
    	for(int i=0; i<len; i++){
    		pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);

    		tipoDePasajero_codigoInterno = Passenger_getTipoPasajero(pPasajero);
    		decodificarTipoDePasajero(tipoDePasajeroStr, tipoDePasajero_codigoInterno);


    		id = Passenger_getId(pPasajero);
    		strcpy(nombre, Passenger_getNombre(pPasajero));
    		strcpy(apellido, Passenger_getApellido(pPasajero));
    		strcpy(codigoDeVuelo, Passenger_getCodigoVuelo(pPasajero));
    		precio = Passenger_getPrecio(pPasajero);
    		strcpy(codigoDeVuelo, Passenger_getCodigoVuelo(pPasajero));
    		strcpy(estadoDeVuelo, Passenger_getEstadoDeVuelo(pPasajero));
    		fprintf(file,"%d,%s,%s,%.0f,%s,%s,%s\n",id,nombre,apellido,precio,codigoDeVuelo,tipoDePasajeroStr,estadoDeVuelo);
    		retorno = 0;
    	}
    }

    fclose(file);
	return retorno;
}



/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno = -1;
	int len;
	FILE* file;
	Passenger* pPasajero = NULL;

	if(pArrayListPassenger != NULL && path != NULL){
		retorno = 0;
		file = fopen(path, "wb");
		len = ll_len(pArrayListPassenger);

		for(int i=0; i<len; i++){
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			fwrite(pPasajero, sizeof(Passenger), 1, file);
		}

	}

	fclose(file);
    return retorno;
}

