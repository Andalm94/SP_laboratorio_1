#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int getInt(int * pNumeroIngresado, char * mensaje, char * mensajeError, int min, int max, int reintentos){

	int auxNumeroIngresado;
	char numeroIngresado[256];
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && max >= min && reintentos>= 0){
		do{
			printf("%s", mensaje);

			//Se carga el numero en el array
			//Se valida si los caracteres ingresados son numericos
			//Si se valida, se convierte el array en un dato INT
			if (myGets(numeroIngresado, 256) == 0 && validarEsInt(numeroIngresado) == 0){
				auxNumeroIngresado = atoi(numeroIngresado);

				// Validamos si el numero ingresado se encuentra en el rango.
				// En caso afirmativo la funcion retorna 0
				if(auxNumeroIngresado >= min && auxNumeroIngresado <= max){
					*pNumeroIngresado = auxNumeroIngresado;
					retorno = 0;
					break;
				}
			}

			//Si ha habido algun error, se muestra al usuario un mensaje de error
			if(retorno == -1){
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos > 0);
	}

	return retorno;
}

int getFloat(float * pNumeroIngresado, char * mensaje, char * mensajeError, int min, int max, int reintentos){
	float auxNumeroIngresado;
	char numeroIngresado[256];
	int retorno;
	retorno = -1;

	if(pNumeroIngresado != NULL && max >= min && reintentos>= 0){
		do{
			printf("%s", mensaje);

			//Se carga el numero en el array
			//Se valida si los caracteres ingresados son numericos
			//Si se valida, se convierte el array en un dato FLOAT
			if (myGets(numeroIngresado, 256) == 0 && validarEsFloat(numeroIngresado) == 0){
				auxNumeroIngresado = atof(numeroIngresado);

				// Validamos si el numero ingresado se encuentra en el rango.
				// En caso afirmativo la funcion retorna 0
				if(auxNumeroIngresado >= min && auxNumeroIngresado <= max){
					*pNumeroIngresado = auxNumeroIngresado;
					retorno = 0;
					break;
				}
			}

			//Si ha habido algun error, se muestra al usuario un mensaje de error
			if(retorno == -1){
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos > 0);
	}

	return retorno;
}

int getCharSiNo (char mensaje[], char * caracter, int reintentos){
	int retorno = -1;
	char auxiliarCaracter;

	if(caracter != NULL && reintentos > 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &auxiliarCaracter);
			auxiliarCaracter = toupper(auxiliarCaracter);
			if(auxiliarCaracter == 'S' || auxiliarCaracter == 'N'){
				*caracter = auxiliarCaracter;
				retorno = 0;
				break;
			}
			reintentos--;
		}while(reintentos > 0);
	}

	return retorno;
}

int getString (char mensaje[], char mensajeError[], char cadena[], int len, int reintentos){
	int retorno = -1;
	char arrayAuxiliar[len];

	if(mensaje != NULL && cadena != NULL && len > 0){

		do{
			printf("%s", mensaje);
			if (myGets(arrayAuxiliar, len) == 0){
				strcpy(cadena, arrayAuxiliar);
				retorno = 0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos > 0);

	}

	return retorno;
}


//------------------------------VALIDACIONES------------------------------


int validarEsInt(char * cadena){
	int retorno = 0;
	int i = 0;

	//Revisamos si el primer caracter indica que el numero es negativo.
	//En caso de que lo sea, seteamos a i en 1 para que comience a buscar
	//desde la siguiente posicion del array.
	if(cadena[0] == '-'){
		i = 1;
	}

	//Revisamos si hay caracteres no numericos.
	for(; cadena[i] != '\0'; i++){
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = -1;
			break;
		}
	}

	return retorno;
}

int validarEsFloat(char * cadena){
	int retorno = 0;
	int i = 0;

	//Revisamos si el primer caracter indica que el numero es negativo.
	//En caso de que lo sea, seteamos a i en 1 para que comience a buscar
	//desde la siguiente posicion del array.
	if(cadena[0] == '-'){
		i = 1;
	}

	//Revisamos si hay caracteres no numericos. Admite el punto '.'
	for(; cadena[i] != '\0'; i++){
		if(cadena[i] > '9' || cadena[i] < '.' || cadena[i] == '/'){
			retorno = -1;
			break;
		}
	}

	return retorno;
}

int myGets(char * cadena, int len){
	int retorno = -1;

	if(cadena != NULL && len > 0){
		fflush(stdin);
		if (fgets(cadena, len, stdin)){
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 0;
	}

	return retorno;
}

//------------------------------MENUS------------------------------

void mostrarMenuPrincipal(){
	printf("\n");
	printf("============================MENU PRINCIPAL=======================================/\n");
	printf("\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
	printf("10. Menu Informes\n");
	printf("11. Salir\n");
	printf("=================================================================================/\n");
}


void mostrarMenuInformes(){
	printf("\n");
	printf("============================MENU INFORMES=======================================/\n");
	printf("\n");
	printf("1. Pasajeros por clase.\n");
	printf("2. Filtrar pasajeros.\n");
	printf("3. Calcular millas acumuladas.\n");
	printf("4. Volver al menu anterior\n");
	printf("=================================================================================/\n");
}

void mostrarMenuModificaciones(){
	printf("\n");
	printf("============================MENU MODIFICACIONES==================================/\n");
	printf("\n");
	printf("MODIFICAR:\n");
	printf("1. Nombre\n");
	printf("2. Apellido\n");
	printf("3. Codigo de vuelo\n");
	printf("4. Tipo de pasajero\n");
	printf("5. Precio\n");
	printf("6. Volver al menu anterior\n");
	printf("=================================================================================/\n");
}

void mostrarMenuOrdenamientos(){
	printf("\n");
	printf("============================MENU ORDENAMIENTOS==================================/\n");
	printf("\n");
	printf("ORDENAR POR:\n");
	printf("1. ID\n");
	printf("2. Nombre\n");
	printf("3. Apellido\n");
	printf("4. Codigo de vuelo\n");
	printf("5. Tipo de pasajero\n");
	printf("6. Precio\n");
	printf("7. Volver al menu anterior\n");
	printf("=================================================================================/\n");
}
