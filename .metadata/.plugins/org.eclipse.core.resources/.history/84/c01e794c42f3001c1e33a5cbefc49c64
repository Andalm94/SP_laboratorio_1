#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"


/** \brief Reserva espacio en memoria dinamica para un pasajero mediante la funcion malloc.
 *
 * \return Exito: puntero a Passenger con campos inicializados.
 */
Passenger* Passenger_new(){
	Passenger *punteroPassenger;

	punteroPassenger = (Passenger*)malloc(sizeof(Passenger));
	if(punteroPassenger != NULL){
		Passenger_setId(punteroPassenger, 0);
		Passenger_setNombre(punteroPassenger, "");
		Passenger_setApellido(punteroPassenger," ");
		Passenger_setCodigoVuelo(punteroPassenger, " ");
		Passenger_setTipoPasajero(punteroPassenger, 0);
		Passenger_setPrecio(punteroPassenger,0);
		Passenger_setEstadoDeVuelo(punteroPassenger, " ");

	}

	return punteroPassenger;
}

/** \brief Recibe como parametros las variables que se almacenaran en los campos de la estructura.
 *  Devuelve un puntero Passenger que apunta a esos datos almacenados.
 *
 * \param char* id, nombre, apellido, codigoDeVuelo, tipoPasajero, precio, estadoDEVuelo
 *
 * \return Exito: Passenger* con la direccion de memoria del pasajero. ERROR: NULL
 */
Passenger* Passenger_newParametros(char* id, char* nombre, char* apellido, char* codigoDeVuelo, char* tipoPasajero, char* precio, char* estadoDeVuelo){
	Passenger *punteroPassenger;
	Passenger *punteroPassengerRetorno = NULL;

	punteroPassenger = Passenger_new();
	if(punteroPassenger != NULL){

		if(Passenger_setId(punteroPassenger, atoi(id)) == 0 &&
			Passenger_setNombre(punteroPassenger, nombre) == 0 &&
			Passenger_setApellido(punteroPassenger, apellido) == 0 &&
			Passenger_setCodigoVuelo(punteroPassenger, codigoDeVuelo) == 0 &&
			Passenger_setTipoPasajero(punteroPassenger, atoi(tipoPasajero)) == 0 &&
			Passenger_setPrecio(punteroPassenger, atof(precio)) == 0 &&
			Passenger_setEstadoDeVuelo(punteroPassenger, estadoDeVuelo) == 0){

				punteroPassengerRetorno = punteroPassenger;
		}

	}

	return punteroPassengerRetorno;
}

/** \brief Recibe un puntero a Passenger y lo elimina -free(this)-
 *
 * \param Passenger* pasajero a ser eliminado
 */
void Passenger_delete(Passenger* this){
	if (this != NULL) {
		free(this);
	}
}

//--------------------------------------- MOSTRAR --------------------------------------------------------
/** \brief Recibe un array de punteros a Passenger y los muestra
 *
 * \param Passenger** pPasajero
 * \param len longitud del array de pasajeros.
 *
 * \return Exito: 0. ERROR o parametros invalidos: -1
 */
int mostrarPasajeros(Passenger **arrayPasajeros, int len){
	int retorno = -1;
	int i;

	if(arrayPasajeros != NULL && len > 0){
		retorno = 0;
		for(i=0; i<len; i++){
			mostrarPasajero(*(arrayPasajeros+i));
		}
	}

	return retorno;
}

/** \brief Recibe el puntero a un pasajero y muestra sus campos.
 *
 * \param Passenger* pPasajero
 *
 * \return Exito: 0. ERROR o parametros invalidos: -1
 */
