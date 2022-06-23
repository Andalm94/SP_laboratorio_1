#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "UTN.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(){
	setbuf(stdout, NULL);
    int option = 0;
    int flagArchivosCargados = 0;
    int flagArchivosGuardados = 0;


    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	mostrarMenuPrincipal();
    	getInt(&option, "\n", "La opcion no existe. Intente nuevamente.\n", 1, 10, 3);


        switch(option)
        {

        	case 1: //-------------------------------------------------------------> CARGAR DATOS DE ARCHIVO TEXTO
                if(flagArchivosCargados == 0){
                	//Mediante una flag, evitamos que se carguen varias veces los datos del archivo
                	//De este modo, evitamos que se multipliquen los datos.
                	if(controller_loadFromText("data.csv",listaPasajeros)==0){
                		printf("Datos cargados exitosamente.\n");
                		flagArchivosCargados = 1;
                	}
                    else{
                        printf("Ha habido un error en la carga de datos.\n");
                    }

                }
                else{
                	printf("Los datos ya han sido cargados\n");
                }



                break;



            case 2: //-------------------------------------------------------------> CARGAR DATOS DE ARCHIVO BINARIO
            	if(flagArchivosCargados == 0){
                	if(controller_loadFromBinary("data.bin", listaPasajeros)==0){
                    	printf("Datos cargados exitosamente.\n");
                    	flagArchivosCargados = 1;
                    }
                    else{
                    	printf("Ha habido un error en la carga de datos.\n");
                    }
            	}
            	else{
            		printf("Los datos ya han sido cargados\n");
            	}

            	break;




            case 3: //-------------------------------------------------------------> ALTA PASAJERO
            	if(flagArchivosCargados == 1 && controller_addPassenger(listaPasajeros) == 0){
                	printf("Pasajero cargado exitosamente.\n");
                }
                else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
                }
            	break;



            case 4: //-------------------------------------------------------------> MODIFICAR PASAJERO
            	if(flagArchivosCargados == 1 && controller_editPassenger(listaPasajeros)==0){
            		printf("\n");
            	}
            	else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
            	}
            	break;



            case 5: //-------------------------------------------------------------> BAJA PASAJERO
            	if(flagArchivosCargados == 1 && controller_removePassenger(listaPasajeros)==0){
            		printf("Pasajero eliminado exitosamente\n");
            	}
            	else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
            	}
            	break;



            case 6: //-------------------------------------------------------------> LISTAR PASAJEROS
            	if(flagArchivosCargados == 1 && controller_ListPassenger(listaPasajeros)==0){
            		printf("\nPasajeros listados exitosamente\n");
            	}
            	else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
            	}
            	break;



            case 7: //-------------------------------------------------------------> ORDENAR PASAJEROS
            	if(flagArchivosCargados == 1 && controller_sortPassenger(listaPasajeros)==0){
            		printf("\n");
            	}
            	else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
            	}
            	break;



            case 8: //-------------------------------------------------------------> GUARDAR DATOS EN ARCHIVO DE TEXTO
            	if(flagArchivosCargados == 1 && controller_saveAsText("data.csv" , listaPasajeros)==0){
            		printf("Informacion guardada exitosamente.\n");
            		flagArchivosGuardados = 1;
            	}
            	else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
            	}
            	break;



            case 9: //-------------------------------------------------------------> GUARDAR DATOS EN ARCHIVO BINARIO
            	if(flagArchivosCargados == 1 && controller_saveAsBinary("data.bin" , listaPasajeros)==0){
            		printf("Datos guardados exitosamente.\n");
            		flagArchivosGuardados = 1;
            	}
            	else{
                	if(flagArchivosCargados == 0){
                		printf("Realice primero la carga de archivos (opcion 1 o 2). \n");
                	}
                	else{
                    	printf("ERROR. Intente nuevamente\n");
                	}
            	}
            	break;



            case 10: //-------------------------------------------------------------> SALIR
            	if(flagArchivosGuardados == 1){
            		option = -1;
            	}
            	else{
            		printf("Guarde los cambios antes de salir (opcion 8 o 9). \n");
            	}
            	break;


        }
    }while(option != -1);
    return 0;
}

