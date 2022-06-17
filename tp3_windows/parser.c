#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){

	//Descripcion:
	//**1-Declaro las variables necesarias para cargar a los pasajeros escaneados del documento
	//**2-Valido los parametros recibidos.
	//**3-Recorro el archivo. Escaneo linea por linea, cargando los datos separados por coma en las variables declaradas al principio.
	//**4-Creo el nuevo pasajero con los datos escaneados. Cargo el nuevo pasajero en la linkedList. Retorno 0 en caso de exito.
	//NOTA: Pasa el campo 'tipoDePasajero' se realiza una codificacion mediante la funcion 'codificarTipoDePasajero'.
	//Dependiendo del valor en tipoDePasajero, se manejara internamente con una variable tipo INT.
	//***Economic --> 1
	//***Executive--> 2
	//***First------> 3
	int retorno = -1;
	Passenger* pPasajero;
	char id[32];
	char nombre[32];
	char apellido[32];
	char codigoDeVuelo[32];
	char tipoDePasajero[32];
	char tipoDePasajero_codigoInterno[4];
	char estadoDeVuelo[32];
	char precio[32];

	if(pFile != NULL && pArrayListPassenger!= NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, apellido, precio, codigoDeVuelo, tipoDePasajero, estadoDeVuelo);//falsa lectura
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, apellido, precio, codigoDeVuelo, tipoDePasajero, estadoDeVuelo); //Escaneo el documento
			codificarTipoDePasajero(tipoDePasajero_codigoInterno, tipoDePasajero); //Codifico el tipo de pasajero
			pPasajero = Passenger_newParametros(id, nombre, apellido, codigoDeVuelo, tipoDePasajero_codigoInterno, precio, estadoDeVuelo); //cargo los datos escaneados en un nuevo pasajero
			ll_add(pArrayListPassenger, pPasajero); //cargo el nuevo pasajero en la linkedList
			retorno = 0;
		}
	}



    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){

	int retorno = -1;
    Passenger* pPasajero = NULL;

    if(pFile != NULL && pArrayListPassenger != NULL){
		while(!feof(pFile)){
			pPasajero = Passenger_new();
			fread(pPasajero, sizeof(Passenger), 1, pFile);
			ll_add(pArrayListPassenger, pPasajero);
			retorno = 0;
		}
    }

	return retorno;
}



