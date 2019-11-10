/*
 * utn.h
 *
 *  Created on: 8 nov. 2019
 *      Author: leoblanco15
 */

#ifndef UTN_H_
#define UTN_H_
int esNumericoFlotante(char str[]);
int esNumerico(char str[]);
int convertInt(char* str);
float convertFloat(char* str);
int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);
int swapEmployee(void* a, void* b);

#endif /* UTN_H_ */