int mostrarPasajero(Passenger *pPasajero){
	int retorno = -1;
	int tipoDePasajero_codigoInterno;
	char tipoDePasajeroStr[16];

	tipoDePasajero_codigoInterno = Passenger_getTipoPasajero(pPasajero);
	decodificarTipoDePasajero(tipoDePasajeroStr, tipoDePasajero_codigoInterno);


	if(pPasajero != NULL){
		retorno = 0;
		printf("%-10d",  Passenger_getId(pPasajero));
		printf("%-15s", Passenger_getNombre(pPasajero));
		printf("%-15s", Passenger_getApellido(pPasajero));
		printf("%-15.2f", Passenger_getPrecio(pPasajero));
		printf("%-15s", Passenger_getCodigoVuelo(pPasajero));
		printf("%-20s", tipoDePasajeroStr);
		printf("%-15s\n", Passenger_getEstadoDeVuelo(pPasajero));
	}

	return retorno;
}


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
int codificarTipoDePasajero(char tipoDePasajeroCodificado[], char tipoDePasajero[]){
	int retorno = -1;
	char tipoDePasajeroConvertido[4];
	strcpy(tipoDePasajeroConvertido, "0");
	//Recibe por parametro un array de caracteres que devolvera la codificacion y otro array que contendra el valor en el campo 'tipoDePasajero' del pasajero
	//Dependiendo del valor en tipoDePasajero, se manejara internamente con una variable tipo INT.
	//***Economic --> 1
	//***Executive--> 2
	//***First------> 3
	if(tipoDePasajeroCodificado != NULL && tipoDePasajero != NULL){
		retorno = 0;


		if(strcmp(tipoDePasajero, "EconomyClass") == 0){
			strcpy(tipoDePasajeroConvertido, "1");
		}
		else{
			if(strcmp(tipoDePasajero, "ExecutiveClass") == 0){
				strcpy(tipoDePasajeroConvertido, "2");
			}
			else{
				if(strcmp(tipoDePasajero, "FirstClass") == 0){
					strcpy(tipoDePasajeroConvertido, "3");
				}
			}
		}

		strcpy(tipoDePasajeroCodificado, tipoDePasajeroConvertido);
	}

	return retorno;

}

