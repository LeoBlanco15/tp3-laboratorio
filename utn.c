/*
 * utn.c
 *
 *  Created on: 8 nov. 2019
 *      Author: leoblanco15
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int esNumericoFlotante(char str[])
{
	int retorno= 0;
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {

       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           retorno=-1;
       i++;

   }
   return retorno;
}
int esNumerico(char str[])
{
   int i=0;
   int retorno= 0;
   while(str[i] != '\0')
   {
    	   if(!(str[i] >= '0' && str[i] <= '9'))
    	   {
    		   retorno= -1;
           	   break;
    	   }
    	   i++;
   }
   return retorno;
}
int convertInt(char* str)
{
	int num;
	int i;
	if(esNumerico(str)== 0)
	{
	   while(str[i] != '\0')
	   {
	    num = 10 * num + str[i];
	    i++;
	   }
	}
	return num;
}
float convertFloat(char* str)
{
	int num;
	int i;
	if(esNumericoFlotante(str))
	{
		while(str[i] != '\0')
		{
			num = 10 * num + str[i];
			i++;
		}
	}
	return num;
}
int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				__fpurge(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo);
					retorno = 0;
				 	break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;
}
int swapEmployee(void* arg1, void* arg2)
{
	int retorno=0;
	Employee* a = (Employee*)arg1;
	Employee* b = (Employee*)arg2;
	//Employee* aux;
	if(strcmp(a->nombre,b->nombre)>0)
			retorno=1;
	else
		retorno=-1;

	//return strcmp(a->nombre,b->nombre);
	return retorno;
}


