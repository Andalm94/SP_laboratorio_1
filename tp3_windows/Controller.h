
//---------------------------------- LOAD ---------------------------------------------------------------------

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);


//---------------------------------- ALTA - MODIFICACION - BAJA-----------------------------------------------

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);

/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);


//------------------------------LISTAR / BUSCAR / ORDENAR-----------------------------------------------------
/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Recibe un ID por parametro y busca el index del pasajero
 *
 * \param int id
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: index del pasajero // Error o parametros invalidos: -1
 *
 */
int controller_BuscarPasajeroPorID(LinkedList* pArrayListPassenger, int id);

/** \brief Ordenar pasajeros. Ofrece ordenar segun cada campo de la estructura y en orden ascendente o descendente.
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

//------------------------------- MANEJO ID ------------------------------------------------------------------

/** \brief Establece un ID para el pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: ID del pasajero // Error o parametros invalidos: -1
 *
 */
int controller_generadorID(LinkedList* pArrayListPassenger);

/** \brief Busca el ultimo ID establecido
 *
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: ultimo ID establecido // Error o parametros invalidos: -1
 *
 */
int controller_buscarUltimoID(LinkedList* pArrayListPassenger);


//---------------------------------- SAVE -------------------------------------------------------------------

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);