/** \brief Traduce a array de caracteres el codigo interno del valor en el campo 'tipoDePasajero'
 *
 * \param char tipoDePasajeroStr[] : cadena que devolvera el siguiente string dependiendo del valor en tipoDePasajeroint
 * 	*** 1 -----> "EconomicClass"
 *	*** 2 -----> "ExecutiveClass"
 *	*** 3 -----> "FirstClass"
 * \param int tipoDePasajeroint: el valor en el campo 'tipoDePasajero'
 *
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int decodificarTipoDePasajero(char tipoDePasajeroStr[], int tipoDePasajeroint){
	int retorno = -1;
	char tipoDePasajeroConvertido[16];
	strcpy(tipoDePasajeroConvertido, "0");

	if(tipoDePasajeroStr != NULL && tipoDePasajeroint > 0){
		retorno = 0;

		switch (tipoDePasajeroint){
			case 1:
				strcpy(tipoDePasajeroConvertido, "EconomyClass");
				break;
			case 2:
				strcpy(tipoDePasajeroConvertido, "ExecutiveClass");
				break;
			case 3:
				strcpy(tipoDePasajeroConvertido, "FirstClass");
				break;

		}

		strcpy(tipoDePasajeroStr, tipoDePasajeroConvertido);

	}

	return retorno;

}


//--------------------------------------- ORDENAR Y COMPARAR ---------------------------------------------

int compararPasajerosPorID(void* primerPasajero, void* segundoPasajero){
	int comparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	int idPrimerPasajero;
	int idSegundoPasajero;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		idPrimerPasajero = Passenger_getId(pPrimerPasajero);
		idSegundoPasajero = Passenger_getId(pSegundoPasajero);

		if(idPrimerPasajero > idSegundoPasajero){
			comparacion = 1;
		}
		else{
			comparacion = -1;
		}
	}

	return comparacion;
}

int compararPasajerosPorNombre(void* primerPasajero, void* segundoPasajero){
	int comparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	char nombrePrimerPasajero[32];
	char nombreSegundoPasajero[32];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		strcpy(nombrePrimerPasajero, Passenger_getNombre(pPrimerPasajero));
		strcpy(nombreSegundoPasajero, Passenger_getNombre(pSegundoPasajero));

		comparacion = strcmp(nombrePrimerPasajero, nombreSegundoPasajero);
	}

	return comparacion;
}

int compararPasajerosPorApellido(void* primerPasajero, void* segundoPasajero){
	int comparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	char apellidoPrimerPasajero[32];
	char apellidoSegundoPasajero[32];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		strcpy(apellidoPrimerPasajero, Passenger_getNombre(pPrimerPasajero));
		strcpy(apellidoSegundoPasajero, Passenger_getNombre(pSegundoPasajero));

		comparacion = strcmp(apellidoPrimerPasajero, apellidoSegundoPasajero);
	}

	return comparacion;
}

int compararPasajerosPorCodigoVuelo(void* primerPasajero, void* segundoPasajero){
	int comparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	char codigoPrimerPasajero[32];
	char codigoSegundoPasajero[32];

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		strcpy(codigoPrimerPasajero, Passenger_getApellido(pPrimerPasajero));
		strcpy(codigoSegundoPasajero, Passenger_getApellido(pSegundoPasajero));

		comparacion = strcmp(codigoPrimerPasajero, codigoSegundoPasajero);
	}

	return comparacion;
}

int compararPasajerosPorTipoPasajero(void* primerPasajero, void* segundoPasajero){
	int comparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	int tipoPrimerPasajero;
	int tipoSegundoPasajero;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		tipoPrimerPasajero = Passenger_getTipoPasajero(pPrimerPasajero);
		tipoSegundoPasajero = Passenger_getTipoPasajero(pSegundoPasajero);

		if(tipoPrimerPasajero > tipoSegundoPasajero){
			comparacion = 1;
		}
		else{
			comparacion = -1;
		}
	}

	return comparacion;
}

int compararPasajerosPorPrecio(void* primerPasajero, void* segundoPasajero){
	int comparacion = 0;
	Passenger* pPrimerPasajero;
	Passenger* pSegundoPasajero;
	float precioPrimerPasajero;
	float precioSegundoPasajero;

	if(primerPasajero != NULL && segundoPasajero != NULL){
		pPrimerPasajero = (Passenger*) primerPasajero;
		pSegundoPasajero = (Passenger*) segundoPasajero;

		precioPrimerPasajero = Passenger_getPrecio(pPrimerPasajero);
		precioSegundoPasajero = Passenger_getPrecio(pSegundoPasajero);

		if(precioPrimerPasajero > precioSegundoPasajero){
			comparacion = 1;
		}
		else{
			comparacion = -1;
		}
	}

	return comparacion;
}

//--------------------------------------- GET Y SET ------------------------------------------------------

int Passenger_setId(Passenger* this,int id){
	int retorno = -1;

	if(this != NULL && id > 0){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this){
	return this->id;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
char* Passenger_getNombre(Passenger* this){
	return this->nombre;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno = -1;

	if(this != NULL && apellido != NULL){
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
char* Passenger_getApellido(Passenger* this){
	return this->apellido;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
char* Passenger_getCodigoVuelo(Passenger* this){
	return this->codigoVuelo;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0){
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this){
	return this->tipoPasajero;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int retorno = -1;

	if(this != NULL && precio > 0){
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
float Passenger_getPrecio(Passenger* this){
	return this->precio;
}

int Passenger_setEstadoDeVuelo(Passenger* this,char* estadoDeVuelo){
	int retorno = -1;

	if(this != NULL && estadoDeVuelo != NULL){
		strcpy(this->estadoDeVuelo, estadoDeVuelo);
		retorno = 0;
	}

	return retorno;
}
char* Passenger_getEstadoDeVuelo(Passenger* this){
	return this->estadoDeVuelo;
}

