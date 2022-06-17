/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListPassenger LinkedList*
 * \return int. Exito: 0 // Error o parametros invalidos: -1
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);


