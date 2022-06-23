/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[16];
	char estadoDeVuelo[16];

}Passenger;

/** \brief Reserva espacio en memoria dinamica para un pasajero mediante la funcion malloc.
 *
 * \return Exito: puntero a Passenger con campos inicializados.
 */
Passenger* Passenger_new();

/** \brief Recibe como parametros las variables que se almacenaran en los campos de la estructura.
 *  Devuelve un puntero Passenger que apunta a esos datos almacenados.
 *
 * \param char* id, nombre, apellido, codigoDeVuelo, tipoPasajero, precio, estadoDEVuelo
 *
 * \return Exito: Passenger* con la direccion de memoria del pasajero. ERROR: NULL
 */
Passenger* Passenger_newParametros(char* id, char* nombre, char* apellido, char* codigoDeVuelo, char* tipoPasajero, char* precio, char* estadoDeVuelo);



/** \brief Recibe un puntero a Passenger y lo elimina -free(this)-
 *
 * \param Passenger* pasajero a ser eliminado
 */
void Passenger_delete(Passenger* this);


//--------------------------------------- MOSTRAR --------------------------------------------------------
/** \brief Recibe un array de punteros a Passenger y los muestra
 *
 * \param Passenger** pPasajero
 * \param len longitud del array de pasajeros.
 *
 * \return Exito: 0. ERROR o parametros invalidos: -1
 */
int mostrarPasajeros(Passenger **arrayPasajeros, int len);

/** \brief Recibe el puntero a un pasajero y muestra sus campos.
 *
 * \param Passenger* pPasajero
 *
 * \return Exito: 0. ERROR o parametros invalidos: -1
 */
int mostrarPasajero(Passenger *pPasajero);

/** \brief Traduce a codigo interno el valor en el campo 'tipoDePasajero'
 *
 * \param char tipoDePasajeroCodificado[] : cadena que devolvera el codigo:
 * 	***Economic --> 1
 *	***Executive--> 2
 *	***First------> 3
 * \param char tipoDePasajero[] : el valor en el campo 'tipoDePasajero'
 *
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int codificarTipoDePasajero(char tipoDePasajeroCodificado[], char tipoDePasajero[]);

/** \brief Traduce a codigo interno el valor en el campo 'tipoDePasajero'
 *
 * \param char tipoDePasajeroInt[] : cadena que devolvera el codigo:
 * 	***Economic --> 1
 *	***Executive--> 2
 *	***First------> 3
 * \param char tipoDePasajeroStr[] : el valor en el campo 'tipoDePasajero'
 *
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 */
int decodificarTipoDePasajero(char tipoDePasajeroStr[], int tipoDePasajeroint);


//--------------------------------------- ORDENAR Y COMPARAR ---------------------------------------------

int compararPasajerosPorID(void* primerPasajero, void* segundoPasajero);

int compararPasajerosPorNombre(void* primerPasajero, void* segundoPasajero);

int compararPasajerosPorApellido(void* primerPasajero, void* segundoPasajero);

int compararPasajerosPorCodigoVuelo(void* primerPasajero, void* segundoPasajero);

int compararPasajerosPorTipoPasajero(void* primerPasajero, void* segundoPasajero);

int compararPasajerosPorPrecio(void* primerPasajero, void* segundoPasajero);



//--------------------------------------- GET Y SET ---------------------------------------------

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this);

int Passenger_setNombre(Passenger* this,char* nombre);
char* Passenger_getNombre(Passenger* this);

int Passenger_setApellido(Passenger* this,char* apellido);
char* Passenger_getApellido(Passenger* this);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
char* Passenger_getCodigoVuelo(Passenger* this);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this);

int Passenger_setPrecio(Passenger* this,float precio);
float Passenger_getPrecio(Passenger* this);

int Passenger_setEstadoDeVuelo(Passenger* this,char* estadoDeVuelo);
char* Passenger_getEstadoDeVuelo(Passenger* this);

#endif /* PASSENGER_H_ */
